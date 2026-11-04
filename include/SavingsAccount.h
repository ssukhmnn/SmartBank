#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
using namespace std;

class SavingsAccount : public Account
{
    double minBalance;
    double interestRate;

public:
    SavingsAccount(string name, double openingBalance);
    void withdraw(double amount);
    double calculateInterest();
    string getType();
};

#endif