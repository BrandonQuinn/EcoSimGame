#ifndef PERSON_H_
#define PERSON_H_

#include <unordered_map>
#include "business.h"
#include "product.h"

struct storedProduct {
	product product;
	int productAge;
};

class person {
	protected:
		unordered_map<string, storedProduct> storedProducts;
		long money = 0;

	public: 
		void goToMarket(vector<business> businesses);

		// purchase the item
		void buyItem(productForSale itemForSale);

		// check if the person requires the item
		bool requiresProduct(product item);

		// find a product in the map
		storedProduct* findProduct(product product);
};

#endif