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
const int MANCOST_COL_INDEX = 1;
const int LIFESPAN_COL_INDEX = 2;
const int FAILURECHANCE_COL_INDEX = 3;

/*
* Converts a line from the items file to an actual item object.
* Limit of 128 
*/
item lineToItem(string line) {
    string tmp[ITEM_COLUMN_LIMIT];

    string name; // 0
    int manufacturingCost; // 1
    int lifeSpan; // 2
    float failureChance; // 3

    for (int c = 0, colIndex = 0; c < line.length(); c++) {
        if (line[c] == ',') {
            switch(colIndex) {
                case NAME_COL_INDEX:
                    name = tmp[NAME_COL_INDEX];
                    break;
                case MANCOST_COL_INDEX: 
                    manufacturingCost = stoi(tmp[MANCOST_COL_INDEX]);
                    break;
                case LIFESPAN_COL_INDEX:
                    lifeSpan = stoi(tmp[LIFESPAN_COL_INDEX]);
                    break;
                case FAILURECHANCE_COL_INDEX:
                    failureChance = stof(tmp[FAILURECHANCE_COL_INDEX]);
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
    
    return newitem;
}

vector<item>* loadItemlist(string filename) {
    vector<item> * items = new vector<item>();
   
    // load items file line by line
    string line;
    ifstream file;
    file.open(filename);
    if (!file.good()) {
        return NULL;
    }

    getline(file, line); // skip first line which is the headings
    while (getline(file, line)) {
        item i = lineToItem(line);
        items->push_back(i);
    }

    file.close();
    return items;
}