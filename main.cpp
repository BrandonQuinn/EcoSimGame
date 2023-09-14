#include <iostream>
#include "main.h"
#include "configload.h"
#include "cmdline.h"

using namespace std;

int main() {
	cout << "Starting game..." << endl;

	vector<item>* items = loadItemlist("items");

	string line;
	while (RUNNING) {
		// get input from user
		cout << "Enter: ";
		cin >> line;
		int success = interpretCmd(line);
		if (success != 0) {
			cout << "Invalid input" << endl;
		}
	}
	
	cout << "Game Stopped" << endl;

	delete(items);
	return 0;
}