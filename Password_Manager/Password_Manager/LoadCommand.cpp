#include "LoadCommand.h"
#include <stdexcept>
#include "PassFileManager.h"


void LoadCommand::execute(const std::vector<std::string> args)
{
	if (args.size() < 1) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	if (!PassFileManager::getInstance()->hasOpenFile()) {
		throw std::runtime_error("There is no file opened!");
	}

	if (args.size() == 1) {
		std::vector<WebsiteEntity> entries = PassFileManager::getInstance()->getFile()->loadAllPasswords(args[0]);

		for (int i = 0; i < entries.size(); i++) {
			std::cout << entries[i].username << ": " << entries[i].password << std::endl;
		}
	}
	else if (args.size() == 2) {
		std::cout << PassFileManager::getInstance()->getFile()->loadPassword(args[0], args[1]);
	}

}