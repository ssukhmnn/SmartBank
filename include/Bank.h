#ifndef BANK_H
#define BANK_H

#include <string>
#include "Account.h"
using namespace std;

class Bank
{
    Account *accounts[100];
    int count;

public:
    Bank();
    ~Bank();

    int createAccount(int type, string name, double openingBalance, int pin);
    Account *findAccount(int accNo);
    void deleteAccount(int accNo);
    void modifyName(int accNo, string newName);
    void transfer(int fromNo, int toNo, double amount);
    void displayAll();

    void saveToFile();
    void loadFromFile();
};

#endif