/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 2
 * Programming Fundamentals Spring 2025
 * Date: 02.02.2025
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_HCM_CAMPAIGN_H_
#define _H_HCM_CAMPAIGN_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
class Unit;
class UnitList;
class Army;
class TerrainElement;

class Vehicle;
class Infantry;

class LiberationArmy;
class ARVN;

class Position;

class Road;
class Mountain;
class River;
class Urban;
class Fortification;
class SpecialZone;

class BattleField;

class HCMCampaign;
class Configuration;

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
enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Army
{
protected:
    int LF, EXP;
    string name;
    UnitList *unitList;
    BattleField *battleField;

    void updateStats();
public:
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;

    virtual ~Army();

    int getLF() const;
    int getEXP() const;
    void setLF(int value);
    void setEXP(int value);

    UnitList* getUnitList() const;
};

//////////// LiberationArmy and ARVN ////////////// 
class LiberationArmy : public Army {
public:
    LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;

private:
    bool findSmallest(int target, vector<Unit*>& selectedUnits);
    int getNearestFibonacci(int num);
};

class ARVN : public Army {
public:
    ARVN(Unit** unitArray, int size, string name, BattleField* battleField);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;
};
///////////////////////////////////////////////////////

class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos); // Example: str_pos = "(1,15)"
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const; // Example: returns "(1,15)"
};

class Unit
{
protected:
    int quantity, weight;
    Position pos;

public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0; // must be overridden by derived classes
    Position getCurrentPosition() const;
    virtual string str() const = 0; // Pure virtual functions cannot have an implementation in the base class
    
    int getWeight() const;
    void setWeight(int w);
    void reduceWeight(double percent);

    int getQuantity() const;  
    void setQuantity(int q);
    void increaseQuantity(int amount);
    void reduceQuantity(double percent); 
};

//////////// VEHICLE and INFANTRY /////////////
class Vehicle : public Unit {
private:
    VehicleType vehicleType;
public:
    Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType);
    int getAttackScore() override;
    string str() const override;
    VehicleType getVehicleType() const;  // Getter for VehicleType
};

class Infantry : public Unit {
private:
    InfantryType infantryType;
public:
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);
    int getAttackScore() override;
    string str() const override;
    InfantryType getInfantryType() const;  // Getter for InfantryType
};
//////////////////////////////////////////////////////

/////////// Add Node for LL/////////////////
class UnitNode {
public:
    Unit* unit;
    UnitNode* next;
    
    UnitNode(Unit* unit) : unit(unit), next(nullptr) {}
};
////////////////////////////////////////////////

class UnitList
{
private:
    int capacity;
    // TODO
    int size;
    int count_vehicle;
    int count_infantry;
    UnitNode* head;
    UnitNode* tail;
public:
    UnitList(int capacity);
    bool insert(Unit *unit);                   // return true if insert successfully
    bool isContain(VehicleType vehicleType);   // return true if it exists
    bool isContain(InfantryType infantryType); // return true if it exists
    string str() const;
    // TODO
    ~UnitList();
    void removeUnit(Unit* unit);
    void reduceWeight(double percent);
    void reduceQuantity(double percent);
    void transferTo(UnitList* otherList);

    UnitNode* getHead() const;
};

class TerrainElement
{
private:
    Position position;
public:
    TerrainElement();
    TerrainElement(Position pos); 
    ~TerrainElement();
    virtual void getEffect(Army *army) = 0;
    Position getPosition() const;
};

class Road : public TerrainElement {
public:
    Road(Position pos);
    void getEffect(Army* army) override;
};

class Mountain : public TerrainElement {
public:
    Mountain(Position pos);
    void getEffect(Army* army) override;
};

class River : public TerrainElement {
public:
    River(Position pos);
    void getEffect(Army* army) override;
};

class Urban : public TerrainElement {
public:
    Urban(Position pos);
    void getEffect(Army* army) override;
};

class Fortification : public TerrainElement {
public:
    Fortification(Position pos);
    void getEffect(Army* army) override;
};

class SpecialZone : public TerrainElement {
public:
    SpecialZone(Position pos);
    void getEffect(Army* army) override;
};


class BattleField
{
private:
    int n_rows, n_cols;
    // TODO
    TerrainElement*** terrain;
public:
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();

    void replaceTerrain(Position* pos, TerrainElement* newTerrain);
    void applyTerrainEffects(Army* army);
    string str() const;
};

//--Configuration
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
};
/////////

class HCMCampaign
{
private:
    Configuration *config;
    BattleField *battleField;
    LiberationArmy *liberationArmy;
    ARVN *ARVNArmy;

public:
    HCMCampaign(const string &config_file_path);
    ~HCMCampaign();
    
    void run();
    string printResult();
};

#endif