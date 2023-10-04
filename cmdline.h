#ifndef CMDLINE_H_
#define CMDLINE_H_

#include <string>

using namespace std;

/*
 * This is where the magic happens, takes the users input and determines 
 * what to dos, calling appropriate functions 
*/
int interpretCmd(string);
void flushcin();

#endif