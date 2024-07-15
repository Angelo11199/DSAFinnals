#include "FileHandling.h"

#include <fstream>

fileHandling::fileHandling(std::string filename) {
    this->filename = filename;
    bool success = init();
    if (!success)
        throw "Error opening file";
}
// todo : returns, a vector of data that was read in csv file. Check if tampered, if yes, return an error and throw an exception error.
bool fileHandling::init() {
    // allow to read and write to file
    std::ofstream file;
    file.open(filename, std::ios::app);
    if (!file) {
        return false;
    }
}