#include <iostream>
#include "AdminPanel.h"
#include "Input.h"
#include "Exceptions.h"
using namespace std;

AdminPanel::AdminPanel(Bank *b)
{
    bank = b;
    password = "admin123";
}

void AdminPanel::start()
{
    cout << "\n===== ADMIN =====" << endl;
    string entered = readLine("Admin password: ");
    if (entered != password)
    {
        cout << "Wrong password." << endl;
        return;
    }

    int choice = 0;
    while (choice != 6)
    {
        cout << "\n1. Create account" << endl;
        cout << "2. Modify account name" << endl;
        cout << "3. Delete account" << endl;
        cout << "4. View all accounts" << endl;
        cout << "5. Unlock account" << endl;
        cout << "6. Back" << endl;
        choice = readInt("Choose: ");

        try
        {
            if (choice == 1)
            {
                int type = readInt("Type (1 = Savings, 2 = Current): ");
                string name = readLine("Holder name: ");
                double opening = readDouble("Opening balance: ");
                int pin = readInt("Set 4-digit PIN: ");
                int no = bank->createAccount(type, name, opening, pin);
                bank->saveToFile();
                cout << "Account created. Number: " << no << endl;
            }
            else if (choice == 2)
            {
                int no = readInt("Account number: ");
                string name = readLine("New name: ");
                bank->modifyName(no, name);
                bank->saveToFile();
                cout << "Name updated." << endl;
            }
            else if (choice == 3)
            {
                int no = readInt("Account number to delete: ");
                bank->deleteAccount(no);
                bank->saveToFile();
                cout << "Account deleted." << endl;
            }
            else if (choice == 4)
            {
                bank->displayAll();
            }
            else if (choice == 5)
            {
                int no = readInt("Account number to unlock: ");
                bank->findAccount(no)->unlock();
                bank->saveToFile();
                cout << "Account unlocked." << endl;
            }
            else if (choice != 6)
            {
                cout << "Invalid choice." << endl;
            }
        }
        catch (BankException e)
        {
            cout << "Error: " << e.getMessage() << endl;
        }
    }
}