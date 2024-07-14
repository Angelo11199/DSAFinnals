#include <string>
class fileHandling {
   private:
    std::string filename;
    bool init();

   public:
    fileHandling(std::string filename);
    ~fileHandling();
    void writeToFile(std::string data);
};