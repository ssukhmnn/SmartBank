#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
using namespace std;

class CurrentAccount : public Account
{
    double overdraftLimit;

public:
    CurrentAccount(string name, double openingBalance);
    void withdraw(double amount);
    double calculateInterest();
    string getType();
};

#endif