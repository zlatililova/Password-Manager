#include "DeleteCommand.h"
#include "PassFileManager.h"

void DeleteCommand::execute(const std::vector<std::string> args)
{
	if (args.size() < 1) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	if (!PassFileManager::getInstance()->hasOpenFile()) {
		throw std::runtime_error("There is no file opened!");
	}

	if (args.size() == 1) {
		PassFileManager::getInstance()->getFile()->deleteAllPasswords(args[0]);
	}
	else if (args.size() == 2) {
		PassFileManager::getInstance()->getFile()->deletePassword(args[0], args[1]);
	}

}