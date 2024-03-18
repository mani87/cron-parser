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
			if (stoi(expression) < limit)
				return expression;
			else
				throw invalid_argument("INVALID_EXPRESSION: Invalid expression.");
		} 

		if (StringUtil::contains(expression, '-')) {
			vector<string> tokens = StringUtil::tokenize(expression, '-');

			if (StringUtil::isNumber(tokens[0]) and StringUtil::isNumber(tokens[1])) {
				int start = stoi(tokens[0]);
				int end = stoi(tokens[1]);

				if (start < limit and end < limit) {
					return StringUtil::getRange(stoi(tokens[0]), stoi(tokens[1]));
				} else {
					throw invalid_argument("INVALID_EXPRESSION: Range is out of bound.");
				}
			} else {
				throw invalid_argument("INVALID_EXPRESSION: Range values are not numbers.");
			}
		}

		if (StringUtil::contains(expression, ',')) {
			vector<string> tokens = StringUtil::tokenize(expression, ',');

			for (int i = 0; i < tokens.size(); i++) {
				if (!StringUtil::isNumber(tokens[i])) {
					throw invalid_argument("INVALID_EXPRESSION: Values are not valid numbers");
				}
			}
			return StringUtil::toString(tokens);
		}

		if (StringUtil::contains(expression, "*/")) {
			string step = expression.substr(expression.find('/')+1);

			if (StringUtil::isNumber(step)) {
				return this->stepRange(stoi(step), limit);
			} else {
				throw invalid_argument("INVALID_EXPRESSION: Given step is not a valid number");
			}
		}
		
		throw invalid_argument("INVALID_EXPRESSION: Try again with a valid cron expression.");
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
