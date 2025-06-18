#pragma once
#include "PasswordFile.h"
#include "FileEncryptor.h"

class PassFileManager
{
public:
    static PassFileManager* getInstance();
    void openFile(std::string& path, std::string& password);
    void createFile(std::string& path, std::string& cipherName, std::vector<std::string>& args, std::string& pass);
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

