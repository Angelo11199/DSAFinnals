#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "./LinkedList.h"

/**
 * @brief Class for handling file operations such as reading from and writing to files
 *
 */
class fileHandling {
   private:
    std::string filename;
    template <typename T>
    void writeToFileHelper(std::ofstream& file, const T& last) {
        file << last << std::endl;
    }

    /**
     * @brief Helper function to write the last argument to the file
     *
     * @tparam T Type of the last argument
     *
     * @param file Output file stream
     * @param last Last argument to write to the file
     */
    template <typename T, typename... Args>
    void writeToFileHelper(std::ofstream& file, const T& first, const Args&... args) {
        file << first;
        if constexpr (sizeof...(args) > 0) {
            file << ",";
            writeToFileHelper(file, args...);
        } else {
            file << std::endl;
        }
    }

   public:
    /**
     * @brief Constructor to initialize the file handler with a specified filename
     *
     * @param filename Name of the file to be handled
     */
    fileHandling(std::string filename);
    int size;
    /**
     * @brief Destructor to clean up resources associated with the file handler
     *
     */
    ~fileHandling();
    void updateFile(std::string newValue, int id, int column = 0) {
        std::ifstream file;
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        std::ofstream outFile;
        outFile.open(filename);
        if (!outFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        for (size_t i = 0; i < lines.size(); i++) {
            std::string currentLine = lines[i];
            std::string currentId = currentLine.substr(0, currentLine.find(","));
            if (std::stoi(currentId) == id) {
                std::string newLine = currentLine;
                size_t pos = 0;
                for (int j = 0; j < column; j++) {
                    pos = newLine.find(",", pos) + 1;
                }
                newLine.replace(pos, newLine.find(",", pos) - pos, newValue);
                outFile << newLine << std::endl;
            } else {
                outFile << currentLine << std::endl;
            }
        }
        outFile.close();
    }

    void deleteRow(int col, const std::string& value) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            int i;  // Declare i outside the for loop
            for (i = 0; i <= col; ++i) {
                if (!std::getline(ss, cell, ',')) break;  // Handle case where line has fewer columns than expected
            }
            if (i == col && cell == value) continue;  // Skip lines where the specified column matches the value
            lines.push_back(line);
        }
        file.close();

        // Re-open the file in write mode to overwrite it
        std::ofstream outFile(filename, std::ofstream::trunc);
        if (!outFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        for (const auto& filteredLine : lines) {
            outFile << filteredLine << std::endl;
        }
        outFile.close();
    }
    /**
     * @brief Writes data to the file
     *
     * @tparam Type of the last argument to write
     * @param last Last argument to write to the file
     */
    template <typename T>
    void writeToFile(const T& last) {
        std::ofstream file;
        file.open(filename, std::ios::app);
        file << last << std::endl;  // Writes the last (or only) item followed by a newline
        file.close();
    }

    /**
     * @brief Writes multiple arguments to the file
     *
     * @tparam Args Types of the arguments to write
     * @param args Arguments to write to the file
     */
    template <typename... Args>
    void writeToFile(const Args&... args) {
        std::ofstream file(filename, std::ios::app);  // Open file once
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;

            return;
        }
        writeToFileHelper(file, args...);  // Start the recursive writing with the file stream
        file.close();                      // Close file after all writing is done
    }

    /**
     * @brief Reads data from the file into a linked list
     *
     * @return LinkedList<std::string> A linked list containing the data read from the file
     */
    LinkedList<std::string> readFromFile() {
        LinkedList<std::string> data;
        std::ifstream file;
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << filename << std::endl;
            return data;
        }
        std::string line;
        while (std::getline(file, line)) {
            // skip if line is empty
            if (line.empty()) {
                continue;
            }

            data.add(line);  // Assuming LinkedList has a push_back method similar to std::vector
        }
        file.close();
        return data;
    }
};

#endif
