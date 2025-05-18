#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"

class UnitNode {
public:
    Unit* unit;
    UnitNode* next;
    
    UnitNode(Unit* unit) : unit(unit), next(nullptr) {}
};

class UnitList
{
private:
    int capacity;
    // TODO
    int size;
    int count_vehicle;
    int count_infantry;
    UnitNode* head;
    UnitNode* tail;
public:
    UnitList(int capacity);
    bool insert(Unit *unit);                   
    bool isContain(VehicleType vehicleType);   
    bool isContain(InfantryType infantryType); 
    string str() const;
    // TODO
    ~UnitList();
    void removeUnit(Unit* unit);
    void removeWeakUnits();
    void reduceWeight(double percent);
    void reduceQuantity(double percent);
    void transferTo(UnitList* otherList);

    UnitNode* getHead() const;
    int getSize() const;
};

#endif
