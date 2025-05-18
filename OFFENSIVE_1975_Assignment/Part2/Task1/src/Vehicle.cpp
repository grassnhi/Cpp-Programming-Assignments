#include "Vehicle.h"

// TODO: implement
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType) {}

int Vehicle::getAttackScore(){
    // cout << " type: " << static_cast<int>(this->vehicleType) << " qual: " << quantity << " weig: " << weight;
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