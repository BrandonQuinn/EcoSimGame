#include "main.h"
#include "product.h"
#include "business.h"
#include "person.h"

const int INIT_NUM_PEOPLE = 100;
vector<person> people;
product products[10];
vector<business> businesses;

void init() {

	/* Create some test products */
	// products to start
	products[0].name = "food";
	products[0].costToMake = 25.0;
	products[0].life = 7;
	products[0].chanceOfRandomDisposal = 0.01;
	products[0].failureChance = 0.05;

	products[1].name = "clothing";
	products[1].costToMake = 10.0;
	products[1].life = 365*2;
	products[1].chanceOfRandomDisposal = 0.09;
	products[1].failureChance = 0.03;

	products[2].name = "car";
	products[2].costToMake = 10000.0;
	products[2].life = 365*15;
	products[2].chanceOfRandomDisposal = 0.0;
	products[2].failureChance = 0.005;

	products[3].name = "furniture";
	products[3].costToMake = 2000.0;
	products[3].life = 365*15;
	products[3].chanceOfRandomDisposal = 0.0;
	products[3].failureChance = 0.005;

	products[4].name = "computer";
	products[4].costToMake = 500.0;
	products[4].life = 365*2;
	products[4].chanceOfRandomDisposal = 0.01;
	products[4].failureChance = 0.01;

	/* Create some test businesses */

	business business;
	business.name = "Car Company";
	productForSale car;
	car.product = products[2];
	car.price = 740.0;
	car.numberAvailable = 5;
	business.addProduct(car);

	businesses.push_back(business);
}

void finalise() {

}

int main() {
	RUNNING = true;

	init();

	string anything;
	while (RUNNING) {
		for (int p = 0; p < people.size(); p++) {
			people.at(p).goToMarket(businesses);
		}
	}

	return 0;
}