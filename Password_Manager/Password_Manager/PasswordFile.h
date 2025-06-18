#pragma once
#include <string>
#include <vector>
#include "MyMap.hpp"
#include "WebsiteEntity.h"
#include "Cipher.h"

class PasswordFile
{
public:
    PasswordFile(const std::string& name, Cipher* cipher, const std::string& password);
    PasswordFile();
    ~PasswordFile();

    bool savePassword(const std::string& site, const std::string& user, const std::string& pass);
    std::string loadPassword(const std::string& site, const std::string& user = "");
    bool updatePassword(const std::string& site, const std::string& user, const std::string& newPass);
    bool deletePassword(const std::string& site, const std::string& user = "");

    void deserialize(std::string& path, std::string& plainText);
    std::string serialize();

    std::string getConfigPassword() const;
    std::string getFilePath() const;

private:
    std::string filePath;
    std::string configPassword;
    Cipher* cipher;

    MyMap<std::string, std::vector<WebsiteEntity>> entries;
};

