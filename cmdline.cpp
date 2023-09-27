#include "cmdline.h"
#include "item.h"
#include <iostream>
#include <limits.h>

using namespace std;

// clears the fail bits and reads a line from cin to clear the buffer
void flushcin() {
	string tmp;
	cin.clear();
	getline(cin, tmp); // read the invalid line out of the buffer
}

// Reads a string from the console which meets certain conditions
string readstring(string prompt) {
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
				cout << "Name must greater than 1 character and less than 256 characters." << endl;
				input = "";
			}
	}

	return input;
}

// Reads an integer from the console which meets certain conditions
int readinteger(string prompt) {
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
				cout << "Cost must be greater than 0." << endl;
			} else {
				continuePrompting = false; // All conditions met
			}
	}

	return input;
}

// get the item information from the command line from the user
item readitem() {
	// name, manufacturing cost, life (days), chance of failure (pd)
	string name;
	int manufactureCost;
	int lifeDays;
	float failureChance;
	item item;
	
	cout << " == New Item == " << endl;	
	name = readstring("Enter name: ");
	manufactureCost = readinteger("Enter manufacturing cost: ");

	cout << "Enter life (in days): ";
	cin >> lifeDays;

	cout << "Enter failure chance (decimal percentage e.g. 0.23): ";
	cin >> failureChance;

	// TODO: Finish creating item and validating input


	return item;
}

int interpretCmd(string cmd) {
	if (cmd == "exit") {
		return -1;
	} else if (cmd == "new item") {  
		item i = readitem();

	} else {
		return 1;
	}

	return 0;
}