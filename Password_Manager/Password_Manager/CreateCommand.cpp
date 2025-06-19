#include "CreateCommand.h"
#include "CipherFactory.h"
#include "PassFileManager.h"

void CreateCommand::execute(const std::vector<std::string> args)
{
	if (args.size() < 4) {
		throw std::invalid_argument("Insufficient number of arguments!");
	}

	std::vector<std::string> cipherArgs(args.begin() + 2, args.end() - 1);

	PasswordFile* pFile = createFile(args[0], args[1], cipherArgs, args[args.size() - 1]);

	PassFileManager::getInstance()->setFile(pFile);

}

PasswordFile* CreateCommand::createFile(const std::string& path, const std::string& cipherName, const std::vector<std::string>& args, const std::string& pass)
{
	Cipher* cipher = CipherFactory::createInstance(cipherName, args);
	return new PasswordFile(path, cipher, pass);

}
