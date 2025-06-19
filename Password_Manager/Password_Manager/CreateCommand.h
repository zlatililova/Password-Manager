#pragma once
#include "Command.h"
#include "PasswordFile.h"

class CreateCommand : public Command
{
public:
	void execute(const std::vector<std::string>args) override;

private:
	PasswordFile* createFile(const std::string& path, const std::string& cipherName, const std::vector<std::string>& args, const std::string& pass);
};

