#include "economy.h"
#include <random>

namespace economy {
	vector<item> items;
	vector<business> businesses;
	vector<person> people;
	vector<house> houses;

	// anything needed to occur before any simulation takes place
	void initialize() {
		// Initialize each person
		for (int p = 0; p < people.size(); p++) {
			people.at(p).create();
		}

		// Initialize each house
		for (int h = 0; h < people.size(); h++) {
			people.at(h).create();
		}
	}

	void simulate() {

	}

	// Adds an item ensuring it doesn't already exist
	int addItem(item i) {
		for (int t = 0; t < items.size(); t++) {
			if (i.name == items.at(t).name) {
				return -1;
			}
		}
		items.push_back(i);
		return 0;
	}
}