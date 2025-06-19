#include "PassFileManager.h"
#include "IOManager.h"
#include "CipherFactory.h"

PassFileManager* PassFileManager::getInstance() {
	static PassFileManager instance;
	return &instance;
}

void PassFileManager::openFile(const std::string& path)
{	
	std::string encrypted = IOManager::getInstance()->loadFile(path);
	std::string plain = fileEncryptor->decryptFile(encrypted);
	currentFile = new PasswordFile();
	currentFile->deserialize(path, plain);

}

void PassFileManager::setFile(PasswordFile* passFile)
{
	currentFile = passFile;
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
	delete currentFile;
	currentFile = nullptr;

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
