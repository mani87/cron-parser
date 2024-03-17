#ifndef CRONEXPRESSION_H
#define CRONEXPRESSION_H

#include <string>
#include <iostream>

using namespace std;

class CronExpression {

private:
	string minute;
	string hour;
	string dayOfMonth;
	string month;
	string dayOfWeek;
	string command;

public:
	CronExpression(string min, string hr, string dom, string m, string dow, string c): minute(min), hour(hr), dayOfMonth(dom), month(m), dayOfWeek(dow), command(c) {};

	string getMinute() {
		return minute;
	}

	string getHour() {
		return hour;
	}

	string getDayOfMonth() {
		return dayOfMonth;
	}

	string getMonth() {
		return month;
	}

	string getDayOfWeek() {
		return dayOfWeek;
	}

	string getCommand() {
		return command;
	}

	void setMinute(string min) {
		minute = min;
	}

	void setHour(string hr) {
		hour = hr;
	}

	void setDayOfMonth(string dom) {
		dayOfMonth = dom;
	}

	void setMonth(string m) {
		month = m;
	}

	void setDayOfWeek(string dow) {
		dayOfWeek = dow;
	}

	void setCommand(string c) {
		command = c;
	}
};


#endif // CRONEXPRESSION_H