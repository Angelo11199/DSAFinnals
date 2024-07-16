#ifndef STRUCTDATA_H
#define STRUCTDATA_H
#include <string>
// Data types for the program. Just to have a unified place to store  all data types plus intellisene support
#include "../includes/LinkedList.h"

/**
 * @brief Struct defining information about an office
 *
 * contains details about an office, including the ID,
 * name, address, rental price, size, and rental status
 */
struct officeInformation {
    int id;
    std::string officeName;
    std::string officeAddress;
    int officePrice;
    std::string officeSize;
    bool isRented;
};

/**
 * @brief Struct defining information about a client
 *
 * This struct contains details about a client, including ID
 * name, address, administrator status, and list of rented office spaces
 */
struct clientData {
    int id;
    std::string clientName;
    std::string clientAddress;
    bool isAdmin;
    LinkedList<officeInformation> rentedSpaces;
};

/**
 * @brief Struct defining basic user information
 *
 * @details Contains basic information about a user, such as username,
 * password, and role
 */
struct User {
    std::string username;
    std::string password;
    int role;
};

#endif