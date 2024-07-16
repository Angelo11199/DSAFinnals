
/**
 * @file main.cpp
 * @author group name here
 * @brief para san to
 * @version 0.5
 * @date 2024-07-16 when weas this created
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>

#include "./ADT/client.h"
#include "./ADT/office.h"
#include "./ADT/structData.h"
#include "./includes/fileHandling.h"
#include "./includes/utils.h"

using namespace std;

int main() {
    client clientList(-1);
    int clientId;
    char hasAccount;
    cout << "Welcome to Office Space Rental System\n";
    cout << "Do you have an account? (y/n): ";
    cin.get(hasAccount);
    hasAccount = static_cast<char>(toupper(hasAccount));
    if (hasAccount == 'Y') {
        clientId = (int)getDouble("Enter your Client ID: ");
        clientList = client(clientId);
    } else {
        clientData currentClient;
        currentClient.id = clientId = (int)getDouble("Enter new Client ID: ");
        currentClient.isAdmin = false;
        cout << currentClient.id << endl;
        cout << "Enter new Client Name: ";
        getline(cin, currentClient.clientName);
        cout << "Enter new Client Address: ";
        getline(cin, currentClient.clientAddress);
        clientList.addClient(currentClient, true);
        cout << "New client added and logged in successfully!\n";
        clientId = currentClient.id;
    }
    // switch (hasAccount) {
    //     case 'Y': {
    //         clientId = (int)getDouble("Enter your Client ID: ");
    //         clientList = client(clientId);
    //         break;
    //     }
    //     case 'N': {
    //         clientData currentClient;
    //         currentClient.id = clientId = (int)getDouble("Enter new Client ID: ");
    //         currentClient.isAdmin = false;
    //         cout << currentClient.id << endl;
    //         cout << "Enter new Client Name: ";
    //         getline(cin, currentClient.clientName);
    //         cout << "Enter new Client Address: ";
    //         getline(cin, currentClient.clientAddress);
    //         clientList.addClient(currentClient, true);
    //         cout << "New client added and logged in successfully!\n";
    //         clientId = currentClient.id;
    //         break;
    //     }
    // }
    // office officeList(clientId);
    bool isRunning = true;
    int choice;
    while (isRunning) {
        displayMenu();
        choice = (int)getDouble("Enter your choice: ");
        // convert to if else statements
        switch (choice) {
            //* working and tested.
            case 1: {
                officeInformation newOffice;
                cout << "Enter Office ID: ";
                cin >> newOffice.id;
                cin.ignore();
                cout << "Enter Office Name: ";
                getline(cin, newOffice.officeName);
                cout << "Enter Office Address: ";
                getline(cin, newOffice.officeAddress);
                cout << "Enter Office Price: ";
                cin >> newOffice.officePrice;
                cout << "Enter Office Size: ";
                cin >> newOffice.officeSize;
                newOffice.isRented = false;
                // officeList.addOffice(newOffice);
                cout << "New Office added successfully!\n";
                break;
            }
            //* not yet tested
            case 2: {
                int officeId;
                cout << "Enter Office ID to rent: ";
                cin >> officeId;

                // officeInformation office = officeList.getOffice(officeId);
                // if (office.id != 0 && !office.isRented) {
                //     office.isRented = true;
                //     // officeList.rentOffice(office, clientId);
                //     cout << "Office rented sucessfully!\n";
                // } else {
                //     cout << "Office is not available for rent.\n";
                // }
                break;
            }
            //* not yet tested
            case 3: {
                int officeId;
                cout << "Enter office ID to return: ";
                cin >> officeId;

                // officeInformation office = officeList.getOffice(officeId);
                // if (office.id != 0 && office.isRented) {
                //     office.isRented = false;
                //     // officeList.endRental(office);
                //     cout << "Office returned successfully!\n";
                // } else {
                //     cout << "Office not currently rented.\n";
                // }
                break;
            }
            //* not yet tested
            case 4: {
                int officeId;
                cout << "Enter Office ID to show details: ";
                cin >> officeId;

                // officeInformation officeData = officeList.getOffice(officeId);
                // if (officeData.id != 0) {
                //     cout << "Office ID: " << officeData.id << endl;
                //     cout << "Office Name: " << officeData.officeName << endl;
                //     cout << "Office Address: " << officeData.officeAddress << endl;
                //     cout << "Office Price: " << officeData.officePrice << endl;
                //     cout << "Office Size: " << officeData.officeSize << endl;
                //     cout << "Is Office Rented? " << (officeData.isRented ? "Yes" : "No") << endl;
                // } else {
                //     cout << "Office is not found.\n";
                // }
                break;
            }
            //* not yet tested. incomplete
            case 5: {
                cout << "Displaying all offices: \n";
                // officeList.print();
                break;
            }
            //* not yet tested
            case 7: {
                cout << "Enter Client ID to show details: ";
                cin >> clientId;
                clientData client = clientList.getClient(clientId);
                if (client.id != 0) {
                    cout << "Client ID: " << client.id << endl;
                    cout << "Client Name: " << client.clientName << endl;
                    cout << "Client Address: " << client.clientAddress << endl;
                } else {
                    cout << "Client not found.\n";
                }
                break;
            }
            case 8: {
                cout << "Exiting program...\n";
                isRunning = false;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}