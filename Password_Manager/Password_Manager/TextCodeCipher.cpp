#include "TextCodeCipher.h"
#include <vector>
#include "Utils.h"

TextCodeCipher::TextCodeCipher(std::string text) : text(text) {
	populateMap();
}

std::string TextCodeCipher::encrypt(const std::string& key) {
	std::vector<int>res;

	for (int i = 0; i < key.size(); i++) {
		int* code = textCode.get(key[i]);
		res.push_back(*code);
	}
	return encodeInts(res);
}

std::string TextCodeCipher::decrypt(const std::string& key) {
	std::vector<int> keyVector = parseInts(key);
	std::string res;
	for (int i = 0; i < keyVector.size(); i++) {
		char curr = textCode.getByValue(keyVector[i]);
		res += curr;
	}

	return res;
}
std::string TextCodeCipher::getName() {
	return "TCC";
}

void TextCodeCipher::populateMap() {
	for (int i = 0; i < text.size(); i++) {
		if (!textCode.contains(text[i])) {
			textCode.insert(text[i], i);
		}
	}
}