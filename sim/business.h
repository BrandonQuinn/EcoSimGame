#ifndef BUSINESS_H_
#define BUSINESS_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "item.h"

using namespace std;

// Item stored in a businesses inventory for sale
struct inventoriedItem {
	item item;
	double price;
	int count;
};

class business {
	public:
		string name;

		// Used to simulate profits and when adding items to sell, 
		// the business must be able to afford the manufacturing costs
		long money;

		// stores a list of reference to an items in the items list
		vector<item*> productLine;

		// People and households need to find items fast, a hashmap seems reasonable
		unordered_map<string, inventoriedItem> itemsForSale;
};

#endif