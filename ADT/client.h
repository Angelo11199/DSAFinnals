//* customer parent
#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "../includes/LinkedList.h"
#include "../includes/fileHandling.h"
#include "./structData.h"

/**
 * @brief represents a client management class
 *
 * @details manages client data and operations using a linked list structure
 */
class client : LinkedList<clientData> {
   protected:
    int clientId = 0;  // currentlly logged in client
    fileHandling file = fileHandling("clients.csv");

   private:
    clientData loggedClient;
    LinkedList<clientData> clientList;

   public:
    /**
     * @brief Constructor for the client class
     *
     * @param clientId ID of the client being managed
     */
    client(int clientId);

    /**
     * @brief Destroy the client object
     *
     */
    ~client();

    /**
     * @brief Adds a new client to the management system
     *
     * @param data Information about the client to be added
     * @param current Indicates if the client is the currently logged-in client
     */
    void addClient(clientData data, bool current = false);

    /**
     * @brief Adds information about an office rented by a client
     *
     * @param data Information about the office being rented
     */
    void addRentedSpace(officeInformation data);

    /**
     * @brief Retrieves information about a specific client
     *
     * @param clientId ID of the client to retrieve information for
     * @return clientData Information about the requested client
     */
    clientData getClient(int clientId);

    /**
     * @brief Changes the information of a specific client
     *
     * @param clientId ID of the client to change information for
     */
    void changeClient(int clientId);

    /**
     * @brief Removes a client from the management system
     *
     * @param data Information about the client to be removed
     */
    void removeClient(int data);

    /**
     * @brief Prints information about all clients in the system
     *
     */
    void printClients();
};
#endif