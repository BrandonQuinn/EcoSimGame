#include "person.h"
#include <iterator>

#include <iostream>
using namespace std;

/*
	Iterator through the hashmap of products the person has
	and find the product given by the parameter, return it.
*/
storedProduct* person::findProduct(product product) {
	storedProduct *storedProduct = NULL;

	// get iterator for items
	auto iterator = storedProducts.find(product.name);
	
	while (iterator != storedProducts.end()) {
		if (iterator->second.product.name == product.name) {
			storedProduct = &(iterator->second);
		}
		iterator++;
	}
	return storedProduct;
}

/*
	Add the product to the persons stored products.
*/
void person::buyItem(productForSale itemForSale) {
	storedProduct newPurchase;
	newPurchase.product = itemForSale.product;
	newPurchase.productAge = 0;
	storedProducts.insert({newPurchase.product.name, newPurchase});
	money -= itemForSale.price;
}

/* 
	Find the element in the map, if not return or the age of the
	successfully found product is greater than it's like, then the product needs to be
	purchased.
*/
bool person::requiresProduct(product product) {
	if (findProduct(product) == NULL || findProduct(product)->productAge >= product.life) {
		return true;
	}

	return false;
}

/*
	Each person will go through each of the products 
	in the list to purcahse and work out if they
	don't have it or it's expired, past it's life expectancy 
	and purchase the product.
*/
void person::goToMarket(vector<business>* businesses) {
	// go through each business and see what they have for sale, 
	//  if you don't have an item, determine if the person 'wants' to purchase it
	
	for (int b = 0; b < businesses->size(); b++) {
	   vector<productForSale>* catalogue = businesses->at(b).getCatalogue();

	   // go through the catalogue
		for (int c = 0; c < catalogue->size(); c++) {
			if (requiresProduct(catalogue->at(c).product)) {
			
				// process the purchase on the business end,
				// then if there's stock and the business allows the purchase, 
				// process on the customer/person end
				bool hadStock = businesses->at(b).processPurchase(catalogue->at(c));
				if (hadStock) {
					buyItem(catalogue->at(c));
				} else {
					// cout << businesses.at(b).name << " has run out of: " << catalogue->at(c).product.name << endl;
				}
			}
		}
	}
}