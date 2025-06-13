#include "CeasarCipher.h"

namespace Constants {
	const unsigned ALPHABET_LEN = 26;
};

CeasarCipher::CeasarCipher(int shift)
{
	this->shift = shift;
}

std::string CeasarCipher::encrypt(std::string& key)
{
	std::string res = key;
	for (int i = 0; i < key.size(); i++) {
		res.at(i) = (key[i] + shift) % Constants::ALPHABET_LEN;
	}

	return res;
}

std::string CeasarCipher::decrypt(std::string& key)
{
	std::string res;
	for (int i = 0; i < key.size(); i++) {
		res.at(i) = (key[i] - shift) % Constants::ALPHABET_LEN;
	}

	return res;
}
