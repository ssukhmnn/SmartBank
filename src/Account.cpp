#include "Account.h"
#include "Exceptions.h"
using namespace std;

int Account::nextAccNo = 1001;

Account::Account(string name, double openingBalance)
{
    if (openingBalance < 0)
    {
        throw BankException("Opening balance cannot be negative.");
    }
    accNo = nextAccNo;
    nextAccNo++;
    holderName = name;
    balance = openingBalance;
    txnCount = 0;
    pin = 0;
    failedAttempts = 0;
}

void Account::record(string type, double amount)
{
    if (txnCount == 100)
    { // history full: drop the oldest one
        for (int i = 1; i < 100; i++)
        {
            history[i - 1] = history[i];
        }
        txnCount = 99;
    }
    history[txnCount] = Transaction(type, amount, balance);
    txnCount++;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        throw BankException("Deposit must be positive.");
    }
    balance = balance + amount;
    record("Deposit", amount);
}

void Account::operator+=(double amount)
{
    deposit(amount);
}

void Account::printStatement()
{
    cout << "--- Statement for account " << accNo << " ---" << endl;
    for (int i = 0; i < txnCount; i++)
    {
        history[i].display();
    }
}

ostream &operator<<(ostream &os, Account &acc)
{
    os << "[" << acc.accNo << "] " << acc.holderName
       << " (" << acc.getType() << ") Balance: " << acc.balance;
    return os;
}
void Account::setPin(int p)
{
    if (p < 1000 || p > 9999)
    {
        throw BankException("PIN must be exactly 4 digits.");
    }
    pin = p;
}

void Account::checkPin(int p)
{
    if (failedAttempts >= 3)
    {
        throw BankException("Account is locked. Contact the admin.");
    }
    if (p != pin)
    {
        failedAttempts++;
        throw InvalidPINException();
    }
    failedAttempts = 0; // correct PIN resets the counter
}