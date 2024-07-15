//* customer parent
#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "../includes/LinkedList.h"
#include "officeRental.h"
#include "structData.h"
class client : LinkedList<clientData> {
   protected:
    int clientId = NULL;  // currentlly logged in client

   private:
    LinkedList<clientData> clientList;
    Node *head;
    LinkedList<officeInformation> rented;

   public:
    client(int clientId);
    ~client();
    void addClient(clientData data);
    void addRentedSpace(officeInformation data);
    clientData getClient(int clientId);
    void changeClient(int clientId);
    void removeClient(int data);
    void printClients();
};
#endif