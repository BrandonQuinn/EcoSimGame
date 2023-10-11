#include "economy.h"

void economy::initSampleData() {
	/* Create some test products */
	// products to start
	products[0].name = "food";
	products[0].costToMake = 25;
	products[0].life = 7;
	products[0].chanceOfRandomDisposal = 0.01;
	products[0].failureChance = 0.05;

	products[1].name = "clothing";
	products[1].costToMake = 10;
	products[1].life = 365*2;
	products[1].chanceOfRandomDisposal = 0.09;
	products[1].failureChance = 0.03;

	products[2].name = "car";
	products[2].costToMake = 10000;
	products[2].life = 365*15;
	products[2].chanceOfRandomDisposal = 0.0;
	products[2].failureChance = 0.005;

	products[3].name = "furniture";
	products[3].costToMake = 2000;
	products[3].life = 365*15;
	products[3].chanceOfRandomDisposal = 0.0;
	products[3].failureChance = 0.005;

	products[4].name = "computer";
	products[4].costToMake = 500;
	products[4].life = 365*2;
	products[4].chanceOfRandomDisposal = 0.01;
	products[4].failureChance = 0.01;

	/* Create some test businesses */

	business business;
	business.name = "Car Company";
	
	productForSale car;
	car.product = products[2];
	car.price = 22500;
	car.numberAvailable = 70;
	business.addProduct(car);

	productForSale computer;
	computer.product = products[4];
	computer.price = 740;
	computer.numberAvailable = 150;
	business.addProduct(computer);

	productForSale furniture;
	furniture.product = products[3];
	furniture.price = 5000;
	furniture.numberAvailable = 100;
	business.addProduct(furniture);

	productForSale clothing;
	clothing.product = products[1];
	clothing.price = 50;
	clothing.numberAvailable = 200;
	business.addProduct(clothing);

	businesses->push_back(business); 

	for (int i = 0; i < INIT_NUM_PEOPLE; i++) {
		person person;
		people->push_back(person);
	}
}

/*
	Run 1 round of the simulation.
*/
void economy::simulate() {
	// people buy products
	for (int p = 0; p < people->size(); p++) {
		people->at(p).goToMarket(businesses);
	}

	// TODO: collect data about people

	// TODO: check business status, gather statistics about business performance

	// TODO: update/alter economic trends

	day++;
}