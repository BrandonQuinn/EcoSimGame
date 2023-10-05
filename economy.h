#ifndef ECONOMY_H_
#define ECONOMY_H_

#include "sim/item.h"
#include "sim/business.h"
#include <vector>

using namespace std;

namespace economy {
	extern vector<item> *items;
	extern vector<business> *businesses;
	int findBusinessByReference(string businessName, business* businessReference);
}

#endif