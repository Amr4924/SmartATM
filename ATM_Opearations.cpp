#include <iostream>
#include <vector>
#include <string>
#include "ATM_Header.h"

using namespace std;

// Display a welcome message to the user
// This function provides an introduction to the ATM system and its features
void WelcomeMessage()
{
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|            ______                ______                   |" << endl;
    cout << "|         ______ Welcome to ATM System ______               |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|                                                           |" << endl;
    cout << "|  This ATM system is designed to provide a user-friendly   |" << endl;
    cout << "|  interface for managing your banking transactions.        |" << endl;
    cout << "|  You can perform operations such as viewing your balance, |" << endl;
    cout << "|  withdrawing cash, and depositing funds.                  |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|  Start progtam:                                           |" << endl;
    cout << "|  1. Insert your card                                      |" << endl;
    cout << "|  2. Enter your PIN code                                   |" << endl;
    cout << "|  3. Choose an operation from the menu                     |" << endl;
    cout << "|  4. Follow the prompts for each operation                 |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|  --> To start the program (1)                             |" << endl;
    cout << "|  --> Exit (0)                                             |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|___________________________________________________________|" << endl;
}

// Display account details for the user
// Iterates through the vector of details and prints account information
void accountData(vector<Details> details)
{
    for (int i = 0; i < details.size(); ++i)
    {
        cout << "--------------------------------" << endl;
        cout << "Name: " << details.at(i).name << endl;
        cout  << endl;
        cout << "Account number: " << details.at(i).Account << endl;
        cout << endl;
        cout << "AccountType: " << details.at(i).accountType << endl;
        cout << endl;
    cout << "Balance: " << details.at(i).balance << " L.E." << endl;
        cout << endl;
        cout << "NegativeBalance: " << details.at(i).negativeBalance << "L.E." << endl;
        cout << "--------------------------------" << endl;
            
    }
}

// Display a list of available operations
// Iterates through the vector of strings and prints each operation
void list(vector<string> list)
{
    for (string& v : list)
    {
        cout << v << endl;
    }

}

// Handle withdrawal operation
// Checks balance and daily withdrawal limits before processing the transaction
void Withdraw(vector<Details> &details,double withdraw)
{
    double MaximumWl = 5000;
    if (details.at(0).balance <= 0 || withdraw > details.at(0).balance)
    {
        cout << "There is not enough balance in your account." << endl;
    }
    else if ((details.at(0).dailyWithdrawn + withdraw) > MaximumWl || withdraw > MaximumWl)
    {
        cout << "You have exceeded your daily withdrawal limit." << endl;
    }
    else 
    {
        details.at(0).balance -= withdraw;
        details.at(0).dailyWithdrawn += withdraw;
        cout << "Successful withdrawal." << endl;
    }
}

// Handle deposit operation
// Checks deposit limits and adjusts balance or negative balance accordingly
void Deposit(vector<Details>& details, double deposit)
{
    double result;
    double MaximumDL = 20000;
    if (deposit <= 0)
    {
        cout << "Deposit amount must be positive." << endl;
    }
    else if (deposit > MaximumDL || details.at(0).dailyDeposit + deposit > MaximumDL)
    {
        cout << "You have exceeded the daily deposit limit." << endl;
    }
    else if (details.at(0).negativeBalance == 0)
    {
        details.at(0).balance += deposit;
        details.at(0).dailyDeposit += deposit;
        cout << "Successful deposit" << endl;
    }
    else if (details.at(0).negativeBalance != 0 || details.at(0).negativeBalance < 0)
    {
        result = deposit - details.at(0).negativeBalance;
        details.at(0).negativeBalance = 0;
        if (result < 0)
        {
            result *= -1;
            details.at(0).balance += result;
        }
        else
        {
            details.at(0).balance += result; 
        }
        details.at(0).dailyDeposit += deposit;
        cout << "Successful deposit" << endl;
    }
}