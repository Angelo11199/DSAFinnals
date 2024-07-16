#ifndef OFFICE_H
#define OFFICE_H
#include "../includes/LinkedList.h"
#include "../includes/fileHandling.h"
#include "./structData.h"
/**
 * @brief Represents an office management class
 *
 * @details class manages office data including rental operations,
 * which used a linked list structure.
 */
class office : public LinkedList<officeInformation> {
   private:
    /**
     * @brief represents a node in the linked list
     *
     */
    struct Node {
        officeInformation data;
        Node* next;
    };
    fileHandling file = fileHandling("offices.csv");
    static office* instance;
    office();  // Private constructor

   public:
    /**
     * @brief Constructor for the office class
     *
     * @param clientID ID of the client using the office management system.
     */
    office(int clientID);

    /**
     * @brief Adds a new office to the management system
     *
     * @param data information about the office to be added
     */
    void addOffice(officeInformation data);

    /**
     * @brief Rents an office to a specified client
     *
     * @param data Information about the office to be rented
     * @param clientID ID of the client renting the office.
     */
    void rentOffice(officeInformation data, int clientID);

    /**
     * @brief Ends the rental of an office, making it available again
     *
     * @param data Information about the office whose rental is ending
     */
    void endRental(officeInformation data);

    /**
     * @brief prints info about all offices in the system
     *
     */
    void printOffices();

    /**
     * @brief retrieves detailed info about a specific office
     *
     * @param officeId ID of the office to retrieve information for
     * @return officeInformation Information about the requested office
     */
    officeInformation getOffice(int officeId);

    /**
     * @brief retrieves a list of offices currently rented out
     *
     * @return LinkedList<officeInformation> List of rented offices
     */
    LinkedList<officeInformation> getRentedOffices();
    /**
     * @brief Destroy the office object
     *
     */
    ~office();
};
#endif