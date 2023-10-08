#include "business.h"

vector<productForSale> business::getCatalogue() {
    return catalogue;
}

void business::addProduct(productForSale product) {
    catalogue.push_back(product);
}

void business::processPurchase(productForSale product) {
    
}