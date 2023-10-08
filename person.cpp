#include "person.h"

void person::buyItem(productForSale itemForSale) {

}

bool person::requiresItem(product item) {
    return true;
}

void person::goToMarket(vector<business> businesses) {
    // go through each business and see what they have for sale, 
    //  if you don't have an item, determine if the person 'wants' to purchase it

    for (int b = 0; b < businesses.size(); b++) {
       vector<productForSale> catalogue = businesses.at(b).getCatalogue();

       // go through the catalogue
        for (int c = 0; c < catalogue.size(); c++) {
            if (requiresItem(catalogue.at(c).product)) {
                buyItem(catalogue.at(c));
                businesses.at(b).processPurchase(catalogue.at(c));
            }
        }
    }
}