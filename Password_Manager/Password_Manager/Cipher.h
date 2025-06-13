#pragma once
#include <string>
class Cipher
{
public:
	virtual std::string encrypt(const std::string& key) = 0;
	virtual std::string decrypt(const std::string& key) = 0;
	virtual std::string getName() = 0;
	virtual ~Cipher() = default;
};



