#pragma once
#include <vector>
#include "Cipher.h"

class CipherFactory
{
public:
	static Cipher* createInstance(std::string& name, std::vector<std::string>& arg);
};

