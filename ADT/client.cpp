#include "client.h"

#include <iostream>

#include "LinkedList.h"

client::client(int clientID) : LinkedList() {
    clientId = clientID;
    clientData client = getClient(clientID);
    if (client.clientID == NULL) {
        // throw error
    }
    rented = client.rentedSpaces;
};

void client::addClient(clientData data) { add(data); };
clientData client::getClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.clientID == clientId) return current->data;
        current = current->next;
    }
    return {};
}
void client::removeClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.clientID == clientId) {
            clientList.remove(current->data);
            break;
        }
        current = current->next;
    }
}
void LinkedList<officeInformation>::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Office ID: " << current->data.officeID << std::endl;
        std::cout << "Office Size: " << current->data.officeSize << std::endl;
        std::cout << "Office Price: " << current->data.officePrice << std::endl;
        std::cout << "Is Office Rented? " << current->data.isRented << std::endl;
        current = current->next;
    }
}
void client::printClients() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Client ID: " << current->data.clientID << std::endl;
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
        if (current->data.clientID == clientId) {
            current->data = getClient(clientId);
            break;
        }
        current = current->next;
    }
}
client::~client() { delete head; }
