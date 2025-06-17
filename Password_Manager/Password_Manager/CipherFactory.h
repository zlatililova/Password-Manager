#pragma once
#include "Cipher.h"

class CipherFactory
{
public:
	static Cipher* createInstance(std::string& name, std::string& arg);
};

