#pragma once
#include <string>
#include "MyMap.hpp"
#include "Command.h"


class CommandManager
{
public:
    void registerCommand(const std::string& name, Command* command);
    void executeCommand(const std::string& inputLine);
    ~CommandManager();
private:
    MyMap<std::string, Command*> commands;

};

