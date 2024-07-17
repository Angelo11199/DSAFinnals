
#ifndef OFFICE_CPP
#define OFFICE_CPP
#include "office.h"

#include <array>
#include <iostream>

#include "../includes/LinkedList.h"
#include "../includes/fileHandling.h"
#include "../includes/utils.h"

office::office(int clientID) : LinkedList() {
    LinkedList<std::string> data = file.readFromFile();
    const std::size_t size = 6;
    std::array<std::string, size> output;
    // while (current != nullptr) {
    //     (current->data, ',', output);
    //     officeInformation office;
    //     office.id = std::stoi(officeData[0]);
    //     office.officeName = officeData[1];
    //     office.officeAddress = officeData[2];
    //     office.officePrice = std::stoi(officeData[3]);
    //     office.officeSize = officeData[4];
    //     office.isRented = officeData[5] == "1";
    //     add(office);
    //     current = current->next;
    // }
};
void office::addOffice(officeInformation data) {
    add(data);
    file.writeToFile(data.id, data.officeName, data.officeAddress, data.officePrice, data.officeSize, data.isRented);
};
void office::endRental(officeInformation data) {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id != data.id) {
            current = current->next;
            continue;
        }
        current->data.isRented = false;
        file.writeToFile(data.id, data.officeName, data.officeAddress, data.officePrice, data.officeSize, data.isRented);
    }
}
officeInformation office::getOffice(int officeId) {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id == officeId) {
            return current->data;
        }
        current = current->next;
    }
    return officeInformation();
}
LinkedList<officeInformation> office::getRentedOffices() {
    LinkedList<officeInformation> rentedOffices;
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        rentedOffices.add(current->data);
        current = current->next;
    }
    return rentedOffices;
}
void office::rentOffice(officeInformation data, int clientID) {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id != data.id) {
            current = current->next;
            continue;
        }
        current->data.isRented = true;
        file.writeToFile(data.id, clientID);
    }
}
office::~office() {
    std::cout << "Office Deleted" << std::endl;
    if (head != nullptr) return;
    delete head;
}
#endif