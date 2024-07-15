//* child class of client. Responsible for renting an office, checking if an office is rented or not as well.
#ifndef OFFICERENTAL_H
#define OFFICERENTAL_H
#include <string>

#include "client.h"
// responsible for client renting an office, checking if an office is rented or not as well.
class clientRent : public client, LinkedList<officeInformation> {
   private:
    int clientId;
    struct Node {
        officeInformation data;
        Node* next;
    };

   public:
    clientRent(int clientId);
    bool rentOffice(int officeId);
    officeInformation* getRentedOffices();
    ~clientRent();
};
#endif