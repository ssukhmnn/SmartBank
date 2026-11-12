# Smart Bank System

A console-based banking and ATM application in C++, built as an Object-Oriented Programming project.

**Team:** [Name 1], [Name 2]
**Course:** OOPs in C++ | **College:** [College name] | **Year:** 2026

## Features

- **Admin panel** (password protected): create, modify and delete accounts, view all accounts, unlock locked accounts
- **ATM for customers:** PIN login, check balance, deposit, withdraw, mini statement
- **Two account types:** Savings (minimum balance 500, 4% interest rate) and Current (overdraft limit 5000)
- **PIN lockout:** an account locks after 3 wrong PIN attempts, and only the admin can unlock it
- **Data saved in a file:** accounts, balances and PINs survive closing the program
- **Input validation:** wrong input (such as letters instead of numbers) does not crash the program

## OOP concepts used

| Concept | Where it is used |
|---|---|
| Classes and objects | `Account`, `Transaction`, `Bank`, `ATM`, `AdminPanel` |
| Inheritance | `SavingsAccount` and `CurrentAccount` inherit from `Account`; custom exceptions inherit from `BankException` |
| Abstract class | `Account` has pure virtual functions (`withdraw`, `calculateInterest`, `getType`) |
| Polymorphism | `Account*` pointers call the correct `withdraw()` for each account type |
| Operator overloading | `+=` for deposits and `<<` for printing an account |
| Exception handling | `BankException`, `InsufficientFundsException`, `InvalidPINException`, `AccountNotFoundException` |
| File handling | `Bank::saveToFile()` and `Bank::loadFromFile()` using `ofstream` and `ifstream` |
| Static members | `Account::nextAccNo` gives each account a unique number |
| Dynamic memory | Accounts are created with `new` and released with `delete` |

## Project structure

```
SmartBank/
├── include/   header files (.h)
├── src/       source files (.cpp)
├── data/      saved account data (accounts.txt is created automatically)
├── docs/      project web page (index.html)
├── main.cpp   program entry point and main menu
└── build.bat  build script for Windows
```

## How to build and run (Windows)

You need a C++ compiler (g++ from MinGW-w64 / MSYS2).

```
git clone https://github.com/ssukhmnn/SmartBank.git
cd SmartBank
.\build.bat
.\bank.exe
```

If `build.bat` does not work, compile manually:

```
g++ -Wall -Iinclude main.cpp src/Transaction.cpp src/Account.cpp src/SavingsAccount.cpp src/CurrentAccount.cpp src/Bank.cpp src/Input.cpp src/ATM.cpp src/AdminPanel.cpp -o bank
```

## How to use

1. Run the program and choose **2 (Admin)**. The admin password is `admin123`.
2. Choose **Create account**, enter the type, name, opening balance and a 4-digit PIN.
3. Go back and choose **1 (Customer)**, then log in with the account number and PIN.
4. After 3 wrong PINs the account locks. The admin can unlock it from the admin menu.

## Known limitations

- The PIN and admin password are stored as plain text (fine for a college project; a real bank would store hashes).
- The mini statement only shows transactions from the current run, because transaction history is not saved in the file.