#include "SavingsAccount.h"
#include "Exceptions.h"
using namespace std;

SavingsAccount::SavingsAccount(string name, double openingBalance)
    : Account(name, openingBalance)
{
    minBalance = 500;
    interestRate = 0.04; // 4% per year
    if (openingBalance < minBalance)
    {
        throw BankException("Savings account needs at least 500 to open.");
    }
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw BankException("Withdrawal must be positive.");
    }
    if (balance - amount < minBalance)
    {
        throw InsufficientFundsException();
    }
    balance = balance - amount;
    record("Withdraw", amount);
}

double SavingsAccount::calculateInterest()
{
    return balance * interestRate;
}

string SavingsAccount::getType()
{
    return "Savings";
}