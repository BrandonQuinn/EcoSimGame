#include "person.h"

void person::create() {
	// Go through each item and determine if the person can buy the product
	for (int i = 0; i < economy::items.size(); i++) {
		// seed with time
		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		// Random number between 0.0 and 1.0
		double percentage = static_cast<double>(std::rand()) / RAND_MAX;
		if (percentage <= economy::items.at(i).personOwnership) {
			inventory.push_back(economy::items.at(i));
		}
	}
}

void person::simulate() {
	
}