#include "office.h"

office::office() {}

void office::addOffice(officeInformation data) {
    LinkedList<officeInformation>::add(data);
}

void office::rentOffice(officeInformation data) {
    LinkedList<officeInformation>::remove(data);
}

void office::endRental(officeInformation data) {
    LinkedList<officeInformation>::add(data);
}

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

office::~office() {
}
