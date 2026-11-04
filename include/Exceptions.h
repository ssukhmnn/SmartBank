#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
using namespace std;

class BankException
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }
    string getMessage()
    {
        return message;
    }
};

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException() : BankException("Insufficient funds.") {}
};

class InvalidPINException : public BankException
{
public:
    InvalidPINException() : BankException("Invalid PIN.") {}
};

class AccountNotFoundException : public BankException
{
public:
    AccountNotFoundException() : BankException("Account not found.") {}
};

#endif