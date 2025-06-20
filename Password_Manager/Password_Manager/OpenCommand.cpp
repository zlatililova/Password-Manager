#include "OpenCommand.h"
#include "IOManager.h"
#include "PassFileManager.h"



bool OpenCommand::checkPassword(const std::string& pass, const std::string& readPass)
{
	return pass == readPass;
}

PasswordFile* OpenCommand::openFile(const std::string& path, const std::string& password) {

	std::string pass = PassFileManager::getInstance()->getFilePassword(path);

	if (!checkPassword(pass, password)) {
		throw std::runtime_error("Incorrect password! Cannot open the file");
	}

	PassFileManager::getInstance()->openFile(path);
}

void OpenCommand::execute(const std::vector<std::string>args) {
	
	if (args.size() < 2) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	openFile(args[0], args[1]);
}
