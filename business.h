#ifndef BUSINESS_H_
#define BUSINESS_H_

#include <string>
#include <vector>
#include "product.h"

using namespace std;

struct productForSale {
	product product;
	long price;
	int numberAvailable;
};

class business {
	protected: 
		vector<productForSale>* catalogue;
	public:
		string name;
		long money = 0;

		business();

		// Returns a vector of all products that this business has for sale
		vector<productForSale>* getCatalogue();

		// Check if there's stock, return false if there's none
		// otherwise process the purchase
		bool processPurchase(productForSale product);
		void addProduct(productForSale product);
};

#endif