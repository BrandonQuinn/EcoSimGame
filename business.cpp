#include "business.h"

#include <iostream>
using namespace std;

business::business() {
	catalogue = new vector<productForSale>();
}

vector<productForSale>* business::getCatalogue() {
	return catalogue;
}

void business::addProduct(productForSale product) {
	catalogue->push_back(product);
}

bool business::processPurchase(productForSale product) {
	// find the product in the catalogue and subtract 1 from the inventory
	for (int i = 0; i < catalogue->size(); i++) {
		if (product.product.name == catalogue->at(i).product.name) {

			// no stock left
			if (catalogue->at(i).numberAvailable == 0) {
				return false;
			}

			// process purchase
			catalogue->at(i).numberAvailable--;
			money += (product.price - product.product.costToMake);
			break;
		}
	}

	return true;
}