#include "CeasarCipher.h"

namespace Constants {
	const unsigned ALPHABET_LEN = 26;
};

static bool isUpper(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

static bool isLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}

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
			res[i] = 'A' + (key[i] - 'A' - shift) % Constants::ALPHABET_LEN;
		}
		else if (isLower(key[i])) {
			res[i] = 'a' + (key[i] - 'a' - shift) % Constants::ALPHABET_LEN;
		};
	}

	return res;
}

std::string CeasarCipher::getName()
{
	return "CC";
}
