#ifndef CRONPARSER_H
#define CRONPARSER_H

#include "ICronParser.h"
#include "CronExpression.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class CronParser: public ICronParser {
public:
	CronExpression parse(string expression) const {
		
		istringstream strstream(expression);

		string part;

		vector<string> parts;

		while (strstream >> part) {
			parts.push_back(part);
		}

		CronExpression cronEx(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
		return cronEx;
	}
};


#endif // CRONPARSER_H