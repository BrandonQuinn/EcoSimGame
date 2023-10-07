#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "configload.h"

using namespace std;

// max number of columns for item dataset
const int ITEM_COLUMN_LIMIT = 16;

// Item column indexes
const int NAME_COL_INDEX = 0;
const int MAN_COST_COL_INDEX = 1;
const int LIFESPAN_COL_INDEX = 2;
const int FAILURE_CHANCE_COL_INDEX = 3;
const int PERSON_OWNERSHIP_COL_INDEX = 4;
const int HOUSE_OWNERSHIP_COL_INDEX = 5;

/*
* Converts a line from the items file to an actual item object.
*/
item lineToItem(string line) {
	string tmp[ITEM_COLUMN_LIMIT];

	string name; // 0
	int manufacturingCost; // 1
	int lifeSpan; // 2
	float failureChance; // 3
	float personOwnership;
	float houseOwnernship;

	for (int c = 0, colIndex = 0; c < line.length(); c++) {
		if (line[c] == ',') {
			switch(colIndex) {
				case NAME_COL_INDEX:
					name = tmp[NAME_COL_INDEX];
					break;
				case MAN_COST_COL_INDEX: 
					manufacturingCost = stoi(tmp[MAN_COST_COL_INDEX]);
					break;
				case LIFESPAN_COL_INDEX:
					lifeSpan = stoi(tmp[LIFESPAN_COL_INDEX]);
					break;
				case FAILURE_CHANCE_COL_INDEX:
					failureChance = stof(tmp[FAILURE_CHANCE_COL_INDEX]);
					break;
				case PERSON_OWNERSHIP_COL_INDEX:
					personOwnership = stof(tmp[PERSON_OWNERSHIP_COL_INDEX]);
					break;
				case HOUSE_OWNERSHIP_COL_INDEX:
					houseOwnernship = stof(tmp[HOUSE_OWNERSHIP_COL_INDEX]);
					break;
			}

			colIndex++; 
			continue; // make sure the ',' doesn't get included
		}
		
		tmp[colIndex] += line[c];
	}

	item newitem;
	newitem.name = name;
	newitem.manufacturingCost = manufacturingCost;
	newitem.lifeSpan = lifeSpan;
	newitem.failureChance = failureChance;
	newitem.personOwnership = personOwnership;
	newitem.houseOwnership = houseOwnernship;

	return newitem;
}

vector<item> loadItemlist(string filename) {
	vector<item> items;
   
	// load items file line by line
	string line;
	ifstream file;
	file.open(filename);

	getline(file, line); // skip first line which is the headings
	while (getline(file, line)) {
		item i = lineToItem(line);
		items.push_back(i);
	}

	file.close();
	return items;
}