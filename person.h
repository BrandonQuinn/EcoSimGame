#ifndef PERSON_H_
#define PERSON_H_

#include "business.h"
#include "product.h"

class person {
	public: 
		void goToMarket(vector<business> businesses);

		// purchase the item
		void buyItem(productForSale itemForSale);

		// check if the person requires the item
		bool requiresItem(product item);
};

#endif