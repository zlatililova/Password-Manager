#pragma once
#include "Command.h"

class CloseCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

