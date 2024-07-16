#ifndef FILEHANDLING_CPP
#define FILEHANDLING_CPP
#include "./FileHandling.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
fileHandling::fileHandling(std::string filename) {
    this->filename = filename;
}
fileHandling::~fileHandling() {
    return;
}

#endif
