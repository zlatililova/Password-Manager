#include "CloseCommand.h"
#include "PassFileManager.h"

void CloseCommand::execute(const std::vector<std::string> args)
{
	if (!PassFileManager::getInstance()->hasOpenFile()) {
		throw std::runtime_error("There is no file opened!");
	}


	PassFileManager::getInstance()->closeFile();

}