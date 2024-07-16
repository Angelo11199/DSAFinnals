#ifndef OFFICE_H
#define OFFICE_H
#include "../includes/LinkedList.h"
#include "../includes/fileHandling.h"
#include "./structData.h"
class office : public LinkedList<officeInformation> {
   private:
    struct Node {
        officeInformation data;
        Node* next;
    };
    fileHandling file = fileHandling("offices.csv");

   public:
    office(int clientID);
    void addOffice(officeInformation data);
    void rentOffice(officeInformation data, int clientID);
    void endRental(officeInformation data);
    void printOffices();
    officeInformation getOffice(int officeId);
    LinkedList<officeInformation> getRentedOffices();
    ~office();
};
#endif