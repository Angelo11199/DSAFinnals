#include "client.h"

#include <iostream>

client::client() {}
client::~client() {}

void client::addClient(clientData data) {
    clientList.add(data);
}
// todo : might need to change this. Might cause infinite loop
clientData client::getClient(int clientId) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.clientID == clientId) {
            return current->data;
        }
        current = current->next;
    }
    return {};
}
void client::removeClient(int clientId) {
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data.clientID == clientId) {
            clientList.remove(current->data);
            break;
        }
        current = current->next;
    }
}

void client::printClients() {
}

void client::getClientRentedSpaces(clientData client) {
}
