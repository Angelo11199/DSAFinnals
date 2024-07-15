#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class fileHandling {
   private:
    string filename;
    ofstream outFile;
    ifstream inFile;

   public:
    fileHandling(string filename) {
        this->filename = filename;
        outFile.open(filename);
        if (!outFile.is_open()) {
            cerr << "Unable to create file: " << filename << endl;
        }
        outFile.close();
    };
    ~fileHandling() {
        if (outFile.is_open()) {
            outFile.close();
        }
        if (inFile.is_open()) {
            inFile.close();
        }
    }
    template <typename T, typename... Args>
    void writeToFile(const T& first, const Args&... args) {
        outFile.open(filename, ios::app);
        if (outFile.is_open()) {
            outFile << first << ",";
            if constexpr (sizeof...(args) > 0) {
                outFile << ",";
                writeToFile(args...);
            } else {
                outFile << endl;
            }
        } else {
            cerr << "Unable to open file for writing: " << filename << endl;
        }
        outFile.close();
    }
    std::vector<std::string> fileHandling::readFromFile() {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Error opening file");
        }

        std::vector<std::string> data;
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }

        file.close();

        bool isTampered = false;
        if (isTampered) {
            throw std::runtime_error("File data is tampered");
        }

        return data;
    };
};

#endif
