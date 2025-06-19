#pragma once
#include <string>
#include "MyMap.hpp"
#include "Command.h"


class CommandManager
{
public:
    static CommandManager* getInstance();
    void registerCommand(const std::string& name, std::shared_ptr <Command> command);
    void executeCommand(const std::string& inputLine);
private:
    CommandManager();
    MyMap<std::string, std::shared_ptr <Command>> commands;

};

