#pragma once
#include "Cipher.h"
#include <string>

class CeasarCipher : public Cipher
{
public:
	CeasarCipher(int shift);
	std::string encrypt(std::string& key) override;
	std::string decrypt(std::string& key) override;
private:
	int shift;
};

