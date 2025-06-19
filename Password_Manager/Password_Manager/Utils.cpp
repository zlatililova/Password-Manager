#include "Utils.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool isValidNumber(const std::string& s) {
	if (!isDigit(s[0]) && s[0] != '-')
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

std::string IntToString(int num)
{
		if (num == 0) {
			return "0";
		}

		bool isNegative = false;
		if (num < 0) {
			isNegative = true;
			num = -num;
		}

		char buffer[20];
		int i = 0;

		while (num > 0) {
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}

		if (isNegative) {
			buffer[i++] = '-';
		}

		buffer[i] = '\0';

		
		int start = 0;
		int end = i - 1;
		if (isNegative) {
			start = 1;
		}
		while (start < end) {
			char temp = buffer[start];
			buffer[start] = buffer[end];
			buffer[end] = temp;
			start++;
			end--;
		}

		return std::string(buffer);
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

std::vector<std::string> parseVector(const std::string& data) {
	std::stringstream s(data);
	std::string curr;
	std::vector<std::string> res;
	try {
		while (std::getline(s, curr, ',')) {
			res.push_back(curr);
		}
	}
	catch (std::exception& e) {
		std::cerr << "Error when parsing encoded string: " << e.what() << std::endl;
	}

	return res;
}

std::vector<std::string> splitString(const std::string& data) {
	std::stringstream s(data);
	std::string curr;
	std::vector<std::string> res;
	try {
		while (std::getline(s, curr, ' ')) {
			res.push_back(curr);
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


int gcd(int a, int b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

int modInverse(int a, int m) {
	a = a % m;
	for (int x = 1; x < m; x++) {
		if ((a * x) % m == 1) {
			return x;
		}
	}
	return -1;
}

bool isUpper(char ch) {
	return ch >= 'A' && ch <= 'Z';
}
char toUpper(char ch) {
	if (isUpper(ch))
		return ch;

	return ch - 'a' + 'A';
}

bool isLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}
int charToInt(char c) {
	return toUpper(c) - 'A';
}

char intToChar(int i) {
	return (char)('A' + i);
}