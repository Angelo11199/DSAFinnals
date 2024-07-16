#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <vector>

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

#endif  // UTILS_H