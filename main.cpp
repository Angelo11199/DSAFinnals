
#include <iostream>
#include <string>

#include "./ADT/client.h"
#include "./ADT/office.h"
#include "./ADT/structData.h"
#include "./includes/fileHandling.h"

using namespace std;

void displayMenu() {
    cout << "Office Space Rental System\n";
    cout << "[1] Add New Office\n";
    cout << "[2] Rent an Office\n";
    cout << "[3] Return an Office\n";
    cout << "[4] Show Office Details\n";
    cout << "[5] Display All Offices\n";
    cout << "[6] Add New Client\n";
    cout << "[7] Show Client Details\n";
    cout << "[8] Exit\n";
    cout << "Choose an option: ";
}

int main() {
    office officeList = office(1);
    client clientList = client(1);
    fileHandling officeFile("offices.txt");
    fileHandling clientFile("clients.txt");

    // officeFile.init();
    // clientFile.init();

    int choice;
    // do {
    //     displayMenu();
    //     cin >> choice;
    //     cin.ignore();

    //     switch (choice) {
    //         case 1: {
    //             officeInformation newOffice;
    //             cout << "Enter Office ID: ";
    //             cin >> newOffice.id;
    //             cin.ignore();
    //             cout << "Enter Office Name: ";
    //             getline(cin, newOffice.officeName);
    //             cout << "Enter Office Address: ";
    //             getline(cin, newOffice.officeAddress);
    //             cout << "Enter Office Price: ";
    //             cin >> newOffice.officePrice;
    //             cout << "Enter Office Size: ";
    //             cin >> newOffice.officeSize;
    //             newOffice.isRented = false;

    //             officeList.addOffice(newOffice);
    //             cout << "New Office added successfully!\n";
    //             break;
    //         }
    //         case 2: {
    //             int officeId;
    //             cout << "Enter Office ID to rent: ";
    //             cin >> officeId;

    //             officeInformation office = officeList.getOffice(officeId);
    //             if (office.id != 0 && !office.isRented) {
    //                 office.isRented = true;
    //                 officeList.rentOffice(office);
    //                 cout << "Office rented sucessfully!\n";
    //             } else {
    //                 cout << "Office is not available for rent.\n";
    //             }
    //             break;
    //         }
    //         case 3: {
    //             int officeId;
    //             cout << "Enter office ID to return: ";
    //             cin >> officeId;

    //             officeInformation office = officeList.getOffice(officeId);
    //             if (office.id != 0 && office.isRented) {
    //                 office.isRented = false;
    //                 officeList.endRental(office);
    //                 cout << "Office returned successfully!\n";
    //             } else {
    //                 cout << "Office not currently rented.\n";
    //             }
    //             break;
    //         }
    //         case 4: {
    //             int officeId;
    //             cout << "Enter Office ID to show detials: ";
    //             cin >> officeId;

    //             officeInformation officeData = officeList.getOffice(officeId);
    //             if (officeData.id != 0) {
    //                 cout << "Office ID: " << officeData.id << endl;
    //                 cout << "Office Name: " << officeData.officeName << endl;
    //                 cout << "Office Address: " << officeData.officeAddress << endl;
    //                 cout << "Office Price: " << officeData.officePrice << endl;
    //                 cout << "Office Size: " << officeData.officeSize << endl;
    //                 cout << "Is Office Rented? " << (officeData.isRented ? "Yes" : "No") << endl;
    //             } else {
    //                 cout << "Office is not found.\n";
    //             }
    //             break;
    //         }
    //         case 5: {
    //             cout << "Displaying all offices: \n";
    //             // officeList.print();
    //             break;
    //         }
    //         case 6: {
    //             clientData newClient;
    //             cout << "Enter Client ID: ";
    //             cin >> newClient.id;
    //             cin.ignore();
    //             cout << "Enter Client Name: ";
    //             getline(cin, newClient.clientName);
    //             cout << "Enter Client Address: ";
    //             getline(cin, newClient.clientAddress);
    //             clientList.addClient(newClient);
    //             cout << "New client added successfully!\n";
    //             break;
    //         }
    //         case 7: {
    //             int clientId;
    //             cout << "Enter Client ID to show details: ";
    //             cin >> clientId;
    //             clientData client = clientList.getClient(clientId);
    //             if (client.id != 0) {
    //                 cout << "Client ID: " << client.id << endl;
    //                 cout << "Client Name: " << client.clientName << endl;
    //                 cout << "Client Address: " << client.clientAddress << endl;
    //             } else {
    //                 cout << "Client not found.\n";
    //             }
    //             break;
    //         }
    //         case 8: {
    //             cout << "Exiting program...\n";
    //             break;
    //         }
    //         default:
    //             cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 8);

    return 0;
}