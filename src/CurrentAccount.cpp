#include "CurrentAccount.h"
#include "Exceptions.h"
using namespace std;

CurrentAccount::CurrentAccount(string name, double openingBalance)
    : Account(name, openingBalance)
{
    overdraftLimit = 5000;
}

void CurrentAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw BankException("Withdrawal must be positive.");
    }
    if (balance - amount < -overdraftLimit)
    {
        throw InsufficientFundsException();
    }
    balance = balance - amount;
    record("Withdraw", amount);
}

double CurrentAccount::calculateInterest()
{
    return 0; // current accounts earn no interest
}

string CurrentAccount::getType()
{
    return "Current";
}