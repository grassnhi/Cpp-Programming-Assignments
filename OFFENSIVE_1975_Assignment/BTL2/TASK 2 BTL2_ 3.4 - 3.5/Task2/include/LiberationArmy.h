#ifndef _H_LIBERATIONARMY_H_
#define _H_LIBERATIONARMY_H_

#include "Army.h"

class LiberationArmy : public Army
{
private:
    Unit **unitArray;       // For temporary
    int size_V = 0;         // For temporary: vehicle count
    int size_I = 0;         // For temporary: infantry count
    int nearestFibonacci(int value);
    vector<Unit*> knapsack(vector<Unit*> units, int maxScore);
    Unit* cloneUnit(Unit* unit);
    

public:
    LiberationArmy(Unit **unitArray, int size, string name);
    void fight(Army *enemy, bool defense) override;
    string str() const override;
};

#endif