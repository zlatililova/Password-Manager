#include "IOManager.h"
#include <fstream>


IOManager* IOManager::getInstance() {
    static IOManager instance;
    return &instance;
}


std::string IOManager::loadFile(const std::string& path, Cipher* fileCipher)
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

    return fileCipher->decrypt(encrypted);
}

void IOManager::saveFile(const std::string& path, const std::string& content, Cipher* fileCipher)
{
    std::ofstream ofs(path);
    if (!ofs) {
        throw std::runtime_error("Could not open file for writing");
    }

    std::string encrypted = fileCipher->encrypt(content);
    ofs << encrypted;
    ofs.close();
}

