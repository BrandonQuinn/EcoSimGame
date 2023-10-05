#include "cmdline.h"
#include "sim/item.h"
#include "economy.h"
#include <iostream>
#include <limits>

using namespace std;

int SPLIT_STRING_BUFFER_SIZE = 100;

// clears the fail bits and reads a line from cin to clear the buffer
void flushcin() {
	string tmp;
	cin.clear();
	while (cin.peek() != '\n') char x = cin.get(); // clear buffer until newline
	if (cin.peek() == '\n') char x = cin.get(); // clear buffer of the new line
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

bool readYesorNo(string prompt) {
	string input;
	bool returnValue;
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
			} else if (input != "y" && input != "n" &&
				input != "Y" && input != "N") {
				cout << "Enter y or n" << endl;
			} else {
				continuePrompting = false; // All conditions met
			}
	}

	if (input == "y" || input == "Y") return true;
	return false;
}

// get the item information from the command line from the user
item readItem() {
	item item;
	
	cout << " == New Item == " << endl;	
	item.name = readString("Enter name: ");
	item.manufacturingCost = readPositiveInteger("Enter manufacturing cost: ");
	item.lifeSpan = readPositiveInteger("Enter life (in days): ");
	item.failureChance = readDoublePercentage("Enter failure chance (decimal percentage e.g. 0.23): ");
	item.person = readYesorNo("Do people require this item (y/n)");
	item.house = readYesorNo("Do people houses require this item (y/n)");

	return item;
}

// Returns -1 if the number of arguments is invalid
int splitString(string str, string* array, int argc) {
	int i = 0, s = 0;
	for (; i < str.size(); i++) {
		if (s > argc-1) {return -1;}
		if (str.at(i) == ' ') {s++; continue;}
		array[s] += str.at(i);
	}

	if (s < argc-1) return -1;

	return 0;
}

int interpretCmd(string cmd) {
	if (cmd == "exit") {
		return -1;
	} else if (cmd == "help") { 
		cout << " == Commands == " << endl;

		cout << "newItem" << endl;
		cout << "	- Create a new item, prompts for each property" << endl;

		cout << "listItems" << endl;
		cout << "	- List all items by name" << endl;

		cout << "listBusinesses" << endl;
		cout << "	- List all businesses by name" << endl;

		cout << "newBusiness" << endl;
		cout << "	- Create new business, just asks name, use modb to modify the business" << endl;
	} 
	
	/* ITEM COMMANDS */
	
	else if (cmd == "newitem") {
		// Prompt user to create a new item
		item i = readItem();
		economy::items->push_back(i);
		cout << "Item '" << i.name << "' created" << endl;
		flushcin();
	} else if (cmd == "listItems") {
		// List out each item
		cout << " == Items == " << endl;
		for (int i = 0; i < economy::items->size(); i++) {
			cout << economy::items->at(i).name << endl;
		}
	} 

	/* BUSINESS COMMANDS */

	else if (cmd == "listBus") {
		cout << " == Businesses == " << endl;
		for (int i = 0; i < economy::businesses->size(); i++) {
			cout << economy::businesses->at(i).name << endl;
		}
	} else if (cmd == "newBus") {
		business b;
		b.name = readString("Enter business name: ");
		economy::businesses->push_back(b);
		cout << "Created new business: " << b.name << endl;
	} else if (cmd.substr(0, 19) == "modBus-addItem") {
		// TODO: modify business
		string arr[4];
		if (splitString(cmd, arr, 4) == -1) {
			cout << "Command has too few or too many arguments." << endl; 
			return 1;
		}
	} else {
		return 1;
	}

	return 0;
}