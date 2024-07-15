//* shows a list of AVAILABLE (NOT RENTED) offices.
#include "officeRental.h"

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
        addrentedSpaces(current->data);
        return true;
    }
    return false;
}
officeInformation* getRentedOffices() {
    return getRentedOffices();
}