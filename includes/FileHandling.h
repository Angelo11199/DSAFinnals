#include <string>
class fileHandling {
    fileHandling(std::string filename);
    ~fileHandling();
    void writeToFile(std::string data);
    void init();
};