#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"

class UnitList
{
private:
    // Your implement

public:
    UnitList(int capacity);
    bool insert(Unit *unit);
    bool isContain(VehicleType vehicleType);
    bool isContain(InfantryType infantryType);
    //vector<Unit *> getUnits() const;
    string str() const;
    void reduceQuantity(int percent);
    void reduceWeight(int percent);
    void clear() {}
    void setUnits(vector<Unit *> units);
    void remove(Unit *unit);
    vector<Unit *>& getUnits();
    void removeUnits(vector<Unit*>& unitsToRemove);
};

#endif
