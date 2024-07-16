//* shows a list of AVAILABLE (NOT RENTED) offices.
#ifndef OFFICERENTAL_CPP
#define OFFICERENTAL_CPP
#include "./officeRental.h"

#include <iostream>

#include "../includes/FileHandling.h"
#include "../includes/utils.h"
#include "./client.h"
#include "./office.h"
clientRent::clientRent(int clientId) : client(clientId), LinkedList<officeInformation>() {
    this->clientId = clientId;
    fileHandling file = fileHandling("offices.csv");
    std::vector<std::string> data = file.readFromFile();
    for (std::string line : data) {
        std::vector<std::string> officeData = splitData(line, ',');
        officeInformation office;
        office.id = std::stoi(officeData[0]);
        office.officeName = officeData[1];
        office.officeAddress = officeData[2];
        office.officePrice = std::stoi(officeData[3]);
        office.officeSize = officeData[4];
        office.isRented = officeData[5] == "1";
        this->LinkedList<officeInformation>::add(office);
    }
};
bool clientRent::rentOffice(int officeId) {
    LinkedList<officeInformation>::Node* current = LinkedList<officeInformation>::head;
    while (current != nullptr) {
        if (current->data.id != officeId) {
            current = current->next;
            continue;
        }
        if (current->data.isRented) {
            return false;
        }
        current->data.isRented = true;
        addRentedSpace(current->data);
        return true;
    }
    return false;
}
void clientRent::ShowAvailableOffices() {
    LinkedList<officeInformation>::Node* current = LinkedList<officeInformation>::head;
    while (current != nullptr) {
        if (!current->data.isRented) {
            std::string isRented = current->data.isRented ? "Yes" : "No";
            std::cout << "Office ID: " << current->data.id << std::endl;
            std::cout << "Office Name: " << current->data.officeName << std::endl;
            std::cout << "Office Address: " << current->data.officeAddress << std::endl;
            std::cout << "Office Size: " << current->data.officeSize << std::endl;
            std::cout << "Unit Price: " << current->data.officePrice << std::endl;
        }
        current = current->next;
    }
}
clientRent::~clientRent() {
    delete LinkedList<officeInformation>::head;
}
#endif
