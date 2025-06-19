#pragma once
#include <string>
#include <vector>

int stringToInt(const std::string& s);
std::string IntToString(int num);


bool isUpper(char ch);
char toUpper(char ch);

bool isLower(char ch);
int charToInt(char c);
char intToChar(int i);

std::vector<int> parseInts(const std::string& data);
std::vector<std::string> parseVector(const std::string& data);
std::string encodeInts(const std::vector<int>& data);
std::vector<std::string> splitString(const std::string& data);

int gcd(int a, int b);
int modInverse(int a, int m);