#include "FileHandling.h"

#include <fstream>

fileHandling::fileHandling(std::string filename) {
    this->filename = filename;
}
// todo : returns, a vector of data that was read in csv file. Check if tampered, if yes, return an error and throw an exception error.
