//* shows a list of ALL offices.
#ifndef OFFICERENTAL_CPP
#define OFFICERENTAL_CPP
#include "./officeRental.h"

#include <iostream>

#include "../includes/FileHandling.h"
#include "../includes/utils.h"
#include "./client.h"
#include "./office.h"
clientRent::clientRent(std::string clientId) : client(clientId) {
    this->clientId = clientId;
    LinkedList<std::string> data = file.readFromFile();
    auto current = data.getHead();
    const size_t size = 2;
    while (current != nullptr) {
        std::array<std::string, size> output;
        splitData(current->data, ',', output);
        clientRentData office;
        office.clientId = output[0];
        office.officeId = output[1];
        if (clientId == output[0]) {
            LinkedList<clientRentData>::add(office);
        }
        current = current->next;
    }
};
bool clientRent::rentOffice(std::string officeId) {
    LinkedList<clientRentData>::Node* current = LinkedList<clientRentData>::head;
    while (current != nullptr) {
        if (current->data.officeId != officeId) {
            current = current->next;
            continue;
        }
    }
    file.writeToFile(clientId, officeId);
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
