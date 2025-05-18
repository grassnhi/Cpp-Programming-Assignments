#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"

class UnitList
{
private:
    int capacity;
    vector<Unit *> units;
    int countVehicle, countInfantry;

public:
    UnitList(int capacity);
    bool insert(Unit *unit);
    bool isContain(VehicleType vehicleType);
    bool isContain(InfantryType infantryType);
    //vector<Unit *> getUnits() const;
    string str() const;
    // * Additional functions if possible
};

#endif
