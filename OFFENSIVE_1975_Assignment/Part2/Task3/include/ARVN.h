#ifndef _H_ARVN_H_
#define _H_ARVN_H_

#include "Army.h"

class ARVN : public Army
{
private:
    // * Hin. You can remove it for your own implementation.
    int nearestFibonacci(int value);
    vector<Unit*> knapsack(vector<Unit*> units, int maxScore);
    Unit* cloneUnit(Unit* unit);
    void resetARVN();
public:
    ARVN(Unit** unitArray, int size, string name, BattleField *battleField);
    void fight(Army* enemy, bool defense=false) override;
    string str() const;

};

#endif