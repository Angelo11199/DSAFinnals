#ifndef OFFICE_H
#define OFFICE_H
#include "../includes/LinkedList.h"
#include "structData.h"
class office : public LinkedList<officeInformation> {
   private:
    int officeId;
    int officeSize;
    int officePrice;
    bool isRented;

   public:
    office() {}
    void addOffice(officeInformation data) { LinkedList<officeInformation>::add(data); }
    void rentOffice(officeInformation data) { LinkedList<officeInformation>::remove(data); }
    void endRental(officeInformation data) { LinkedList<officeInformation>::add(data); }
    officeInformation getOffice(int officeId) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.officeID == officeId) {
                return current->data;
            }
            current = current->next;
        }
    }
    ~office() {
        delete head;
    };
};
#endif