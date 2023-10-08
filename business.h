#ifndef BUSINESS_H_
#define BUSINESS_H_

#include <string>
#include <vector>
#include "product.h"

using namespace std;

struct productForSale {
	product product;
	double price;
	int numberAvailable;
};

class business {
	protected: 
		vector<productForSale> catalogue;
	public:
		string name;

		// Returns a vector of all products that this business has for sale
		vector<productForSale> getCatalogue();
		void processPurchase(productForSale product);
		void addProduct(productForSale product);
};

#endif