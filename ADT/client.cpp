#ifndef CLIENT_CPP
#define CLIENT_CPP
#include "./client.h"

#include <array>
#include <iostream>
#include <vector>

#include "../includes/FileHandling.h"
#include "../includes/LinkedList.h"
#include "../includes/utils.h"
#include "./clientRent.h"
#include "./office.h"
client::client(int clientID) {
    if (clientID == -1) return;
    clientId = clientID;
    LinkedList<std::string> data = file.readFromFile();
    auto current = data.getHead();
    const std::size_t size = 4;
    bool isUser = false;
    while (current != nullptr) {
        std::array<std::string, size> output;
        splitData(current->data, ',', output);
        current = current->next;
        if (clientID == std::stoi(output[0])) {
            loggedClient.id = std::stoi(output[0]);
            loggedClient.clientName = output[1];
            loggedClient.clientAddress = output[2];
            loggedClient.isAdmin = output[3] == "1";
        }
        add({std::stoi(output[0]), output[1], output[2], output[3] == "1"});
    }
    if (loggedClient.clientName == "") {
        std::cout << "Client not found" << std::endl;
    }
}

int client::addClient(clientData data, bool current) {
    data.id = size + 1;
    std::cout << data.isAdmin << std::endl;
    add(data);
    file.writeToFile(data.id, data.clientName, data.clientAddress, data.isAdmin);
    if (current) {
        clientId = data.id;
    };
    return data.id;
}
clientData client::getClient(int clientId) {
    Node* current = this->head;
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
            remove(current->data);
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
        std::cout << "-------------------------------------------------------------------------" << std::endl;
        std::cout << "Client ID: " << current->data.id << std::endl;
        std::cout << "Client Name: " << current->data.clientName << std::endl;
        std::cout << "Client Phone: " << current->data.clientAddress << std::endl;
        current = current->next;
    }
    std::cout << "-------------------------------------------------------------------------" << std::endl;
}
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
    // std::cout << "Client Deleted" << std::endl;
    // if (head != nullptr) {
    //     Node* current = head;
    //     while (current != nullptr) {
    //         Node* temp = current;
    //         current = current->next;
    //         delete temp;
    //     }
    // }
}

#endif