#include "IDescriptor.h"
#include "../utils/StringUtil.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

class Descriptor : public IDescriptor {

public:
	string describe(string expression, int limit) const {

		if (expression == "*") {
			return StringUtil::getRange(1, limit);
		}

		if (StringUtil::isNumber(expression)) {
			return expression;
		} 

		if (StringUtil::contains(expression, '-')) {
			vector<string> tokens = StringUtil::tokenize(expression, '-');
			return StringUtil::getRange(stoi(tokens[0]), stoi(tokens[1]));
		}

		if (StringUtil::contains(expression, ',')) {
			vector<string> tokens = StringUtil::tokenize(expression, ',');
			return StringUtil::toString(tokens);
		}

		if (StringUtil::contains(expression, "*/")) {
			int step = stoi(expression.substr(expression.find('/')+1));
			return this->stepRange(step, limit);
		}
		
		return expression;
	}

private:
	string stepRange(int step, int limit) const {
		string output = "";
		int start = 0;
		while (start < limit) {
			output += (to_string(start) + " ");
			start+=step;
		}
		return output;
	}
};
