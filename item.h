#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class item {
    public:
        string name;
        double manufacturingCost; // in AUD $
        int lifeSpan; // in days
        float failureChance; // per day
};

#endif