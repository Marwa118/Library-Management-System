#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

class FileManager {
public:
    static void saveToFile(const std::string& filename, const std::vector<std::string>& lines);
    static std::vector<std::string> readFromFile(const std::string& filename);
};

#endif
