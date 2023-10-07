#ifndef PERSON_H_
#define PERSON_H_

#include "..\economy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

struct inventory {
    item item;
    int daysOwned;
};

class person {
    public:
        vector<inventory> items;
        void create();
        void simulate();
};

#endif