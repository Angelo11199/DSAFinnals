#include "client.h"

#include <iostream>

#include "LinkedList.h"

client::client() : LinkedList() {};

void client::addClient(clientData data) { LinkedList::add(data); };
clientData client::getClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.clientID == clientId) {
            return current->data;
        }
        current = current->next;
    }
    return {};  // return empty clientData struct if not found
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

void client::printClients() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Client ID: " << current->data.clientID << std::endl;
        std::cout << "Client Name: " << current->data.clientName << std::endl;
        std::cout << "Client Phone: " << current->data.clientAddress << std::endl;
        std::cout << "Client Rented Space: " << rentedSpaces << std::endl;
        getClientRentedSpaces(current->data);
        current = current->next;
    }
}

void client::getClientRentedSpaces(clientData client) {
}
client::~client() { delete head; }
