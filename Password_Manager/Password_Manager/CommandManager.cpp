#include "CommandManager.h"
#include <vector>
#include "Utils.h"

void CommandManager::registerCommand(const std::string& name, Command* command)
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

	Command* cmd = *(commands.get(line[0]));

	cmd->execute(args);
}

CommandManager::~CommandManager()
{
	for (auto& entry : commands) {
		delete entry.value;
	}
}
