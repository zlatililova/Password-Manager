#include "SaveCommand.h"
#include <stdexcept>
#include "PassFileManager.h"

void SaveCommand::execute(const std::vector<std::string>args) {
	
	if (args.size() < 3) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	if (!PassFileManager::getInstance()->hasOpenFile()) {
		throw std::runtime_error("There is no file opened!");
	}

	PassFileManager::getInstance()->getFile()->savePassword(args[0], args[1], args[2]);
}