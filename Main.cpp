#include "service/CronExpression.h"
#include "service/ICronParser.h"
#include "service/IDescriptor.h"
#include "service/Descriptor.h"
#include "service/CronParser.h"
#include "config/Config.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

vector<pair<string, string> > getDescriptions(CronExpression cronEx) {
    Descriptor descriptor;
    IDescriptor* desc = &descriptor;

    vector<pair<string, string> > descriptions;

    descriptions.push_back(make_pair("minutes", desc->describe(cronEx.getMinute(), Config::MAX_MINUTES)));
    descriptions.push_back(make_pair("hour", desc->describe(cronEx.getHour(), Config::MAX_HOURS)));
    descriptions.push_back(make_pair("day of month", desc->describe(cronEx.getDayOfMonth(), Config::MAX_DAY_OF_MONTH)));
    descriptions.push_back(make_pair("month", desc->describe(cronEx.getMonth(), Config::MAX_MONTH)));
    descriptions.push_back(make_pair("day of week", desc->describe(cronEx.getDayOfWeek(), Config::MAX_DAY_OF_WEEK)));
    descriptions.push_back(make_pair("command", cronEx.getCommand()));

    return descriptions;
}

void printCronDescription(vector<pair<string, string> > descriptions) {
    for (int i = 0; i < descriptions.size(); i++) {
        cout << setw(14) << left << descriptions[i].first << descriptions[i].second << endl;
    }
}


int main(int argc, char * argv[]) {

    try {
        string cex = argv[1];

        CronParser cronParser;
        ICronParser* parser = &cronParser;
        CronExpression cronEx = parser->parse(cex);

        vector<pair<string, string> > descriptions = getDescriptions(cronEx);
        printCronDescription(descriptions);
    } catch (exception& e) {
        cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}