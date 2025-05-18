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
    int num_rows, num_cols;
    vector<Position*> arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone;
    vector<Unit*> liberationUnits, ARVNUnits;
    int eventCode;

public:
    Configuration(const string& filepath);
    ~Configuration();

    int getNumRows() const;
    int getNumCols() const;

    const vector<Position*>& getArrayForest() const;
    const vector<Position*>& getArrayRiver() const;
    const vector<Position*>& getArrayFortification() const;
    const vector<Position*>& getArrayUrban() const;
    const vector<Position*>& getArraySpecialZone() const;

    const vector<Unit*>& getLiberationUnits() const;
    const vector<Unit*>& getARVNUnits() const;

    int getEventCode() const;
    
    string str() const;

    void extractPosition(const string& data, vector<Position*>& target);
    string printPositions(const string& label, const vector<Position*>& positions) const;
};

#endif