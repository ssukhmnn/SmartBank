#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

class Account
{
protected:
    static int nextAccNo; // shared by all accounts, gives unique numbers
    int accNo;
    string holderName;
    double balance;
    Transaction history[100];
    int txnCount;

    void record(string type, double amount);

public:
    Account(string name, double openingBalance);
    virtual ~Account() {}

    void deposit(double amount);
    virtual void withdraw(double amount) = 0; // pure virtual: Account is abstract
    virtual double calculateInterest() = 0;
    virtual string getType() = 0;

    int getAccNo() { return accNo; }
    double getBalance() { return balance; }
    string getName() { return holderName; }
    void printStatement();
    void setName(string newName) { holderName = newName; }
    void restore(int no, double bal)
    {
        accNo = no;
        balance = bal;
    }
    static void setNextAccNo(int n) { nextAccNo = n; }

    void operator+=(double amount); // operator overloading
    friend ostream &operator<<(ostream &os, Account &acc);
};

#endif