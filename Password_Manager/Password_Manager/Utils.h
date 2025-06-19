#pragma once
#include <string>
#include <vector>

int stringToInt(const std::string& s);
std::string IntToString(int num);

std::vector<int> parseInts(const std::string& data);
std::vector<std::string> parseVector(const std::string& data);
std::string encodeInts(const std::vector<int>& data);
std::vector<std::string> splitString(const std::string& data);