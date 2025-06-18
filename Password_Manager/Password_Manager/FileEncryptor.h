#pragma once
#include <string>
#include "Cipher.h"

class FileEncryptor
{
public:
	FileEncryptor();
	~FileEncryptor();
	FileEncryptor(const FileEncryptor&) = delete;
	FileEncryptor& operator=(const FileEncryptor&) = delete;

	std::string encryptFile(const std::string& plainText);
	std::string decryptFile(const std::string& encryptedText);

private:
	Cipher* cipher = nullptr;
};

