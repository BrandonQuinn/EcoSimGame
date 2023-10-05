#include "economy.h"

namespace economy {
	vector<item> *items;
	vector<business> *businesses = new vector<business>();

	// Linear search for the business by name, assigned the reference to the second parameter
	int findBusinessByReference(string businessName, business* businessReference) {
		for (int i = 0; i < businesses->size(); i++) {
			if (businessName == businesses->at(i).name) {
				businessReference = &businesses->at(i);
				return 0;
			}
		}

		return -1;
	}
}