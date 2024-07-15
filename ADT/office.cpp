#include "office.h"

#include <iostream>
#include <vector>

#include "../includes/utils.h"
#include "fileHandling.h"

office::office(int clientID) : LinkedList() {
    fileHandling file = fileHandling("offices.csv");
    std::vector<std::string> data = file.readFromFile();
    for (std::string line : data) {
        std::vector<std::string> officeData = splitData(line, ',');
        officeInformation office;
        office.officeID = std::stoi(officeData[0]);
        office.officeName = officeData[1];
        office.officeAddress = officeData[2];
        office.officePrice = std::stoi(officeData[3]);
        office.officeSize = officeData[4];
        office.isRented = officeData[5] == "1";
        if (office.officeID != clientID) continue;
        add(office);
    }
};

officeInformation office::getOffice(int officeId) {
    typename LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.officeID == officeId) {
            return current->data;
        }
        current = current->next;
    }
    return officeInformation();
}
LinkedList<officeInformation> office::getRentedOffices() {
    LinkedList<officeInformation> rentedOfficesList;
    typename LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.isRented) {
            rentedOfficesList.add(current->data);
        }
        current = current->next;
    }
    return rentedOfficesList;
}

void LinkedList<officeInformation>::print() {
    typename LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        std::string isRented = current->data.isRented ? "Yes" : "No";
        std::cout << "Office ID: " << current->data.officeID << std::endl;
        std::cout << "Office Name: " << current->data.officeName << std::endl;
        std::cout << "Office Address: " << current->data.officeAddress << std::endl;
        std::cout << "Office Size: " << current->data.officeSize << std::endl;
        std::cout << "Price Bought: " << current->data.officePrice << std::endl;
        current = current->next;
    }
}

office::~office() {
    delete head;
}
