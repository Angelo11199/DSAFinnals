#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

    template <typename T, typename... Args>
    void writeToFileHelper(std::ofstream& file, const T& first, const Args&... args) {
        file << first;
        if constexpr (sizeof...(args) > 0) {
            file << ", ";
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

    /**
     * @brief Destructor to clean up resources associated with the file handler
     *
     */
    ~fileHandling();

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

    template <typename... Args>
    void writeToFile(const Args&... args) {
        std::ofstream file(filename, std::ios::app);  // Open file once
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }
        writeToFileHelper(file, args...);  // Start the recursive writing with the file stream
        file.close();                      // Close file after all writing is done
    }

    std::vector<std::string> readFromFile() {
        std::vector<std::string> data;
        std::ifstream file;
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return data;
        }
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
        file.close();
        return data;
    };
};

#endif
