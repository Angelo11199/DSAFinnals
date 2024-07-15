//* child class of client. Responsible for renting an office, checking if an office is rented or not as well.
#ifndef OFFICERENTAL_H
#define OFFICERENTAL_H
#include <string>

#include "client.h"
// responsible for client renting an office, checking if an office is rented or not as well.
class clientRent : public client {
   private:
    int clientId;

   public:
    clientRent(int clientId);

    void rentOffice(int officeId);
    officeInformation* getRentedOffices();
    ~clientRent();
};
#endif