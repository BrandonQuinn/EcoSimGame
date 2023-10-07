#include "economy.h"

namespace economy {
	vector<item> *items;
	vector<business> *businesses = new vector<business>();

	// Adds an item ensuring it doesn't already exist
	int addItem(item i) {
		for (int t = 0; t < items->size(); t++) {
			if (i.name == items->at(t).name) {
				return -1;
			}
		}
		items->push_back(i);
		return 0;
	}
}