#include "cmdline.h"
#include "sim/item.h"
#include <iostream>
#include <limits>

using namespace std;

// clears the fail bits and reads a line from cin to clear the buffer
void flushcin() {
	string tmp;
	cin.clear();
	getline(cin, tmp); // read the invalid line out of the buffer
}

// Reads a string from the console which meets certain conditions
string readString(string prompt) {
	string input = "";

	// keep asking for input while the input is bad or doesn't meet certain conditions
	while (cin.bad() | input == "") {
			cout << prompt;
			cin >> input;

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
float readFloatingPointPercentage(string prompt) {
	float input;
	bool continuePrompting = true;

	// keep asking for input while the input is bad or doesn't meet certain conditions
	while (cin.bad() | continuePrompting) {
			cout << prompt;
			cin >> input;

			// validate input
			if (cin.fail()) {
				cout << "Invalid input" << endl;
				flushcin();
			} else if (input < 0.0f | input > 1.0f) {
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
	item.failureChance = readFloatingPointPercentage("Enter failure chance (decimal percentage e.g. 0.23): ");

	return item;
}

int interpretCmd(string cmd) {
	if (cmd == "exit") {
		return -1;
	} else if (cmd == "help") { 

	} else if (cmd == "new item") {  
		item i = readItem();

		// TODO: create new item to economy

	} else {
		return 1;
	}

	return 0;
}