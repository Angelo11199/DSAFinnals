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
    std::cout << "Office Space Rental System\n";
    std::cout << "[1] Add New Office\n";
    std::cout << "[2] Rent an Office\n";
    std::cout << "[3] Return an Office\n";
    std::cout << "[4] Show Office Details\n";
    std::cout << "[5] Display All Offices\n";
    std::cout << "[6] Check Video Availability\n";
    std::cout << "[7] Client Maintenance\n";
    std::cout << "[8] Exit\n";
    std::cout << "Choose an option: ";
    return 0;
}

inline int displayMenu2() {
    std::cout << "Client Maintenance\n";
    std::cout << "[1] Add New Client\n";
    std::cout << "[2] Show Client Details\n";
    std::cout << "[3] List of Videos Rented by a Customer\n";
    std::cout << "[4] Go back\n";
    std::cout << "Choose an option: ";
    return 0;
}
/**
 * @brief Generates and prints random numbers as strings
 *
 * @return int Always returns 0
 */

// inline std::string generateRandomNumber() {
//     srand(time(0));  // Seed the random number generator
//     std::string random_number_str;
//     int digits = 10;  // Number of digits
//     for (int i = 0; i < digits; ++i) {
//         int random_number = rand() % 10;                     // Generate a random number between 0 and 9
//         random_number_str += std::to_string(random_number);  // Append the digit to the string
//     }
//     return random_number_str;
// }

#endif  // UTILS_H