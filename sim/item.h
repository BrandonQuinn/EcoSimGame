#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class item {
	public:
		string name;
		int manufacturingCost; // in AUD $
		int lifeSpan; // in days
		float failureChance; // per day
		float personOwnership;
		float houseOwnership;
};

#endif