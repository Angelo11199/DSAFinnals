#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief Splits a string into parts based on a delimiter
 *
 * @param data The string to be split
 * @param delimiter The character to split the string by
 * @return std::vector<std::string> Vector of strings containing the split parts
 */
// Definition of splitData function
inline std::vector<std::string> splitData(const std::string& data, char delimiter) {
    std::vector<std::string> result;
    std::stringstream dataStream(data);
    std::string piece;

    while (std::getline(dataStream, piece, delimiter)) {
        result.push_back(piece);
    }

    return result;
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
    std::cout << "[6] Add New Client\n";
    std::cout << "[7] Show Client Details\n";
    std::cout << "[8] Exit\n";
    std::cout << "Choose an option: ";
    return 0;
}
#endif  // UTILS_H