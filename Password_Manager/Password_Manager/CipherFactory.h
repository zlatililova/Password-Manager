#pragma once
#include <vector>
#include "Cipher.h"

class CipherFactory
{
public:
	static Cipher* createInstance(const std::string& name, const std::vector<std::string>& arg);
};

