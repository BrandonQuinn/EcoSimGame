#ifndef ECONOMY_H_
#define ECONOMY_H_

#include "sim/item.h"
#include "sim/business.h"
#include "sim/house.h"
#include "sim/person.h"
#include <vector>

using namespace std;

namespace economy {

	// Limit on the size of the economy
	const int MAX_PEOPLE = 1000;
	const int MAX_BUSINESSES = 100;
	const int MAX_HOUSES = 100;
	const int MAX_ITEMS = 10000;

	// Economic trends

	// Entities in the economy
	extern vector<item> items;
	extern vector<business> businesses;
	extern vector<person> people;
	extern vector<house> houses;

	extern void initialize();
	extern void simulate();
	extern int addItem(item);
}

#endif