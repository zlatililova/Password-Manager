#pragma once
#include "Command.h"

class UpdateCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

