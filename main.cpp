#include "main.h"

int main() {
	RUNNING = true;
	cout << "Starting game..." << endl;

	vector<item>* items = loadItemlist("items");
	string line;
	int result;

	while (RUNNING) {
		result = -2;
		line = ""; // clear
		
		// get input from user
		cout << "> ";
		getline(cin, line);
		result = interpretCmd(line);
		
		if (result == 1) {
			cout << "Invalid input" << endl;
		} else if (result == -1) {
			RUNNING = false;
		}
	}
	
	cout << "Game Stopped" << endl;

	delete(items);
	return 0;
}