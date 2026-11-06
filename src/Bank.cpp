#include <iostream>
#include <fstream>
#include <iomanip>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Exceptions.h"
using namespace std;

Bank::Bank()
{
    count = 0;
}

Bank::~Bank()
{
    for (int i = 0; i < count; i++)
    {
        delete accounts[i];
    }
}

int Bank::createAccount(int type, string name, double openingBalance)
{
    if (count == 100)
    {
        throw BankException("Bank is full.");
    }
    Account *acc;
    if (type == 1)
    {
        acc = new SavingsAccount(name, openingBalance);
    }
    else if (type == 2)
    {
        acc = new CurrentAccount(name, openingBalance);
    }
    else
    {
        throw BankException("Invalid account type.");
    }
    accounts[count] = acc;
    count++;
    return acc->getAccNo();
}

Account *Bank::findAccount(int accNo)
{
    for (int i = 0; i < count; i++)
    {
        if (accounts[i]->getAccNo() == accNo)
        {
            return accounts[i];
        }
    }
    throw AccountNotFoundException();
}

void Bank::deleteAccount(int accNo)
{
    for (int i = 0; i < count; i++)
    {
        if (accounts[i]->getAccNo() == accNo)
        {
            delete accounts[i];
            for (int j = i; j < count - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            count--;
            return;
        }
    }
    throw AccountNotFoundException();
}

void Bank::modifyName(int accNo, string newName)
{
    Account *acc = findAccount(accNo);
    acc->setName(newName);
}

void Bank::transfer(int fromNo, int toNo, double amount)
{
    if (fromNo == toNo)
    {
        throw BankException("Cannot transfer to the same account.");
    }
    Account *from = findAccount(fromNo);
    Account *to = findAccount(toNo);
    from->withdraw(amount);
    to->deposit(amount);
}

void Bank::displayAll()
{
    if (count == 0)
    {
        cout << "No accounts yet." << endl;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << *accounts[i] << endl;
    }
}

void Bank::saveToFile()
{
    ofstream out("data/accounts.txt");
    if (!out)
    {
        throw BankException("Could not open file for saving.");
    }
    out << fixed << setprecision(2);
    for (int i = 0; i < count; i++)
    {
        out << accounts[i]->getType() << " "
            << accounts[i]->getAccNo() << " "
            << accounts[i]->getBalance() << " "
            << accounts[i]->getName() << endl;
    }
    out.close();
}

void Bank::loadFromFile()
{
    ifstream in("data/accounts.txt");
    if (!in)
    {
        return; // no file yet: first run
    }
    string type, name;
    int no;
    double bal;
    int maxNo = 1000;

    while (count < 100 && in >> type >> no >> bal)
    {
        getline(in, name);
        name.erase(0, 1); // remove the space before the name

        Account *acc;
        if (type == "Savings")
        {
            acc = new SavingsAccount(name, 500); // 500 is just a placeholder
        }
        else
        {
            acc = new CurrentAccount(name, 0);
        }
        acc->restore(no, bal); // put back the real number and balance

        accounts[count] = acc;
        count++;
        if (no > maxNo)
        {
            maxNo = no;
        }
    }
    Account::setNextAccNo(maxNo + 1); // so new accounts continue the numbering
    in.close();
}