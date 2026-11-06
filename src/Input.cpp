#include <iostream>
#include "Input.h"
using namespace std;

int readInt(string prompt)
{
    int x;
    cout << prompt;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. " << prompt;
    }
    cin.ignore(1000, '\n');
    return x;
}

double readDouble(string prompt)
{
    double x;
    cout << prompt;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. " << prompt;
    }
    cin.ignore(1000, '\n');
    return x;
}

string readLine(string prompt)
{
    string s;
    cout << prompt;
    getline(cin, s);
    while (s == "")
    {
        cout << "Cannot be empty. " << prompt;
        getline(cin, s);
    }
    return s;
}