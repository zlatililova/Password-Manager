#include "UpdateCommand.h"
#include "PassFileManager.h"

void UpdateCommand::execute(const std::vector<std::string> args)
{
	if (args.size() < 3) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	if (!PassFileManager::getInstance()->hasOpenFile()) {
		throw std::runtime_error("There is no file opened!");
	}

	
	PassFileManager::getInstance()->getFile()->updatePassword(args[0], args[1], args[2]);

}