#include <iostream>
#include <vector>
#include <string>
#include "ATM_Header.h"

using namespace std;

// Main entry point of the ATM system
// This function initializes the ATM system and handles user interactions
int main()
{
    // Initialize a vector to store card details (default card is preloaded)
    vector<Details> details = { Details() };
    int choice;

    // Display the welcome message to the user
    WelcomeMessage();

    // Prompt the user to start the program or exit
    cout << ""  << endl << ":";
    cin >> choice;
    system("cls");

    // If the user chooses to start the program
    if (choice == 1)
    {
        int pick;
        int insertCard;

        // Prompt the user to insert their card
        cout << "Please insert the card by pressing number (1)" << endl << ":";
        cin >> insertCard;
        if (insertCard == 1)
        {
            int count = 1;
            int pin;
            cout << "The card has been entered successfully." << endl;
            cout << endl;

            // Allow the user three attempts to enter the correct PIN
            while (count <= 3)
            {
                cout << "Enter the password: " << endl << ":";
                cin >> pin;

                if (pin == details[0].Pin)
                {
                    cout << "Successful operation." << endl;
                    break;
                }
                else
                {
                    if (count == 3)
                    {
                        // Block the card after three incorrect attempts
                        cout << "You have entered the wrong password 3 times. The card has been blocked. Program will exit." << endl;
                        return 0;
                    }
                    count++;
                    cout << "#" << count << " PIN code error try again." << endl;
                }
            }
        }
        else
        {
            // Handle case where the card is not inserted correctly
            cout << "Card declined." << endl;
            return 0;
        }

        // Define the list of available operations
        vector<string> List
        {
            "[1] View balance",
            "[2] Withdraw",
            "[3] Deposit",
            "[4] Account Data"
        };

        system("cls");
        char again;
        do {
            // Display the list of operations to the user
            list(List);
            cout << "Choose from the available options" << endl;
            cin >> pick;

            // Handle the user's choice
            if (pick == 1)
            {
                // Display the current balance
                cout << "Balance: " << details.at(0).balance << " L.E." << endl;
            }
            else if (pick == 2)
            {
                // Handle withdrawal operation
                cout << "Withdraw: " << endl;
                double withdraw;
                cout << "Enter the amount" << endl;
                cout << ":";
                cin >> withdraw;

                Withdraw(details, withdraw);
            }
            else if (pick == 3)
            {
                // Handle deposit operation
                cout << "Deposit:- " << endl;
                double deposit;
                cout << "Enter the amount" << endl;
                cout << ":";
                cin >> deposit;
                Deposit(details, deposit);
            }
            else if (pick == 4)
            {
                // Display account data
                cout << "Account Data:- " << endl;
                accountData(details);
            }
            else
            {
                // Handle invalid choices
                cout << "Invalid choice. Please try again." << endl;
            }

            system("cls");
            // Ask the user if they want to perform another operation
            cout << "\nDo you want to do another operation?" << endl;
            cout << "(y/n) : ";
            cin >> again;

        } while (again == 'y' || again == 'Y');
    }
    else if (choice == 0)
    {
        // Exit the program if the user chooses 0
        return 0;
    }

    // Display a farewell message before exiting the program
    cout << "\nThank you for using our ATM system. Have a great day!" << endl;

    return 0;
}