#include "PassFileManager.h"
#include "IOManager.h"
#include "CipherFactory.h"

PassFileManager* PassFileManager::getInstance() {
	static PassFileManager instance;
	return &instance;
}

void PassFileManager::openFile(const std::string& path, const std::string& password)
{	
	std::string encrypted = IOManager::getInstance()->loadFile(path);
	std::string plain = fileEncryptor->decryptFile(encrypted);
	
	currentFile = new PasswordFile();
	currentFile->deserialize(path, plain);

	if (password != currentFile->getConfigPassword()) {
		throw std::runtime_error("Incorrect password! Cannot open the file");
	}

}

void PassFileManager::createFile(const std::string& path, const std::string& cipherName, const std::vector<std::string>& args, const std::string& pass)
{
	Cipher* cipher = CipherFactory::createInstance(cipherName, args);
	currentFile = new PasswordFile(path, cipher, pass);

}

PasswordFile* PassFileManager::getFile()
{
	return currentFile;
}

void PassFileManager::closeFile()
{
	std::string plainText = currentFile->serialize();
	std::string encrypted = fileEncryptor->encryptFile(plainText);
	IOManager::getInstance()->saveFile(currentFile->getFilePath(), encrypted);

}

bool PassFileManager::hasOpenFile() const
{
	return currentFile != nullptr;
}

PassFileManager::~PassFileManager()
{
	if (hasOpenFile()) {
		closeFile();
	}
	delete fileEncryptor;
}

PassFileManager::PassFileManager(): currentFile(nullptr), fileEncryptor(nullptr)
{
	fileEncryptor = new FileEncryptor();
}
