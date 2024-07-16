//* customer parent
#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "../includes/LinkedList.h"
#include "./structData.h"
class client : LinkedList<clientData> {
   protected:
    int clientId = 0;  // currentlly logged in client

   private:
    clientData loggedClient;
    LinkedList<clientData> clientList;
    Node *head;
    LinkedList<officeInformation> rented = LinkedList<officeInformation>();

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