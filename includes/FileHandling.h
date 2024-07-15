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
        init();
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

    vector<string> readFromFile() {
        vector<string> data;
        string line;
        inFile.open(filename);
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                data.push_back(line);
            }
        } else {
            cerr << "Unable to open file for reading: " << filename << endl;
        }
        inFile.close();
        return data;
    }

    bool init() {
        outFile.open(filename);
        if (!outFile.is_open()) {
            cerr << "Unable to create file: " << filename << endl;
        }
        outFile.close();
    }
};

#endif
