#include "business.h"

#include <iostream>
using namespace std;

vector<productForSale> business::getCatalogue() {
	return catalogue;
}

void business::addProduct(productForSale product) {
	catalogue.push_back(product);
}

bool business::processPurchase(productForSale product) {
	// find the product in the catalogue and subtract 1 from the inventory
	for (int i = 0; i < catalogue.size(); i++) {
		if (product.product.name == catalogue.at(i).product.name) {
			if (catalogue.at(i).numberAvailable == 0) {
				return false;
			}
			catalogue.at(i).numberAvailable--;
			cout << "na " << catalogue.at(i).numberAvailable << endl;
			break;
		}
	}

	return true;
}