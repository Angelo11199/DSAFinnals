#ifndef STRUCTDATA_H
#define STRUCTDATA_H
#include <string>
// Data types for the program. Just to have a unified place to store  all data types plus intellisene support
#include "../includes/LinkedList.h"
struct officeInformation {
    int officeID;
    std::string officeName;
    std::string officeAddress;
    int officePrice;
    int officeSize;
    bool isRented;
};
struct clientData {
    int clientID;
    std::string clientName;
    std::string clientAddress;
    LinkedList<officeInformation> rentedSpaces;
};
struct User {
    std::string username;
    std::string password;
    int role;
};

#endif