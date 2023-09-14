#include <iostream>
#include "main.h"
#include "configload.h"

using namespace std;

int main() {
	cout << "Starting game..." << endl;

	vector<item>* items = loadItemlist("items");

	string line;
	while (RUNNING) {
		// get input from user
		cout << "Enter: ";
		cin >> line;
	}
	
	cout << "Game Stopped" << endl;

	delete(items);
	return 0;
}