#pragma once
#include "Command.h"
class DeleteCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
};

