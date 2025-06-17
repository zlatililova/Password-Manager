#pragma once
#include "PasswordFile.h"

class PassFileManager
{
public:
    static PassFileManager* getInstance();
    void setFile(PasswordFile* file);
    PasswordFile* getFile();
    void clearFile();
    bool hasOpenFile() const;

private:
    PassFileManager();
    PassFileManager(const PassFileManager&) = delete;
    PassFileManager& operator=(const PassFileManager&) = delete;

    PasswordFile* currentFile = nullptr;

};

