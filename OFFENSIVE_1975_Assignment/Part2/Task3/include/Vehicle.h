#ifndef VEHICLE_H
#define VEHICLE_H

#include "Unit.h"

enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};

class Vehicle : public Unit
{
protected:
    VehicleType vehicleType;  // * Thể loại phương tiện

public:
    // * Constructor: khởi tạo với quantity, weight, pos, và vehicleType.
    Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType);

    // * Override hàm getAttackScore: score = (vehicleType_value * 304) + (quantity * weight)
    int getAttackScore() override;

    // * Override hàm str: trả về chuỗi theo định dạng
    // * "Vehicle[vehicleType=<vehicleType>, quantity=<quantity>, weight=<weight>, pos=<pos>]"
    string str() const override;

    // * Help: Get/Set
    VehicleType getVehicleType() const { return vehicleType; }
    void setVehicleType(VehicleType value) { vehicleType = value; }

    static string vehicleTypeToString(VehicleType vt) {
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
};

#endif // VEHICLE_H
