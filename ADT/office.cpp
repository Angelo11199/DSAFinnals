
#ifndef OFFICE_CPP
#define OFFICE_CPP
#include "office.h"

#include <iostream>
#include <vector>

#include "../includes/LinkedList.h"
#include "../includes/fileHandling.h"
#include "../includes/utils.h"

office::office(int clientID) : LinkedList() {
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
        if (office.id != clientID) continue;
        add(office);
    }
};

officeInformation office::getOffice(int officeId) {
    typename LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id == officeId) {
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
};

office::~office() {
    delete head;
}
#endif