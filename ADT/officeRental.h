#ifndef OFFICERENTAL_H
#define OFFICERENTAL_H
#include <string>

#include "client.h"
class clientRent : public client {
   private:
    int clientId;

   public:
    clientRent(int clientId) {
        this->clientId = clientId;
        clientData client = getClient(clientId);
    };

    void rentOffice(int officeId);
    void returnOffice(int officeId);
    officeInformation* getRentedOffices();
    ~clientRent();
};
#endif