#include "person.h"
#include <iterator>


// TODO: Fix finding products
storedProduct person::findProduct(product product) {
	storedProduct storedProduct;

	// get iterator for items
	iterator iterator = storedProducts.find(product.name);
	
	while (iterator != storedProducts.end()) {
		iterator.next();
	}

	return storedProduct;
}

void person::buyItem(productForSale itemForSale) {

}

bool person::requiresProduct(product product) {

	// find the element in the map, if not found the map
	// return an iterator pointing to the end of the iterator
	if (storedProducts.find(product.name) == storedProducts.end()) {
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