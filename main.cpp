#include <iostream>
#include "Bank.h"
#include "Exceptions.h"
using namespace std;

int main()
{
    Bank bank;
    bank.loadFromFile();

    try
    {
        int a = bank.createAccount(1, "Amit Kumar", 2000);
        int b = bank.createAccount(2, "Neha Singh", 1000);
        bank.transfer(a, b, 700);  // works
        bank.transfer(a, b, 5000); // fails: would go below the minimum
    }
    catch (BankException e)
    {
        cout << "Error: " << e.getMessage() << endl;
    }

    bank.displayAll();
    bank.saveToFile();
    return 0;
}