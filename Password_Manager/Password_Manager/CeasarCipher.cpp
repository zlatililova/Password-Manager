#include "CeasarCipher.h"
#include "Utils.h"

namespace Constants {
	const unsigned ALPHABET_LEN = 26;
	const unsigned MOD = 26;
};



CeasarCipher::CeasarCipher(int shift) : shift(shift) {}

std::string CeasarCipher::encrypt(const std::string& key)
{
	std::string res(key);
	for (int i = 0; i < key.size(); i++) {
		if (isUpper(key[i])) {
			res[i] = 'A' + (key[i] - 'A' + shift) % Constants::ALPHABET_LEN;
		}
		else if (isLower(key[i])) {
			res[i] = 'a' + (key[i] - 'a' + shift) % Constants::ALPHABET_LEN;
		};
	}

	return res;
}

std::string CeasarCipher::decrypt(const std::string& key)
{
	std::string res(key);
	for (int i = 0; i < key.size(); i++) {
		if (isUpper(key[i])) {
			char ch = key[i] - shift;
			if (ch < 'A')
				ch = ch + 'Z' - 'A' + 1;
			res[i] = ch;
		}
		else if (isLower(key[i])) {
			char ch = key[i] - shift;
			if (ch < 'a')
				ch = ch + 'z' - 'a' + 1;
			res[i] = ch;
		};
	}

	return res;
}

std::string CeasarCipher::getName()
{
	return "CC";
}

std::string CeasarCipher::getConfig()
{
	return IntToString(shift);
}
