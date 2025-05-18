#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "main.h"
#include "Position.h"
#include "Unit.h"
#include "Vehicle.h"
#include "Infantry.h"
//!-----------------------------------------------------
//! CLASS Configuration
//!-----------------------------------------------------
class Configuration {
private:
    int num_rows;
    int num_cols;
    vector<Position*> arrayForest;
    vector<Position*> arrayRiver;
    vector<Position*> arrayFortification;
    vector<Position*> arrayUrban;
    vector<Position*> arraySpecialZone;
    // Các mảng đơn vị quân được để trống (stub) trong phần hiện thực mẫu
    vector<Unit*> liberationUnits;
    vector<Unit*> ARVNUnits;
    
    int eventCode;
public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
    
    // Hint: You can add more or other methods to access the private members if needed.
    int getNumRows() const { return num_rows; }
    int getNumCols() const { return num_cols; }
    const vector<Position*>& getForestPositions() const { return arrayForest; }
    const vector<Position*>& getRiverPositions() const { return arrayRiver; }
    const vector<Position*>& getFortificationPositions() const { return arrayFortification; }
    const vector<Position*>& getUrbanPositions() const { return arrayUrban; }
    const vector<Position*>& getSpecialZonePositions() const { return arraySpecialZone; }
    int getEventCode() const { return eventCode; }
    vector<Unit*>& getLiberationUnits() { return liberationUnits; }
    vector<Unit*>& getARVNUnits() { return ARVNUnits; }
};

#endif