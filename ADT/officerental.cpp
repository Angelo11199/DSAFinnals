//* shows a list of AVAILABLE (NOT RENTED) offices.
#include "officeRental.h"

#include <iostream>

#include "office.h"
clientRent::clientRent(int clientId) : client(clientId), LinkedList<officeInformation>() {};
bool clientRent::rentOffice(int officeId) {
    LinkedList<officeInformation>::Node* current = LinkedList<officeInformation>::head;
    while (current != nullptr) {
        if (current->data.officeID != officeId) {
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
            std::cout << "Office ID: " << current->data.officeID << std::endl;
            std::cout << "Office Size: " << current->data.officeSize << std::endl;
            std::cout << "Office Price: " << current->data.officePrice << std::endl;
        }
        current = current->next;
    }
}
clientRent::~clientRent() {
    delete LinkedList<officeInformation>::head;
}