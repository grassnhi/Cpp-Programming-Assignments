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

//!-----------------------------------------------------
//! CLASS Position
//!-----------------------------------------------------
class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos);
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const;
};

//!-----------------------------------------------------
//! CLASS Unit
//!-----------------------------------------------------
class Unit
{
protected:
    int quantity, weight;
    Position pos;
    // * You can add more attributes if needed
public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    virtual string str() const = 0;
    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS Infantry : public Unit
//!-----------------------------------------------------
class Infantry : public Unit
{
private:
    InfantryType infantryType;
    // * You can add more attributes if needed
public:
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);
    ~Infantry(){}
    int getAttackScore() override;
    string str() const override;

    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS Vehicle : public Unit
//!-----------------------------------------------------
class Vehicle : public Unit
{
private:
    VehicleType vehicleType;
    // * You can add more attributes if needed
public:
    Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType);
    ~Vehicle() {}
    int getAttackScore() override;
    string str() const override;
    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS UnitList
//!-----------------------------------------------------
class UnitList
{
private:
    int capacity;
    // * You can add more attributes if needed
public:
    UnitList(int capacity);
    bool insert(Unit *unit);
    bool isContain(VehicleType vehicleType);
    bool isContain(InfantryType infantryType);
    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS Army 
//!-----------------------------------------------------
class Army {
protected:
    int LF;
    int EXP;
    string name;
    BattleField* battleField;
    // * You can add more attributes if needed
    
public:
    UnitList *unitList;
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual ~Army();
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;

    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS LiberationArmy
//!-----------------------------------------------------
class LiberationArmy : public Army
{
private:
    // * You can add more attributes if needed
public:
    LiberationArmy(Unit **unitArray, int size, string name, BattleField *battleField);
    ~LiberationArmy();
    void fight(Army *enemy, bool defense) override;
    string str() const override;
    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS ARVN
//!-----------------------------------------------------
class ARVN : public Army
{
private:
    // * You can add more attributes if needed
public:
    ARVN(Unit** unitArray, int size, string name, BattleField* battleField);
    ~ARVN();
    void fight(Army* enemy, bool defense=false) override;
    string str() const;

    // * You can add more methods if needed

};

//!-----------------------------------------------------
//! CLASS TerrainElement và các lớp dẫn xuất
//!-----------------------------------------------------
class TerrainElement {
protected:
    Position pos;
    // * You can add more attributes if needed
public:
    TerrainElement(Position);
    virtual ~TerrainElement();
    virtual void getEffect(Army *army) = 0;
    // * You can add more attributes if needed
};

class Road : public TerrainElement {
public:
    Road(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

class Mountain : public TerrainElement {
public:
    Mountain(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

class River : public TerrainElement {
public:
    River(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

class Urban : public TerrainElement {
public:
    Urban(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

class Fortification : public TerrainElement {
public:
    Fortification(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

class SpecialZone : public TerrainElement {
public:
    SpecialZone(Position pos) : TerrainElement(pos) {}
    void getEffect(Army *army);
    // * You can add more methods if needed
};

//!-----------------------------------------------------
//! CLASS BattleField
//!-----------------------------------------------------
class BattleField {
private:
    int n_rows, n_cols;
    TerrainElement ***terrain;
    // * You can add more attributes if needed
public:
    BattleField(int n_rows, int n_cols, const vector<Position*>& arrayForest,
                const vector<Position*>& arrayRiver, const vector<Position*>& arrayFortification,
                const vector<Position*>& arrayUrban, const vector<Position*>& arraySpecialZone);
    ~BattleField();
    TerrainElement* getElement(int r, int c) const;
    string str() const;
    // * You can add more methods if needed
};

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
    vector<Unit*> liberationUnits;
    vector<Unit*> ARVNUnits;
    int eventCode;
    // * You can modify or add more attributes if needed
public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
    
    // * Getter methods */
    // * You can add more getter methods if needed
};

//!-----------------------------------------------------
//! Lớp HCMCampaign
//!-----------------------------------------------------
class HCMCampaign {
private:
    Configuration* config;
    BattleField* battleField;
    LiberationArmy* liberationArmy;
    ARVN* arvnArmy;
    // * You can modify or add more attributes if needed
public:
    HCMCampaign(const string & config_file_path);
    ~HCMCampaign();
    void run();
    // Phương thức printResult: trả về chuỗi kết quả theo định dạng:
    // "LIBERATIONARMY[LF=<LF>,EXP=<EXP>]-ARVN[LF=<LF>,EXP=<EXP>]"
    string printResult();
    // * You can add more methods if needed
};
#endif