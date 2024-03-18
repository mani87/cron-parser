#include <cassert>
#include "../service/CronParser.h"
#include "../service/IDescriptor.h"
#include "../service/Descriptor.h"
#include "../utils/StringUtil.h"


using namespace std;


void testValidCronExpression() {
    string cex = "*/15 0 1,15 * 1-5 /usr/bin/find";

    CronParser cronParser;
    ICronParser* parser = &cronParser;
    CronExpression cronEx = parser->parse(cex);

    assert(cronEx.getMinute() == "*/15");
    assert(cronEx.getHour() == "0");
    assert(cronEx.getDayOfMonth() == "1,15");
    assert(cronEx.getMonth() == "*");
    assert(cronEx.getDayOfWeek() == "1-5");
    assert(cronEx.getCommand() == "/usr/bin/find");
}


void testInvalidCronExpression() {
    bool exThrown = false;
    try {
        string cex = "*/ab 0 1,15 * 1-5 /usr/bin/find";

        CronParser cronParser;
        ICronParser* parser = &cronParser;
        CronExpression cronEx = parser->parse(cex);

        Descriptor descriptor;
        IDescriptor* desc = &descriptor;

    	string minDesc = desc->describe(cronEx.getMinute(), 60);

	} catch (exception& ex) {
		exThrown = true;
	}

	assert(exThrown);
}


void testValidCronExpressionDescription() {
    string cex = "*/15 0 1,15 * 1-5 /usr/bin/find";

    CronParser cronParser;
    ICronParser* parser = &cronParser;
    CronExpression cronEx = parser->parse(cex);

    Descriptor descriptor;
    IDescriptor* desc = &descriptor;

    string minDesc = desc->describe(cronEx.getMinute(), 60);

    assert(minDesc == "0 15 30 45 ");
}


int main() { 
	int totalTests = 3;
	int passedTests = 0;

	testValidCronExpression();
	passedTests++;
	testValidCronExpressionDescription();
	passedTests++;
	testInvalidCronExpression();
	passedTests++;

	cout << passedTests << "/" << totalTests << " test cases passed." << endl;
	cout << totalTests - passedTests << "/" << totalTests << " test cases failed." << endl;
	
	return 0; 
}
