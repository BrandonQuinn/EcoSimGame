#include "main.h"

void init() {
	cout << "Starting game..." << endl;
	economy::items = loadItemlist("items");
	economy::initialize();
}

void finalise() {

}

int main() {
	RUNNING = true;
	string line;
	int result;

	init();

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

	return 0;
}