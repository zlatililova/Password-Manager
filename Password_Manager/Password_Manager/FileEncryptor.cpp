#include "FileEncryptor.h"
#include "CeasarCipher.h"


FileEncryptor::FileEncryptor() : cipher(nullptr)
{
	cipher = new CeasarCipher(0);
}

FileEncryptor::~FileEncryptor()
{
	delete cipher;
}

std::string FileEncryptor::encryptFile(const std::string& plainText)
{
	return cipher->encrypt(plainText);
}

std::string FileEncryptor::decryptFile(const std::string& encryptedText)
{
	return cipher->decrypt(encryptedText);
}
