//* shows a list of AVAILABLE (NOT RENTED) offices.
#include "officeRental.h"

#include "office.h"
clientRent::clientRent(int clientId) : client(clientId) {
    // enter file handling here. where it will read to availableOffices.csv
    this->clientId = clientId;
};
bool rentOffice(int officeId) {
    officeInformation office = getOffice(officeId);
    if (office.isRented) {
        return false;
    }
    office.isRented = true;
    rentOffice(office);
    return true;
}
officeInformation* getRentedOffices() {
    return getRentedOffices();
}