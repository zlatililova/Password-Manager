#pragma once
#include "Command.h"
class SaveCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

