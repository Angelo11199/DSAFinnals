//* child class of client. Responsible for renting an office, checking if an office is rented or not as well.
#ifndef OFFICERENTAL_H
#define OFFICERENTAL_H
#include "../includes/LinkedList.h"
#include "./client.h"
#include "./office.h"
// responsible for client renting an office, checking if an office is rented or not as well.
class clientRent : public client, public LinkedList<officeInformation> {
   private:
    int clientId;

   public:
    clientRent(int clientId);
    bool rentOffice(int officeId);
    void ShowAvailableOffices();
    ~clientRent();
};
#endif