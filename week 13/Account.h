// A sample interface file for Account class.
#ifndef ACCOUNT_H
#define ACCOUNT_H 

#include <string>
using namespace std;

class Account
{
public:
    bool setAccount(string newName, int newNumber, int newType, double newBalance);
    bool deposit(double amount);
    bool withdrawal(double amount);
    void displayAccountInfo( );
    bool closeAccount(int newNumber);


int getNumber();
    bool createAccount(string newName, int newNumber, int newType, double newBalance);

private:

    string name;     // account holder's name
    int number;      // account number
    int type;        // account type: 1 - checking, 2 - saving
    double balance;  // current balance of the account
};

#endif    // end of ACCOUNT_H

