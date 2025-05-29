#ifndef _H_TERRAIN_ELEMENT_H_
#define _H_TERRAIN_ELEMENT_H_

class Army; // Forward declaration

#include "Army.h"

//-----------------------------------------------------
// CLASS TerrainElement và các lớp dẫn xuất
//-----------------------------------------------------
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
    virtual string type() const = 0;

    double calculateDistance(const Position& pos1, const Position& pos2);
};

class Road : public TerrainElement {
public:
    Road(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};

class Mountain : public TerrainElement {
public:
    Mountain(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};

class River : public TerrainElement {
public:
    River(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};

class Urban : public TerrainElement {
public:
    Urban(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};

class Fortification : public TerrainElement {
public:
    Fortification(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};

class SpecialZone : public TerrainElement {
public:
    SpecialZone(Position pos);
    void getEffect(Army* army) override;
    string type() const override;
};



#endif