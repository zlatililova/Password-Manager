#pragma once
#include "Command.h"
#include "PasswordFile.h"


class OpenCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;
private:
	std::string readFilePassword(const std::string& filename);
	bool checkPassword(const std::string& pass, const std::string& readPass);
	PasswordFile* openFile(const std::string& path, const std::string& password);
};

