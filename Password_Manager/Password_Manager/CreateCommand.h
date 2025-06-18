#pragma once
#include "Command.h"

class CreateCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

