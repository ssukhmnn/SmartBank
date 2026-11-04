#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction
{
    string type;
    double amount;
    double balanceAfter;
    string timestamp;

public:
    Transaction();
    Transaction(string type, double amount, double balanceAfter);
    void display();
};

#endif