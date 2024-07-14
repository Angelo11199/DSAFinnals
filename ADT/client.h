#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "../includes/LinkedList.h"
#include "officeRental.h"
#include "structData.h"
class client : public LinkedList<clientData> {
   private:
    struct Node {
        clientData data;
        Node *next;
    };

    LinkedList<clientData> clientList;
    void getClientRentedSpaces(clientData client);
    Node *head;

   public:
    client();
    ~client();
    void addClient(clientData data);
    clientData getClient(int clientId);
    void removeClient(int data);
    void printClients();
};
#endif
