#ifndef CMDLINE_H_
#define CMDLINE_H_

#include <string>

using namespace std;

/*
 * This is where the magic happens, takes the users input and determines 
 * what to do, calling appropriate functions 
*/
int interpretCmd(string);

#endif