#pragma once
#include "Command.h"

class LoadCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

