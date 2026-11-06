#include <iostream>
#include "ATM.h"
#include "Input.h"
#include "Exceptions.h"
using namespace std;

ATM::ATM(Bank *b)
{
    bank = b;
}

void ATM::start()
{
    cout << "\n===== ATM =====" << endl;
    int no = readInt("Account number: ");
    int pin = readInt("PIN: ");

    Account *acc = 0;
    try
    {
        acc = bank->findAccount(no);
        acc->checkPin(pin);
    }
    catch (InvalidPINException e)
    {
        cout << e.getMessage() << " Attempts left: "
             << (3 - acc->getFailedAttempts()) << endl;
        bank->saveToFile(); // so the lockout survives a restart
        return;
    }
    catch (BankException e)
    {
        cout << "Error: " << e.getMessage() << endl;
        return;
    }
    session(acc);
}

void ATM::session(Account *acc)
{
    cout << "\nWelcome, " << acc->getName() << "!" << endl;
    int choice = 0;
    while (choice != 5)
    {
        cout << "\n1. Check balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Mini statement" << endl;
        cout << "5. Logout" << endl;
        choice = readInt("Choose: ");

        try
        {
            if (choice == 1)
            {
                cout << "Balance: " << acc->getBalance() << endl;
            }
            else if (choice == 2)
            {
                double amt = readDouble("Amount to deposit: ");
                acc->deposit(amt);
                bank->saveToFile(); // saved after every transaction
                cout << "Done. New balance: " << acc->getBalance() << endl;
            }
            else if (choice == 3)
            {
                double amt = readDouble("Amount to withdraw: ");
                acc->withdraw(amt);
                bank->saveToFile();
                cout << "Done. New balance: " << acc->getBalance() << endl;
            }
            else if (choice == 4)
            {
                acc->printStatement();
            }
            else if (choice != 5)
            {
                cout << "Invalid choice." << endl;
            }
        }
        catch (BankException e)
        {
            cout << "Error: " << e.getMessage() << endl;
        }
    }
    bank->saveToFile();
    cout << "Logged out. Thank you!" << endl;
}