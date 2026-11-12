#include <iostream>
#include "Bank.h"
#include "ATM.h"
#include "AdminPanel.h"
#include "Input.h"
using namespace std;

int main()
{
    Bank bank;
    bank.loadFromFile();
    ATM atm(&bank);
    AdminPanel admin(&bank);

    int choice = 0;
    while (choice != 3)
    {
        cout << "\n===== SMART BANK =====" << endl;
        cout << "1. Customer (ATM)" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Exit" << endl;
        choice = readInt("Choose: ");

        if (choice == 1)
        {
            atm.start();
        }
        else if (choice == 2)
        {
            admin.start();
        }
        else if (choice != 3)
        {
            cout << "Invalid choice." << endl;
        }
    }
    bank.saveToFile();
    cout << "Goodbye!" << endl;
    return 0;
}