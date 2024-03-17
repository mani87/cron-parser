#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <string>

using namespace std;

class IDescriptor {
public:
	virtual string describe(string expression, int limit) const = 0;
};

#endif // DESCRIPTOR_H