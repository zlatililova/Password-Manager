#pragma once
#include "Cipher.h"
#include "MyMap.hpp"

class TextCodeCipher : public Cipher
{
public:
	TextCodeCipher(std::string text);
	std::string encrypt(const std::string& key) override;
	std::string decrypt(const std::string& key) override;
	std::string getName() override;

private:
	void populateMap();
	std::string text;
	MyMap<char, int> textCode;
};

