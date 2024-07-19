
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

#include "./ADT/clientRent.h"
#include "./ADT/office.h"
#include "./ADT/structData.h"
#include "./includes/fileHandling.h"
#include "./includes/utils.h"
using namespace std;

int main() {
    clientRent clientList = clientRent(-1);
    int clientId = -1;
    char hasAccount;
    while (hasAccount != 'Y' && hasAccount != 'N') {
        cout << "Welcome to Office Space Rental System\n";
        cout << "Do you have an account? (y/n): ";
        cin.get(hasAccount);
        hasAccount = static_cast<char>(toupper(hasAccount));
        switch (hasAccount) {
            case 'Y': {
                clientId = (int)getDouble("Enter your Client ID: ");
                clientList = clientRent(clientId);
                break;
            }
            case 'N': {
                clientData currentClient;
                currentClient.isAdmin = false;
                cin.ignore();
                cout << "Enter new Client Name: ";
                getline(cin, currentClient.clientName);
                cout << "Enter new Client Address: ";
                getline(cin, currentClient.clientAddress);
                clientId = clientList.addClient(currentClient, true);
                clientList = clientRent(clientId);
                cout << "New client added and logged in successfully!\n";
                break;
            }
        }
    }
    office officeList(clientId);
    bool isRunning = true;
    int choice;
    while (isRunning) {
        clear();
        displayMenu();
        choice = (int)getDouble("Enter your choice: ");
        switch (choice) {
            case 1: {
                cout << "-------------------------------------------------------------------------" << endl
                     << endl;
                bool adminPassed = password() == 1;
                if (!adminPassed) {
                    cout << "Password Incorrect! \n";
                    break;
                }
                cout << endl
                     << "-------------------------------------------------------------------------" << endl;
                officeInformation newOffice;
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
                officeList.addOffice(newOffice);
                cout << "New Office added successfully!\n";
                break;
            }
            case 2: {
                cout << "-------------------------------------------------------------------------" << endl;
                int officeId;
                cout << "Enter Office ID to rent: ";
                cin >> officeId;
                officeInformation office = officeList.getOffice(officeId);
                if (office.id == 0) {
                    cout << "Office not found.\n";
                    break;
                }
                if (!office.isRented) {
                    officeList.rentOffice(office, clientId);
                    clientList.rentOffice(office.id);
                    cout << "Office rented sucessfully!\n";
                } else {
                    cout << "Office is not available for rent.\n";
                }
                break;
            }
            case 3: {
                cout << "-------------------------------------------------------------------------" << endl;
                int officeId;
                cout << "Enter office ID to return: ";
                cin >> officeId;
                cout << "-------------------------------------------------------------------------" << endl;
                officeInformation office = officeList.getOffice(officeId);
                cout << office.id << endl;
                cout << office.isRented << endl;
                if (office.id != 0 && office.isRented) {
                    office.isRented = false;
                    officeList.endRental(office);
                    clientList.endRental(office.id);
                    office.isRented = false;
                    cout << "Office returned successfully!\n\n";
                } else {
                    cout << "Office not currently rented.\n\n";
                }
                break;
            }
            case 4: {
                cout << "-------------------------------------------------------------------------" << endl;
                int officeId;
                cout << "Enter Office ID to show details: ";
                cin >> officeId;

                cout << "-------------------------------------------------------------------------" << endl;
                officeInformation officeData = officeList.getOffice(officeId);
                if (officeData.id != 0) {
                    cout << "Office ID: " << officeData.id << endl;
                    cout << "Office Name: " << officeData.officeName << endl;
                    cout << "Office Address: " << officeData.officeAddress << endl;
                    cout << "Office Price: " << officeData.officePrice << endl;
                    cout << "Office Size: " << officeData.officeSize << endl;
                    cout << "Is Office Rented? " << (officeData.isRented ? "Yes" : "No") << endl;
                } else {
                    cout << "Office is not found.\n";
                }
                break;
            }
            case 5: {
                cout << "-------------------------------------------------------------------------" << endl;
                cout << "Displaying all offices: \n";
                officeList.printOffices();
                break;
            }
            case 6: {
                cout << "-------------------------------------------------------------------------" << endl;
                int officeId;
                cout << "Enter Office ID to show availability: ";
                cin >> officeId;

                cout << "-------------------------------------------------------------------------" << endl;
                officeInformation officeData = officeList.getOffice(officeId);
                if (officeData.id != 0) {
                    cout << "Office ID: " << officeData.id << endl;
                    cout << "Office Name: " << officeData.officeName << endl;
                    cout << "Office Address: " << officeData.officeAddress << endl;
                    cout << "Office Price: " << officeData.officePrice << endl;
                    cout << "Office Size: " << officeData.officeSize << endl;
                    cout << "Availability: ";
                    if (officeData.isRented) {
                        cout << "Already Rented\n";
                    } else {
                        cout << "Available\n";
                    }
                } else {
                    cout << "Office not found.\n";
                }
                break;
            }
            case 7: {
                cout << "-------------------------------------------------------------------------" << endl;
                cout << "Here are the office you have rented: \n";
                clientList.showRentedOffices();
                break;
            }
            //* not yet tested
            case 8: {
                cout << "-------------------------------------------------------------------------" << endl
                     << endl;
                bool adminPassed = password() == 1;
                if (!adminPassed) {
                    cout << "Password Incorrect! \n";
                    break;
                }
                displayMenu2();
                int choice2 = 0;
                choice2 = (int)getDouble("Enter your choice: ");
                switch (choice2) {
                    case 1: {
                        cout << "-------------------------------------------------------------------------" << endl;
                        clientData currentClient;
                        cout << "-------------------------------------------------------------------------" << endl;
                        currentClient.isAdmin = false;
                        cout << currentClient.id << endl;
                        cout << "Enter new Client Name: ";
                        getline(cin, currentClient.clientName);
                        cout << "Enter new Client Address: ";
                        getline(cin, currentClient.clientAddress);
                        clientList.addClient(currentClient, true);
                        cout << "New client added!\n";
                        break;
                    }
                    case 2: {
                        int clientIdSearch;
                        cout << "-------------------------------------------------------------------------" << endl;
                        cout << "Enter Client ID to show details: ";
                        cin >> clientIdSearch;
                        cout << "-------------------------------------------------------------------------" << endl;
                        clientData client = clientList.getClient(clientIdSearch);
                        if (client.id != -1) {
                            cout << "Client ID: " << client.id << endl;
                            cout << "Client Name: " << client.clientName << endl;
                            cout << "Client Address: " << client.clientAddress << endl;
                        } else {
                            cout << "Client not found. Going back.\n";
                        }
                        break;
                    }
                    case 3: {
                        int clientIdSearch;
                        cout
                            << "-------------------------------------------------------------------------" << endl;
                        cout << "Enter Client ID to show rented offices: ";
                        cin >> clientIdSearch;
                        cout << "-------------------------------------------------------------------------" << endl;
                        clientData client = clientList.getClient(clientIdSearch);
                        clientList = clientRent(clientIdSearch);
                        if (client.id != 0) {
                            cout << "Client ID: " << client.id << endl;
                            cout << "Client Name: " << client.clientName << endl;
                            cout << "Client Address: " << client.clientAddress << endl;
                            cout << "Rented Offices: \n";
                            clientList.showRentedOffices(clientId);
                            clientList = clientRent(clientId);
                        } else {
                            cout << "Client not found. Going back.\n";
                        }
                        break;
                    }
                    case 4:
                    default:
                        cout << "-------------------------------------------------------------------------" << endl;
                        cout << "Going back.\n";
                }
                break;
            }
            case 9: {
                cout << "-------------------------------------------------------------------------" << endl;
                cout << "Exiting program...\n";
                isRunning = false;
                break;
            }
            default: {
                cout << "-------------------------------------------------------------------------" << endl;
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
    return 0;
}