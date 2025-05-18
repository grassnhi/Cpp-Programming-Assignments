#include "Vehicle.h"

//!----------------------------------------------
//! Lớp Vehicle
//!----------------------------------------------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType) {}

int Vehicle::getAttackScore(bool donoth){
    // string vehicleTypeStr;
    // switch (vehicleType) {
    //     case TRUCK: vehicleTypeStr = "TRUCK"; break;
    //     case MORTAR: vehicleTypeStr = "MORTAR"; break;
    //     case ANTIAIRCRAFT: vehicleTypeStr = "ANTIAIRCRAFT"; break;
    //     case ARMOREDCAR: vehicleTypeStr = "ARMOREDCAR"; break;
    //     case APC: vehicleTypeStr = "APC"; break;
    //     case ARTILLERY: vehicleTypeStr = "ARTILLERY"; break;
    //     case TANK: vehicleTypeStr = "TANK"; break;
    //     default: vehicleTypeStr = "UNKNOWN"; break;
    // }
    // cout << "\n type: " << vehicleTypeStr << " qual: " << quantity << " weig: " << weight << " => " << ceil((static_cast<int>(this->vehicleType) * 304 + this->quantity * this->weight) / 30.0);
    return ceil((static_cast<int>(this->vehicleType) * 304 + this->quantity * this->weight) / 30.0);
}

string Vehicle::str() const{
    string vehicleTypeStr;
    switch (vehicleType) {
        case TRUCK: vehicleTypeStr = "TRUCK"; break;
        case MORTAR: vehicleTypeStr = "MORTAR"; break;
        case ANTIAIRCRAFT: vehicleTypeStr = "ANTIAIRCRAFT"; break;
        case ARMOREDCAR: vehicleTypeStr = "ARMOREDCAR"; break;
        case APC: vehicleTypeStr = "APC"; break;
        case ARTILLERY: vehicleTypeStr = "ARTILLERY"; break;
        case TANK: vehicleTypeStr = "TANK"; break;
        default: vehicleTypeStr = "UNKNOWN"; break;
    }
    stringstream ss;
    ss << "Vehicle[vehicleType=" << vehicleTypeStr  
       << ",quantity=" << this->quantity
       << ",weight=" << this->weight
       << ",position=" << this->pos.str() << "]";  
    return ss.str();
}

VehicleType Vehicle::getVehicleType() const{
    return this->vehicleType;
}

bool Vehicle::isVehicle() const {
    return true;
}
