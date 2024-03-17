#ifndef ICRONPARSER_H
#define ICRONPARSER_H

#include "CronExpression.h"
#include <string>

using namespace std;


class ICronParser {
public:
	virtual CronExpression parse(string expression) const = 0;
};


#endif