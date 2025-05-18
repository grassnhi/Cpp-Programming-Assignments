#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Infantry : public Unit {
private:
    InfantryType infantryType;

public:
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);
    int getAttackScore(bool donoth = false) override;
    string str() const override;
    InfantryType getInfantryType() const;  // Getter for InfantryType
    int personalNumber(int score);
    bool isPerfectSquare(int num);
    bool isVehicle() const override;
};

#endif // INFANTRY_H