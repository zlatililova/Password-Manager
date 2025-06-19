#include "CommandManager.h"
#include <vector>
#include "Utils.h"
#include "CreateCommand.h"
#include "OpenCommand.h"
#include "SaveCommand.h"
#include "LoadCommand.h"
#include "UpdateCommand.h"
#include "DeleteCommand.h"
#include "CloseCommand.h"
#include "CipherFactory.h"

void CommandManager::registerCommand(const std::string& name, std::shared_ptr <Command> command)
{
	commands.insert(name, command);

}

void CommandManager::executeCommand(const std::string& inputLine)
{
	std::vector<std::string> line = splitString(inputLine);
	std::vector<std::string> args(line.begin() + 1, line.end());

	if (!commands.contains(line[0])) {
		throw std::runtime_error("There is no such a command!");
	}

	Command* cmd = commands.get(line[0])->get();

	cmd->execute(args);
}

CommandManager::CommandManager()
{
	registerCommand("create", std::make_shared<CreateCommand>());
	registerCommand("open", std::make_shared<OpenCommand>());
	registerCommand("save", std::make_shared <SaveCommand>());
	registerCommand("load", std::make_shared <LoadCommand>());
	registerCommand("update", std::make_shared <UpdateCommand>());
	registerCommand("delete", std::make_shared <DeleteCommand>());
	registerCommand("close", std::make_shared <CloseCommand>());
}

CommandManager* CommandManager::getInstance() {
	static CommandManager instance;
	return &instance;
}

