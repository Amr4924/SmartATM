<!-- ATM System Logo -->
<p align="center">
  <img src="https://raw.githubusercontent.com/amrsa3dwy/atm-logo/main/atm_logo.png" alt="ATM System Logo" width="180" />
</p>

# ATM System

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Technical Details](#technical-details)
- [Example Scenarios](#example-scenarios)
- [Limitations & Future Work](#limitations--future-work)
- [Author](#author)
- [License](#license)

---

## Introduction

The ATM System is a C++ console application that simulates the basic operations of an Automated Teller Machine. It is designed for educational purposes, demonstrating core programming concepts such as data structures, user input validation, error handling, and modular code organization.

This project is ideal for students and beginners who want to understand how ATM logic works and how to structure a C++ application with multiple source files.

---

## Features

- **Welcome Message:** Professional greeting and instructions for users.
- **Card Insertion Simulation:** User is prompted to insert a card to begin.
- **PIN Verification:** Secure login with up to three attempts before blocking the card.
- **Balance Inquiry:** View current account balance.
- **Cash Withdrawal:** Withdraw funds with daily limits and error handling for insufficient balance.
- **Deposit Funds:** Deposit money with daily limits and negative balance management.
- **Account Data Display:** View detailed account information including name, account number, type, and balances.
- **Operation Menu:** Easy-to-use menu for selecting operations.
- **Error Handling:** Clear messages for invalid input, exceeded limits, and blocked cards.
- **Farewell Message:** Professional goodbye message upon exit.
- **Modular Code:** Separation of logic into header and source files for maintainability.

---

## Getting Started

### Prerequisites

- C++11 or later
- Windows OS (for `system("cls")` compatibility)
- C++ compiler (e.g., g++, Visual Studio)

### Installation

1. Clone or download the repository to your local machine.
2. Open the project folder in your preferred IDE or editor.

### Compilation

Use the following command to compile the project (example for g++):
```sh
g++ ATM.cpp ATM_Opearations.cpp -o ATM.exe
```

---

## Usage

1. Run the compiled executable.
2. Follow the on-screen instructions:
   - Insert your card by pressing `1`.
   - Enter your PIN code (default: `0000`).
   - Choose an operation from the menu.
   - Follow prompts for each operation.
   - Exit by pressing `0` at the start or choosing not to continue after an operation.

---

## Code Structure

- `ATM.cpp`  
  Main program file. Handles user interaction, menu navigation, and program flow.

- `ATM_Opearations.cpp`  
  Implements ATM operations such as withdrawal, deposit, account data display, and welcome message.

- `ATM_Header.h`  
  Contains the `Details` struct and function declarations for ATM operations.

- `README.md`  
  Project documentation.

---

## Technical Details

### Data Structure

```cpp
struct Details {
    std::string name;
    std::string Account;
    std::string accountType;
    double balance;
    double negativeBalance;
    double dailyWithdrawn;
    double dailyDeposit;
    int Pin;
};
```

### Functions

- `WelcomeMessage()`  
  Displays a formatted welcome message and instructions.

- `accountData(std::vector<Details> details)`  
  Prints account information.

- `list(std::vector<std::string> list)`  
  Displays the menu options.

- `Withdraw(std::vector<Details>& details, double withdraw)`  
  Handles withdrawal logic and checks limits.

- `Deposit(std::vector<Details>& details, double deposit)`  
  Handles deposit logic and negative balance management.

---

## Example Scenarios

### Scenario 1: Successful Login and Balance Inquiry

1. Start the program.
2. Insert card (`1`).
3. Enter correct PIN (`0000`).
4. Choose `[1] View balance`.
5. See your current balance.

### Scenario 2: Exceeding Withdrawal Limit

1. Start the program.
2. Insert card (`1`).
3. Enter correct PIN.
4. Choose `[2] Withdraw`.
5. Enter an amount greater than daily limit (`5000`).
6. Receive error message.

### Scenario 3: Card Blocked After Wrong PIN

1. Start the program.
2. Insert card (`1`).
3. Enter wrong PIN three times.
4. Card is blocked and program exits.

---

## Limitations & Future Work

- Only one card/account is supported (can be extended for multiple users).
- Data is not persisted; all changes are lost after program exit.
- No graphical user interface.
- Security features (e.g., PIN masking) are basic.
- Platform-dependent screen clearing (`system("cls")`).

### Possible Improvements

- Add file I/O for persistent data storage.
- Support multiple cards/accounts.
- Implement PIN masking for better security.
- Add transaction history.
- Create a GUI version.

---

## Author

- Amr Saad Rajab Ahmed
- [LinkedIn Profile](https://www.linkedin.com/in/amrsa3dwy)

---

## License

This project is for educational purposes and is provided as-is without any warranty.

---

If you have any questions or suggestions, feel free to contact the author or contribute to the project!
