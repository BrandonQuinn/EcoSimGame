#include "person.h"
#include <iterator>

#include <iostream>
using namespace std;

storedProduct person::findProduct(product product) {
	storedProduct storedProduct;

	// get iterator for items
	auto iterator = storedProducts.find(product.name);
	
	while (iterator != storedProducts.end()) {
		if (iterator->second.product.name == product.name) {
			storedProduct = iterator->second;
		}

		iterator++;
	}

	return storedProduct;
}

void person::buyItem(productForSale itemForSale) {

}

/* 
	find the element in the map, if not return or the age of the
	successfully found product is greater than it's like, then the product needs to be
	purchased
*/
bool person::requiresProduct(product product) {
	if (findProduct(product) == NULL || findProduct(product).productAge >= product.life) {
		return true;
	}

	return false;
}

void person::goToMarket(vector<business> businesses) {
	// go through each business and see what they have for sale, 
	//  if you don't have an item, determine if the person 'wants' to purchase it

	for (int b = 0; b < businesses.size(); b++) {
	   vector<productForSale> catalogue = businesses.at(b).getCatalogue();

	   // go through the catalogue
		for (int c = 0; c < catalogue.size(); c++) {
			if (requiresProduct(catalogue.at(c).product)) {
				buyItem(catalogue.at(c));
				businesses.at(b).processPurchase(catalogue.at(c));
			}
		}
	}
}