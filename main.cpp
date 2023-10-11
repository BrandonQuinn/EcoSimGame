#include "main.h"
#include "economy.h"

/*
	Func prototypes
*/
string getInput();
void interpretCmdlnInput(string);
void simulate();

economy* econ = new economy;

void init() {
	econ->initSampleData();
}

void finalise() {

}

int main() {
	RUNNING = true;
	init();
	cout << "Starting simulation..." << endl;
	
	while (RUNNING) {
		interpretCmdlnInput(getInput());
	}

	finalise();
	cout << "Simulation ended." << endl;
	return 0;
}

string getInput() {
	string input;
	cout << "> ";
	cin >> input;
	return input;
}

/*
	Interpret command line input and figure out what to do.
*/
void interpretCmdlnInput(string input) {
	cout << ">>> " << input << endl;

	if (input == "exit") {
		RUNNING = false;
	} else if (input == "go") {
		econ->simulate();
	}
}
