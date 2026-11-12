#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <string>
#include "Bank.h"
using namespace std;

class AdminPanel
{
    Bank *bank;
    string password;

public:
    AdminPanel(Bank *b);
    void start();
};

#endif