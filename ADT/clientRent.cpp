//* shows a list of ALL offices.
#ifndef OFFICERENTAL_CPP
#define OFFICERENTAL_CPP
#include "./clientRent.h"

#include <iostream>

#include "../includes/FileHandling.h"
#include "../includes/utils.h"
#include "./client.h"
#include "./office.h"

clientRent::clientRent(int clientID) : client(clientID) {
    clientId = clientID;
    LinkedList<std::string> data = file.readFromFile();
    auto current = data.getHead();
    const size_t size = 2;
    while (current != nullptr) {
        std::array<std::string, size> output;
        splitData(current->data, ',', output);
        clientRentData office;
        // check if output is not empty
        if (output[0].empty() || output[1].empty()) {
            current = current->next;
            continue;
        }
        office.clientId = std::stoi(output[0]);
        office.officeId = std::stoi(output[1]);
        if (clientId == office.clientId) {
            LinkedList<clientRentData>::add(office);
        }
        current = current->next;
    }
};
bool clientRent::rentOffice(int officeId) {
    LinkedList<clientRentData>::Node* current = LinkedList<clientRentData>::head;
    while (current != nullptr) {
        if (current->data.clientId != officeId) {
            current = current->next;
            continue;
        }
    }
    file.writeToFile(clientId, officeId);
    return true;
}
void clientRent::showRentedOffices() {
    auto currentOffice = office(clientId).getHead();
    LinkedList<clientRentData>::Node* current = LinkedList<clientRentData>::getHead();
    while (current != nullptr) {
        while (currentOffice != nullptr) {
            if (current->data.officeId == currentOffice->data.id) {
                std::cout << "office Name: " << currentOffice->data.officeName << std::endl;
                std::cout << "office Address: " << currentOffice->data.officeAddress << std::endl;
                std::cout << "office Price: " << currentOffice->data.officePrice << std::endl;
                std::cout << "office Size: " << currentOffice->data.officeSize << std::endl;
            }
            currentOffice = currentOffice->next;
        }
        current = current->next;
    }
}
clientRent::~clientRent() {
    std::cout << "Client Rent Destructor Called" << std::endl;
}

#endif
