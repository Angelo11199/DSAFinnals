
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
    auto current = data.getHead();
    while (current != nullptr) {
        std::array<std::string, size> output;
        splitData(current->data, ',', output);
        officeInformation office;
        office.id = std::stoi(output[0]);
        office.officeName = output[1];
        office.officeAddress = output[2];
        office.officePrice = std::stoi(output[3]);
        office.officeSize = output[4];
        office.isRented = output[5] == "1";
        add(office);
        current = current->next;
    }
};
void office::addOffice(officeInformation data) {
    data.id = size + 1;
    add(data);
    file.writeToFile(data.id, data.officeName, data.officeAddress, data.officePrice, data.officeSize, 0);
};
void office::endRental(officeInformation data) {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id == data.id) {
            file.updateFile(std::to_string(0), data.id, 5);
            current->data.isRented = false;
            break;
        }
        current = current->next;  // Move to the next node if not a match
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
    return {};
}
void office::rentOffice(officeInformation data, int clientID) {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        if (current->data.id != data.id) {
            current = current->next;
            continue;
        }
        if (current->data.isRented) {
            std::cout << "Office is already rented" << std::endl;
            return;
        }
        if (current->data.id == data.id) {
            current->data.isRented = true;
            file.updateFile(std::to_string(1), data.id, 5);
            break;
        }
    }
}
void office::printOffices() {
    LinkedList<officeInformation>::Node* current = head;
    while (current != nullptr) {
        std::cout << "-------------------------------------------------------------------------" << std::endl;
        std::cout << "Office ID: " << current->data.id << std::endl;
        std::cout << "Office Name: " << current->data.officeName << std::endl;
        std::cout << "Office Address: " << current->data.officeAddress << std::endl;
        std::cout << "Office Price: " << current->data.officePrice << std::endl;
        std::cout << "Office Size: " << current->data.officeSize << std::endl;
        std::cout << "Office is Rented: " << (current->data.isRented ? "Yes" : "No") << std::endl;
        current = current->next;
    }
    std::cout << "-------------------------------------------------------------------------" << std::endl;
}
office::~office() {
    // std::cout << "Office Deleted" << std::endl;
    // if (head != nullptr) return;
    // delete head;
}
#endif