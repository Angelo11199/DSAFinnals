#ifndef OFFICE_H
#define OFFICE_H
#include "../includes/LinkedList.h"
#include "structData.h"
// responsible for storing office data. checking if an office is rented or not as well.
class office : public LinkedList<officeInformation> {
   private:
    struct Node {
        officeInformation data;
        Node* next;
    };

   public:
    office(int clientID);
    void addOffice(officeInformation data);
    void rentOffice(officeInformation data);
    void endRental(officeInformation data);
    void printOffices();
    officeInformation getOffice(int officeId);
    LinkedList<officeInformation> getRentedOffices();
    ~office();
};
#endif