#pragma once
#include "PasswordFile.h"
#include "FileEncryptor.h"

class PassFileManager
{
public:
    static PassFileManager* getInstance();
    void openFile(const std::string& path, const std::string& password);
    void createFile(const std::string& path, const std::string& cipherName, const std::vector<std::string>& args, const std::string& pass);
    PasswordFile* getFile();
    void closeFile();
    bool hasOpenFile() const;

    ~PassFileManager();

private:
    PassFileManager();
    PassFileManager(const PassFileManager&) = delete;
    PassFileManager& operator=(const PassFileManager&) = delete;


    PasswordFile* currentFile = nullptr;
    FileEncryptor* fileEncryptor = nullptr;

};

