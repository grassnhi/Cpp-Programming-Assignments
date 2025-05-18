#include "Infantry.h"

// TODO: implement
//!----------------------------------------------
//! Lớp Infantry
//!----------------------------------------------
Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType)
    : Unit(quantity, weight, pos), infantryType(infantryType)
{
}

int Infantry::getAttackScore() {
   
}
string Infantry::str() const {
}