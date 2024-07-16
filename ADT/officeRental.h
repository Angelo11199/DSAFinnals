//* child class of client. Responsible for renting an office, checking if an office is rented or not as well.
#ifndef OFFICERENTAL_H
#define OFFICERENTAL_H
#include "../includes/LinkedList.h"
#include "./client.h"
#include "./office.h"

/**
 * @brief Represents a client rental management class
 *
 * @details Handles renting offices by clients and checking the rental status of offices
 */
class clientRent : public client, public LinkedList<officeInformation> {
   private:
    int clientId;

   public:
    /**
     * @brief Constructor for the clientRent class
     *
     * @param clientId ID of the client using the rental management
     */
    clientRent(int clientId);

    /**
     * @brief Rents an office for the client
     *
     * @param officeId ID of the office to rent
     * @return true If the office was successfully rented
     * @return false Otherwise
     */
    bool rentOffice(int officeId);

    /**
     * @brief Shows available offices that can be rented
     *
     */
    void ShowAvailableOffices();

    /**
     * @brief Destroy the client Rent object
     *
     */
    ~clientRent();
};
#endif