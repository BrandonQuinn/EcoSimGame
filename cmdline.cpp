#include "cmdline.h"
#include "sim/item.h"
#include "economy.h"
#include <iostream>
#include <limits>

using namespace std;

// clears the fail bits and reads a line from cin to clear the buffer
void flushcin() {
	string tmp;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//getline(cin, tmp); // read the invalid line out of the buffer
}

// Reads a string from the console which meets certain conditions
string readString(string prompt) {
	string input = "";

	// keep asking for input while the input is bad or doesn't meet certain conditions
	while (cin.bad() | input == "") {
			cout << prompt;
			getline(cin, input);

			// validate input
			if (cin.fail()) {
				cout << "Invalid input" << endl;
				flushcin();
			} else if (input.length() <= 1 | input.length() >= 255) {
				cout << "Name must greater than 1 character and less than 256 characters" << endl;
				input = "";
			}
	}

	return input;
}

// Reads an integer from the console which meets certain conditions
int readPositiveInteger(string prompt) {
	int input;
	bool continuePrompting = true;

	// keep asking for input while the input is bad or doesn't meet certain conditions
	while (cin.bad() | continuePrompting) {
			cout << prompt;
			cin >> input;

			// validate input
			if (cin.fail()) {
				cout << "Invalid input" << endl;
				flushcin();
			} else if (input < 0) {
				cout << "Integer must be greater than 0" << endl;
			} else {
				continuePrompting = false; // All conditions met
			}
	}

	return input;
}

// Read a floating point value between 0 and 1 inclusive
float readDoublePercentage(string prompt) {
	double input;
	bool continuePrompting = true;

	// keep asking for input while the input is bad or doesn't meet certain conditions
	while (cin.bad() | continuePrompting) {
			cout << prompt;
			cin >> input;

			// validate input
			if (cin.fail()) {
				cout << "Invalid input" << endl;
				cout << "failed" << endl;
				flushcin();
			} else if (input < 0.0 | input > 1.0) {
				cout << "Value must be between 0.0 and 1.0" << endl;
			} else {
				continuePrompting = false; // All conditions met
			}
	}

	return input;
}

// get the item information from the command line from the user
item readItem() {
	item item;
	
	cout << " == New Item == " << endl;	
	item.name = readString("Enter name: ");
	item.manufacturingCost = readPositiveInteger("Enter manufacturing cost: ");
	item.lifeSpan = readPositiveInteger("Enter life (in days): ");
	item.failureChance = readDoublePercentage("Enter failure chance (decimal percentage e.g. 0.23): ");

	return item;
}

int interpretCmd(string cmd) {
	if (cmd == "exit") {
		return -1;
	} else if (cmd == "help") { 
		cout << " == Commands == " << endl;

		cout << "new item" << endl;
		cout << "	- Create a new item, prompts for each property" << endl;

		cout << "list items" << endl;
		cout << "	- List all items by name" << endl;

	} else if (cmd == "new item") {  
		item i = readItem();

		// TODO: create new item to economy
		economy::items->push_back(i);
		cout << "Item '" << i.name << "' created" << endl;
	} else if (cmd == "list items") {
		// List out each item
		cout << "Listing items:" << endl;
		for (int i = 0; i < economy::items->size(); i++) {
			cout << economy::items->at(i).name << endl;
		}
	} else {
		return 1;
	}

	return 0;
}