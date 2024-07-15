//* customer parent
#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "../includes/LinkedList.h"
#include "officeRental.h"
#include "structData.h"
class client : LinkedList<clientData> {
   private:
    struct Node {
        clientData data;
        Node *next;
    };
    int clientId = NULL;  // currentlly logged in client
    LinkedList<clientData> clientList;
    LinkedList<officeInformation> getClientRentedSpaces(int clientId);
    int rentedSpaces = 0;
    Node *head;

   public:
    client(int clientId);
    ~client();
    void addClient(clientData data);
    clientData getClient(int clientId);
    void removeClient(int data);
    void printClients();
};
#endif