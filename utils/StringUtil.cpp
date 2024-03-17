#include "StringUtil.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<string> StringUtil::tokenize(string input, char delimiter) {
	vector<string> tokens;
    istringstream iss(input);
    string token;
    while (getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string StringUtil::getRange(int start, int end) {
	string range = "";
	for (int i = start; i <= end; i++)
		range += (to_string(i) + " ");
	return range;
}

string StringUtil::toString(vector<string> items) {
	string output = "";
	for (int i = 0; i < items.size(); i++)
		output+=(items[i] + " ");
	return output;
}

bool StringUtil::isNumber(string number) {
	return regex_match(number, regex("-?[0-9]+"));
}

bool StringUtil::contains(string value, char key) {
	return value.find(key) != string::npos;
}

bool StringUtil::contains(string value, string subpart) {
	return value.find(subpart) != string::npos;
}