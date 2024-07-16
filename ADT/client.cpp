#ifndef CLIENT_CPP
#define CLIENT_CPP
#include "./client.h"

#include <iostream>
#include <vector>

#include "../includes/FileHandling.h"
#include "../includes/LinkedList.h"
#include "../includes/utils.h"
#include "./office.h"
client::client(int clientID) : LinkedList() {
    if (clientID == -1) return;
    clientId = clientID;
    std::vector<std::string> data = file.readFromFile();
    for (std::string line : data) {
        std::vector<std::string> clientData = splitData(line, ',');
        if (clientID == std::stoi(clientData[0])) {
            loggedClient.id = std::stoi(clientData[0]);
            loggedClient.clientName = clientData[1];
            loggedClient.clientAddress = clientData[2];
            loggedClient.isAdmin = std::stoi(clientData[3]) == 1;
            loggedClient.rentedSpaces = rented = office(clientID).getRentedOffices();
        }
        clientList.add({std::stoi(clientData[0]), clientData[1], clientData[2], std::stoi(clientData[3]) == 1});
    };
    if (loggedClient.clientName == "") {
        std::cout << "Client not found" << std::endl;
    }
};

void client::addClient(clientData data, bool current) {
    std::cout << data.isAdmin << std::endl;
    add(data);
    file.writeToFile(data.id, data.clientName, data.clientAddress, data.isAdmin);
    if (current) {
        clientId = data.id;
    };
}
clientData client::getClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == clientId) return current->data;
        current = current->next;
    }
    return {};
}
/**
 * @brief remove a client from the client list
 *
 * @param clientId
 */
void client::removeClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == clientId) {
            clientList.remove(current->data);
            break;
        }
        current = current->next;
    }
}
// void LinkedList<officeInformation>::print() {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << "Office ID: " << current->data.officeID << std::endl;
//         std::cout << "Office Size: " << current->data.officeSize << std::endl;
//         std::cout << "Office Price: " << current->data.officePrice << std::endl;
//         std::cout << "Is Office Rented? " << current->data.isRented << std::endl;
//         current = current->next;
//     }
// }
void client::printClients() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Client ID: " << current->data.id << std::endl;
        std::cout << "Client Name: " << current->data.clientName << std::endl;
        std::cout << "Client Phone: " << current->data.clientAddress << std::endl;
        std::cout << "Client Rented Space: " << rented.getSize() << std::endl;
        current = current->next;
    }
}
void client::addRentedSpace(officeInformation data) { rented.add(data); };
void client::changeClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == clientId) {
            current->data = getClient(clientId);
            break;
        }
        current = current->next;
    }
}
client::~client() {
    std::cout << "Client Deleted" << std::endl;
    if (head != nullptr) return;
    delete head;
}
#endif