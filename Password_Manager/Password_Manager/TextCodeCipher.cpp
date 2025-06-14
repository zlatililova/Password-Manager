#include "TextCodeCipher.h"
#include <vector>
#include <sstream>

TextCodeCipher::TextCodeCipher(std::string text) : text(text) {
	populateMap();
}

static std::string encodeInts(const std::vector<int>& data) {
	std::string res;

	for (size_t i = 0; i < data.size(); i++) {
		res += std::to_string(data[i]);
		if (i < data.size() - 1) {
			res += ",";
		}
	}
	return res;
}

static int stringToInt(const std::string& s) {
	int result = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			result = result * 10 + (s[i] - '0');
		}
	}
	return result;
}

static std::vector<int> parseInts(const std::string& data) {
	std::stringstream s(data);
	std::string curr;
	std::vector<int> res;
	while (std::getline(s, curr, ',')) {
		res.push_back(stringToInt(curr));
	}

	return res;
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