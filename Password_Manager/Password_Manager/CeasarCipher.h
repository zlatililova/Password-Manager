#pragma once
#include "Cipher.h"
#include <string>

class CeasarCipher : public Cipher
{
public:
	CeasarCipher(int shift);
	std::string encrypt(const std::string& key) override;
	std::string decrypt(const std::string& key) override;
	std::string getName() override;
private:
	int shift;
};

