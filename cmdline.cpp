#include "cmdline.h"
#include "item.h"
#include <iostream>

using namespace std;

// get the item information from the command line from the user
item readitem() {
    // name, manufacturing cost, life (days), chance of failure (pd)
    string name;
    int manufactureCost;
    int lifeDays;
    float failureChance;
    item item;
    
    cout << " == New Item == " << endl;
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter manufacturing cost (full number): ";
    cin >> manufactureCost;

    cout << "Enter life (in days): ";
    cin >> lifeDays;

    cout << "Enter failure change (decimal percentage e.g. 0.23): ";
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