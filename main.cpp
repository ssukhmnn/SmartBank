#include <iostream>
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Exceptions.h"
using namespace std;

int main()
{
    Account *accounts[2];
    accounts[0] = new SavingsAccount("Amit", 2000);
    accounts[1] = new CurrentAccount("Neha", 1000);

    for (int i = 0; i < 2; i++)
    {
        try
        {
            *accounts[i] += 500;         // operator overloading
            accounts[i]->withdraw(2500); // polymorphism: each type has its own rule
        }
        catch (BankException e)
        {
            cout << "Error for " << accounts[i]->getName()
                 << ": " << e.getMessage() << endl;
        }
        cout << *accounts[i] << endl; // operator overloading
        accounts[i]->printStatement();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete accounts[i];
    }
    return 0;
}