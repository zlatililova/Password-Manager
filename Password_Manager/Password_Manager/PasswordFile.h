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

    void savePassword(const std::string& site, const std::string& user, const std::string& pass);
    const std::string loadPassword(const std::string& site, const std::string& user) const ;
    const std::vector<WebsiteEntity> loadAllPasswords(const std::string& site) const;
    void updatePassword(const std::string& site, const std::string& user, const std::string& newPass);
    void deletePassword(const std::string& site, const std::string& user);
    void deleteAllPasswords(const std::string& site);

    void deserialize(const std::string& path, const std::string& plainText);
    std::string serialize();

    std::string getFilePath() const;

private:
    void fillInPassword(const std::string& site, const std::string& user, const std::string& pass);

    std::string filePath;
    std::string configPassword;
    Cipher* cipher;

    MyMap<std::string, std::vector<WebsiteEntity>> entries;
};

