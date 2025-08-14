#ifndef ATM_H
#define ATM_H

#include <vector>
#include <string>

// Structure to store card details
// Includes fields for name, account number, account type, balance, and more
struct Details
{
    std::string name = "Amr Saad Rajab Ahmed";
    std::string Account = "720602800";
    std::string accountType = "Current account";
    double balance = 8700;
    double negativeBalance = 2500;
    double dailyWithdrawn = 0;
    double dailyDeposit = 0;
    int Pin = 0000;
};

// Function declarations for ATM operations
// These functions are implemented in ATM_Opearations.cpp
void accountData(std::vector<Details> details);
void list(std::vector<std::string> list);
void Withdraw(std::vector<Details> &details, double withdraw);
void Deposit(std::vector<Details>& details, double deposit);
void WelcomeMessage();

#endif