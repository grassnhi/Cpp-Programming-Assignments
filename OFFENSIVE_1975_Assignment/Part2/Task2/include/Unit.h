#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    int unitScore;
public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0; // must be overridden by derived classes
    Position getCurrentPosition() const;
    virtual string str() const = 0; // Pure virtual functions cannot have an implementation in the base class
    
    int getWeight() const;
    void setWeight(int w);
    void reduceWeight(double percent);

    int getQuantity() const;  
    void setQuantity(int q);
    void increaseQuantity(int amount); 
    void reduceQuantity(double percent);

    int getScore() const;
    void storeAttackScore(int attackScore);

    virtual bool isVehicle() const = 0;
};

#endif // UNIT_H
