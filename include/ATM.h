#ifndef ATM_H
#define ATM_H

#include "Bank.h"
using namespace std;

class ATM
{
    Bank *bank;
    void session(Account *acc);

public:
    ATM(Bank *b);
    void start();
};

#endif