#include "Utils.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool isValidNumber(const std::string& s) {
	if (!isDigit(s[0]) || s[0] != '-')
		return false;
	for (int i = 1; i < s.size(); i++) {
		if (!isDigit(s[i])) {
			return false;
		}
	}

	return true;
}

int stringToInt(const std::string& s) {
	int result = 0;

	if (!isValidNumber(s)) {
		throw std::invalid_argument("The string is not a valid num!");
	}

	for (int i = 0; i < s.length(); ++i) {
		if (isDigit(s[i])) {
			result = result * 10 + (s[i] - '0');
		}
	}
	return result;
}

std::vector<int> parseInts(const std::string& data) {
	std::stringstream s(data);
	std::string curr;
	std::vector<int> res;
	try {
		while (std::getline(s, curr, ',')) {
			res.push_back(stringToInt(curr));
		}
	}
	catch (std::exception& e) {
		std::cerr << "Error when parsing encoded string: " << e.what() << std::endl;
	}

	return res;
}

std::string encodeInts(const std::vector<int>& data) {
	std::string res;

	for (size_t i = 0; i < data.size(); i++) {
		res += std::to_string(data[i]);
		if (i < data.size() - 1) {
			res += ",";
		}
	}
	return res;
}