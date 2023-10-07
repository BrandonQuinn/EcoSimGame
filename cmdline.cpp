#include "cmdline.h"
#include "sim/item.h"
#include "economy.h"
#include <iostream>
#include <limits>

using namespace std;

const int SPLIT_STRING_BUFFER_SIZE = 100;

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
float readFloatPercentage(string prompt) {
	float input;
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

// Return a boolean based on user input being 'y' or 'n'
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
	item.failureChance = readFloatPercentage("Enter failure chance (decimal percentage e.g. 0.23): ");
	item.personOwnership = readFloatPercentage("Do people require this item (y/n)");
	item.houseOwnership = readFloatPercentage("Do people houses require this item (y/n)");

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

// Write the help menu to the console
void outputHelpMenu() {
	cout << " == Commands == " << endl;

	cout << "newItem" << endl;
	cout << "	- Create a new item, prompts for each property" << endl;

	cout << "listItems" << endl;
	cout << "	- List all items by name" << endl;

	cout << "listBus" << endl;
	cout << "	- List all businesses by name" << endl;

	cout << "newBus" << endl;
	cout << "	- Create new business, just asks for a name" << endl;
}

// Prompt the user to create a new item
void newItem() {
	// Prompt user to create a new item
	item i = readItem();
	int success = economy::addItem(i);

	if (success == 0) {
		cout << "Item '" << i.name << "' created" << endl;
	} else if (success == -1) {
		cout << "Item probably already exists by that name." << endl;
	}

	flushcin();
}

// List all items
void listItems() {
	// List out each item
	cout << " == Items == " << endl;
	for (int i = 0; i < economy::items.size(); i++) {
		cout << economy::items.at(i).name << endl;
	}
}

// List the name of every business
void listBusinesses() {
	cout << " == Businesses == " << endl;
	for (int i = 0; i < economy::businesses.size(); i++) {
		cout << economy::businesses.at(i).name << endl;
	}
}

// Create a new business 
void newBusiness() {
	business b;
	b.name = readString("Enter business name: ");
	economy::businesses.push_back(b);
	cout << "Created new business: " << b.name << endl;
}

// Main command line interpreter function
int interpretCmd(string cmd) {
	if (cmd == "exit") {
		return -1;
	} else if (cmd == "help") { 
		outputHelpMenu();
	} else if (cmd == "newItem") {
		newItem();
	} else if (cmd == "listItems") {
		listItems();
	} else if (cmd == "listBus") {
		listBusinesses();
	} else if (cmd == "newBus") {
		newBusiness();
	} else if (cmd.substr(0, 19) == "modBus-addItem") {
		string arr[4];
		if (splitString(cmd, arr, 4) == -1) {
			cout << "Command has too few or too many arguments." << endl; 
			return 1;
		}

		// economy::modBusAddItem(arr[1], arr[2], stoi(arr[3]));

	} else {
		return 1;
	}

	return 0;
}