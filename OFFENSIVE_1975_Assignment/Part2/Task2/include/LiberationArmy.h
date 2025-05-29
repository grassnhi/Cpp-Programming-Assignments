#ifndef _H_LIBERATIONARMY_H_
#define _H_LIBERATIONARMY_H_

#include "Army.h"

class LiberationArmy : public Army {
public:
    LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField = nullptr);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;

    bool isLiberation() const override;

private:
    int getNearestFibonacci(int num);
    bool findSmallest(int target, vector<Unit*>& selectedUnits, bool veh); 
};


#endif