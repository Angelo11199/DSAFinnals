#ifndef UTILS_H
#define UTILS_H

#include <array>
#include <iostream>
#include <sstream>
#include <string>

#include "./LinkedList.h"
/**
 * @brief Splits a string into parts based on a delimiter
 *
 * @param data The string to be split
 * @param delimiter The character to split the string by
 * @return std::vector<std::string> Vector of strings containing the split parts
 */
// Definition of splitData function
template <size_t N>
void splitData(const std::string& input, char delimiter, std::array<std::string, N>& output) {
    std::istringstream stream(input);
    std::string token;
    size_t index = 0;

    while (std::getline(stream, token, delimiter) && index < N) {
        output[index++] = token;
    }
}
/**
 * @brief Prompts the user to enter a double value
 *
 * @param prompt Optional prompt message to display to the user
 * @return double The double value entered by the user
 */
// gets a number from the user
inline double getDouble(std::string prompt = "") {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}

/**
 * @brief Displays a menu for an office rental system
 *
 * @return int The user's selected option from the menu
 */
inline int displayMenu() {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Office Space Rental System\n";
    std::cout << "[1] Add New Office\n";
    std::cout << "[2] Rent an Office\n";
    std::cout << "[3] Return an Office\n";
    std::cout << "[4] Show Office Details\n";
    std::cout << "[5] Display All Offices\n";
    std::cout << "[6] Check Office Availability\n";
    std::cout << "[7] Show Rented Office\n";
    std::cout << "[8] Client Maintenance\n";
    std::cout << "[9] Exit\n";
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    return 0;
}

inline int displayMenu2() {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "\nClient Maintenance\n";
    std::cout << "[1] Add New Client\n";
    std::cout << "[2] Show Client Details\n";
    std::cout << "[3] List of Videos Rented by a Customer\n";
    std::cout << "[4] Go back\n";
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    return 0;
}

inline int password() {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "In order to proceed. ";
    std::cout << "Enter password: \n";
    int password;
    std::cin >> password;
    if (password == 0000)
        return 1;
    else
        return -1;
}

#endif  // UTILS_H