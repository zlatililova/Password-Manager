#pragma once
#include <string>
#include "Cipher.h"

class IOManager {
public:
    static IOManager* getInstance();
    std::string loadFile(const std::string& path, Cipher* cipher);
    void saveFile(const std::string& path, const std::string& content, Cipher* cipher);

private:
    IOManager() = default;
    IOManager(const IOManager&) = delete;
    IOManager& operator=(const IOManager&) = delete;
};

