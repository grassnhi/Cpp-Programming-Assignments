#include "TerrainElement.h"
#include "LiberationArmy.h"

double calculateDistance(const Position& pos1, const Position& pos2) {
    int rowDiff = pos1.getRow() - pos2.getRow();
    int colDiff = pos1.getCol() - pos2.getCol();
    return (sqrt(double(rowDiff * rowDiff + colDiff * colDiff)));
}
//!-----------------------------------------------------
//! Lớp TerrainElement và các lớp dẫn xuất
//!-----------------------------------------------------

// --------- TERRAIN ELEMENT CLASS IMPLEMENTATION (ABSTRACT) ---------
TerrainElement::TerrainElement() {}

TerrainElement::TerrainElement(Position pos) : position(pos) {}

TerrainElement::~TerrainElement() {}

Position TerrainElement::getPosition() const {
    return this->position;
}

// --------- INDIVIDUAL TERRAIN CLASSES IMPLEMENTATION ---------
Road::Road(Position pos) : TerrainElement(pos) {}

void Road::getEffect(Army* army) {
    // No effect
    // cout << "No effect" << endl;
}

string Road::type() const { 
    return "Road"; 
}

Mountain::Mountain(Position pos) : TerrainElement(pos) {}

void Mountain::getEffect(Army* army){
    bool isLiberation = army->isLiberation();
    int radius = isLiberation ? 2 : 4;
    double incrEXP = isLiberation ? 0.3 : 0.2;
    double decrsLF = isLiberation ? 0.1 : 0.05;

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = sqrt(pow(node->unit->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) +
                           pow(node->unit->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if(distance <= radius){
            if(node->unit->isVehicle()){
                int newLF = army->getLF() + static_cast<int>(ceil(node->unit->getAttackScore() * incrEXP));
                army->setLF(newLF);
            }else{
                army->setEXP(army->getEXP() + static_cast<int>(ceil(node->unit->getAttackScore() * incrEXP)));
            }
        }
        node = node->next;
    }
    
    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
}

string Mountain::type() const { 
    return "Moun"; 
}

River::River(Position pos) : TerrainElement(pos) {}

void River::getEffect(Army* army){
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = sqrt(pow(node->unit->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) + 
                                pow(node->unit->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if(distance <= 2){
            if(!(node->unit->isVehicle())){
                int newScore = army->getEXP() - static_cast<int>(ceil(node->unit->getAttackScore() * 0.1));
                army->setEXP(newScore);
            }
        }
        node = node->next;
    }

    army->setEXP(max(0, min(500, army->getEXP())));
}

string River::type() const { 
    return "Rivr"; 
}

Urban::Urban(Position pos) : TerrainElement(pos) {}

void Urban::getEffect(Army* army){
    bool isLiberation = army->isLiberation();

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = sqrt(pow(node->unit->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) + 
                                pow(node->unit->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if(isLiberation){
            if(node->unit->isVehicle()){
                Vehicle* veh = dynamic_cast<Vehicle*>(node->unit);
                if(veh->getVehicleType() == ARTILLERY && distance <= 2){
                    army->setLF(army->getLF() - static_cast<int>(ceil(node->unit->getAttackScore() * 0.5)));
                }
            }else{
                Infantry* inf = dynamic_cast<Infantry*>(node->unit);
                if((inf->getInfantryType() == SPECIALFORCES || inf->getInfantryType() == REGULARINFANTRY) && distance <= 5){
                    int delta = static_cast<int>(ceil((2 * node->unit->getAttackScore()) / distance));
                    army->setEXP(army->getEXP() + delta);
                }
            }
        }else if(!node->unit->isVehicle()){
            Infantry* inf = dynamic_cast<Infantry*>(node->unit);
            if(inf->getInfantryType() == REGULARINFANTRY && distance <= 3){
                int delta = static_cast<int>(ceil((3 * node->unit->getAttackScore()) / (2 * distance)));
                    army->setEXP(army->getEXP() + delta);
            }
        }
        node = node->next;
    }

    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
}

string Urban::type() const { 
    return "Urbn"; 
}

Fortification::Fortification(Position pos) : TerrainElement(pos) {}

void Fortification::getEffect(Army* army){
    bool isLiberation = army->isLiberation();

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = sqrt(pow(node->unit->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) + 
                                pow(node->unit->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if(distance <= 2){
            int delta = static_cast<int>(ceil(node->unit->getAttackScore() * 0.2));
            if(isLiberation){
                if(node->unit->isVehicle()){
                    army->setLF(army->getLF() - delta);
                }else{
                    army->setEXP(army->getEXP() - delta);
                }
            }else{
                if(node->unit->isVehicle()){
                    army->setLF(army->getLF() + delta);
                }else{
                    army->setEXP(army->getEXP() + delta);
                }
            }
        }
        node = node->next;
    }
    
    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
}

string Fortification::type() const { 
    return "Fort"; 
}

SpecialZone::SpecialZone(Position pos) : TerrainElement(pos) {}

void SpecialZone::getEffect(Army* army){
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = sqrt(pow(node->unit->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) + 
                                pow(node->unit->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if(distance <= 1){
            if(node->unit->isVehicle()){
                army->setLF(army->getLF() - node->unit->getAttackScore());
            }else{
                army->setEXP(army->getEXP() - node->unit->getAttackScore());
            }
        }
        node = node->next;
    }
    
    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
}

string SpecialZone::type() const { 
    return "Spec"; 
}
