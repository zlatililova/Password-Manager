#pragma once
#include <string>
#include <vector>
#include "MyMap.hpp"
#include "WebsiteEntity.h"
#include "Cipher.h"

class PasswordFile
{
public:
    PasswordFile(const std::string& name, const std::string& password, Cipher* cipher);

    void saveToFile() const;
    void loadFromFile();

    bool savePassword(const std::string& site, const std::string& user, const std::string& pass);
    std::string loadPassword(const std::string& site, const std::string& user = "");
    bool updatePassword(const std::string& site, const std::string& user, const std::string& newPass);
    bool deletePassword(const std::string& site, const std::string& user = "");

private:
    std::string fileName;
    std::string configPassword;
    Cipher* cipher;

    MyMap<std::string, std::vector<WebsiteEntity>> entries;
};

