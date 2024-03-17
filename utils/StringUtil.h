#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class StringUtil {
public:
	static vector<string> tokenize(string input, char delimiter);

	static string getRange(int start, int end);

	static string toString(vector<string> items);

	static bool isNumber(string number);

	static bool contains(string input, char key);

	static bool contains(string input, string subpart);
};


#endif // STRING_UTIL_H
