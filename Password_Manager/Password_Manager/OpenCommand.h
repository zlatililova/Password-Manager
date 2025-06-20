#pragma once
#include "Command.h"
#include "PasswordFile.h"


class OpenCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
private:
	bool checkPassword(const std::string& pass, const std::string& readPass);
	void openFile(const std::string& path, const std::string& password);
};

