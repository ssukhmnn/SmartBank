#include <iostream>
#include <ctime>
#include "Transaction.h"
using namespace std;

Transaction::Transaction()
{
    type = "";
    amount = 0;
    balanceAfter = 0;
    timestamp = "";
}

Transaction::Transaction(string t, double a, double b)
{
    type = t;
    amount = a;
    balanceAfter = b;

    time_t now = time(0);
    timestamp = ctime(&now);
    timestamp.erase(timestamp.length() - 1);
}

void Transaction::display()
{
    cout << timestamp << " | " << type << " | " << amount
         << " | Balance: " << balanceAfter << endl;
}