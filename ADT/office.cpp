//* srtictly for office that are ALREADY RENTED.
#include "office.h"

#include <iostream>

office::office() : LinkedList() {};

void office::addOffice(officeInformation data) { add(data); }

void office::rentOffice(officeInformation data) { remove(data); }

void office::endRental(officeInformation data) { add(data); }

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
// returns a list of rented offices
LinkedList<officeInformation> office::getRentedOffices(int offset = 0) {
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
        std::cout << "Office Size: " << current->data.officeSize << std::endl;
        std::cout << "Office Price: " << current->data.officePrice << std::endl;
        std::cout << "Is Office Rented? " << isRented << std::endl;
        current = current->next;
    }
}

office::~office() {
    delete head;
}
