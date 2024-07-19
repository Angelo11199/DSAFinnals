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
        if (current->data.officeId == officeId) {
            std::cout << "Office already rented" << std::endl;
            return false;
        }
        current = current->next;
    }
    LinkedList<clientRentData>::add({clientId, officeId});
    file.writeToFile(clientId, officeId);
    return true;
}
void clientRent::showRentedOffices(int currentClent) {
    if (currentClent == 0) currentClent = clientId;
    auto currentOffice = office(currentClent).getHead();
    LinkedList<clientRentData>::Node* current = LinkedList<clientRentData>::getHead();
    while (current != nullptr) {
        while (currentOffice != nullptr) {
            if (current->data.officeId == -1) {
                break;
            }
            if (currentOffice->data.id == current->data.officeId) {
                std::cout << "Office ID: " << currentOffice->data.id << std::endl;
                std::cout << "Office Name: " << currentOffice->data.officeName << std::endl;
                std::cout << "Office Address: " << currentOffice->data.officeAddress << std::endl;
                std::cout << "Office Price: " << currentOffice->data.officePrice << std::endl;
                std::cout << "Office Size: " << currentOffice->data.officeSize << std::endl;
                std::cout << "Office is Rented: " << currentOffice->data.isRented << std::endl;
                std::cout << std::endl;
                break;
            }
            currentOffice = currentOffice->next;
        }
        current = current->next;
    }
}
void clientRent::endRental(int officeId) {
    LinkedList<clientRentData>::Node* current = LinkedList<clientRentData>::head;
    while (current != nullptr) {
        if (current->data.officeId != officeId) {
            current = current->next;
            continue;
        }
        if (officeId == current->data.officeId) {
            file.deleteRow(2, std::to_string(officeId));
            current->data.officeId = -1;
            break;
        }
    }
}
clientRent::~clientRent() {
    // std::cout << "Client Rent Destructor Called" << std::endl;
}

#endif
