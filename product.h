#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

using namespace std;

class product {
	public:
		string name;
		long costToMake;
		int life;
		double failureChance;
		double chanceOfRandomDisposal;
};

#endif