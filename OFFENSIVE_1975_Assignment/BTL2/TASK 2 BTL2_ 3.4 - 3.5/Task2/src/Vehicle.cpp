#include "Vehicle.h"

//!----------------------------------------------
//! Lớp Vehicle
//!----------------------------------------------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType)
{
}

int Vehicle::getAttackScore()
{
    // TODO: Implement
}


/* 
@Fix
 */
string Vehicle::str() const
{
    // TODO: Implement
}