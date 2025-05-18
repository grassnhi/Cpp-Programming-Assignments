#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    int attackScore;

public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit() = default;
    virtual int getAttackScore() = 0;
    int getAttackScoreinFight();
    void setAttackScore(int score);
    Position getCurrentPosition() const;
    virtual string str() const = 0;

    int getQuantity() { return quantity; }
    int getWeight() { return weight; }
    void setQuantity(int quantity);
    void setWeight(int weight);
};

#endif // UNIT_H
