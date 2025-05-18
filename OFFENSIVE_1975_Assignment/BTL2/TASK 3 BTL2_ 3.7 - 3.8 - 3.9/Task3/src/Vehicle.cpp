#include "Vehicle.h"

// ? Hàm chuyển enum VehicleType thành chuỗi
string vehicleTypeToString(VehicleType vt)
{
    switch(vt)
    {
        case TRUCK:         return "TRUCK";
        case MORTAR:        return "MORTAR";
        case ANTIAIRCRAFT:  return "ANTIAIRCRAFT";
        case ARMOREDCAR:    return "ARMOREDCAR";
        case APC:           return "APC";
        case ARTILLERY:     return "ARTILLERY";
        case TANK:          return "TANK";
        default:            return "UNKNOWN";
    }
}

//!----------------------------------------------
//! Lớp Vehicle
//!----------------------------------------------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType)
{
    
}

int Vehicle::getAttackScore()
{
}


/* 
@Fix
 */
string Vehicle::str() const
{
}