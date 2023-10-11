#ifndef _ECONOMY_H_
#define _ECONOMY_H_

#include "business.h"
#include "person.h"
#include "product.h"
#include <iostream>
#include <vector>

using namespace std;

class economy {
	const int INIT_NUM_PEOPLE = 200;
	
	public:
		int time = 0;

		vector<person>* people = new vector<person>();
		product products[10];
		vector<business>* businesses = new vector<business>();

		void initSampleData(); 
		void simulate();
};

#endif