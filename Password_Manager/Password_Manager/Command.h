#pragma once
#include <vector>
#include <string>

class Command
{
public:
	virtual void execute(const std::vector<std::string>args) = 0;
	virtual ~Command() = default;
};

