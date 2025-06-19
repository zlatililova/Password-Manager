#include "IOManager.h"
#include <fstream>


IOManager* IOManager::getInstance() {
    static IOManager instance;
    return &instance;
}


std::string IOManager::loadFile(const std::string& path)
{
    std::ifstream ifs(path);
    if (!ifs) {
        throw std::runtime_error("Could not open file for reading");
    }
    std::string encrypted, line;
    while (std::getline(ifs, line)) {
        encrypted += line + '\n';
    }
    ifs.close();

    return encrypted;
}

void IOManager::saveFile(const std::string& path, const std::string& content)
{
    std::ofstream ofs(path);
    if (!ofs) {
        throw std::runtime_error("Could not open file for writing");
    }

    
    ofs << content;
    ofs.close();
}

std::string IOManager::readLine(const std::string& path)
{

    std::ifstream ifs(path);
    if (!ifs) {
        throw std::runtime_error("Could not open file for reading");
    }
    std::string line;
    std::getline(ifs, line);
    ifs.close();

    return line;
}

