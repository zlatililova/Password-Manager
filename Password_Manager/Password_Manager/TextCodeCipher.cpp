#include "TextCodeCipher.h"

TextCodeCipher::TextCodeCipher(std::string text) : text(text) {
	populateMap();
}

std::string TextCodeCipher::encrypt(const std::string& key) {}
std::string TextCodeCipher::decrypt(const std::string& key) {}
std::string TextCodeCipher::getName() {}

void TextCodeCipher::populateMap() {}