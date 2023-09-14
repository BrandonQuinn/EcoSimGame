#ifndef CONFIGLOAD_H_
#define CONFIGLOAD_H_

#include <string>
#include <vector>
#include "item.h"

using namespace std;

/*
 * Takes the name of the file which stores each item that exists in the economy,
 * reads the file and stores the data stored in a vector and returns the vector
*/
vector<item>* loadItemlist(string filename);

#endif