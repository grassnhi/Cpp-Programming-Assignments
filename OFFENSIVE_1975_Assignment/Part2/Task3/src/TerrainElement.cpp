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

double TerrainElement::calculateDistance(const Position& pos1, const Position& pos2) {
    int row = pos1.getRow() - pos2.getRow();
    int col = pos1.getCol() - pos2.getCol();
    return (sqrt(double(row * row + col * col)));
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
    double radius = isLiberation ? 2.0 : 4.0;
    double incrEXP = isLiberation ? 0.3 : 0.2;
    double descrLF = isLiberation ? 0.1 : 0.05;

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = this->calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if (distance <= radius) {
            cout << "Effect: " << node->unit->str() << endl;

            double score = node->unit->getScore();

            if (node->unit->isVehicle()) {
                double descr = ceil(score * descrLF * 1.0);
                cout << " => score: " << score << " - descrLF: " << descrLF << " => descr: " << descr << " => distance: " << distance << " => radius: " << radius << endl;

                int newLF = army->getLF() - static_cast<int>(descr);
                army->setLF(newLF);
            } else {
                double incr = ceil(score * incrEXP * 1.0);
                cout << " => incr: " << incr << " => distance: " << distance << " => radius: " << radius << endl;

                int newEXP = army->getEXP() + static_cast<int>(incr);
                army->setEXP(newEXP);
            }
        }

        node = node->next;
    }
    
    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
    cout << "LF: " << army->getLF() << " - EXP: " << army->getEXP() << endl;
}

string Mountain::type() const { 
    return "Moun"; 
}

River::River(Position pos) : TerrainElement(pos) {}

void River::getEffect(Army* army){
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = this->calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 2){
            if(!(node->unit->isVehicle())){
                double newScore = node->unit->getScore() * 0.9;
                cout << "newScore: " << newScore << endl;
                node->unit->storeAttackScore(ceil(newScore));
            }
        }
        node = node->next;
    }
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
        double distance = this->calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(isLiberation){
            if(node->unit->isVehicle()){
                Vehicle* veh = dynamic_cast<Vehicle*>(node->unit);
                if(veh->getVehicleType() == ARTILLERY && distance <= 2){
                    veh->storeAttackScore(veh->getScore() + static_cast<int>(ceil(veh->getScore() * 0.5)));
                }
            }else{
                Infantry* inf = dynamic_cast<Infantry*>(node->unit);
                if((inf->getInfantryType() == SPECIALFORCES || inf->getInfantryType() == REGULARINFANTRY) && distance <= 5){
                    int delta = static_cast<int>(ceil((2.0 * node->unit->getScore()) / distance));
                    inf->storeAttackScore(inf->getScore() + delta);
                }
            }
        }else if(!node->unit->isVehicle()){
            Infantry* inf = dynamic_cast<Infantry*>(node->unit);
            if(inf->getInfantryType() == REGULARINFANTRY && distance <= 3){
                int delta = static_cast<int>(ceil((3.0 * node->unit->getScore()) / (2.0 * distance)));
                inf->storeAttackScore(inf->getScore() + delta);
            }
        }
        node = node->next;
    }
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
        double distance = this->calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 2){
            int delta = static_cast<int>(ceil(node->unit->getScore() * 0.2));
            if(isLiberation){
                node->unit->storeAttackScore(node->unit->getScore() - delta);
            }else{
                node->unit->storeAttackScore(node->unit->getScore() + delta);
            }
        }
        node = node->next;
    }
}

string Fortification::type() const { 
    return "Fort"; 
}

SpecialZone::SpecialZone(Position pos) : TerrainElement(pos) {}

void SpecialZone::getEffect(Army* army){
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = this->calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 1){
            if(node->unit->isVehicle()){
                cout << "Vehicle effected: " << node->unit->str() << " - " << node->unit->getScore() << endl;
                node->unit->storeAttackScore(0);
            }else{
                cout << "Inf effected: " << node->unit->str()  << " - " << node->unit->getScore() << endl;
                node->unit->storeAttackScore(0);
            }
        }
        node = node->next;
    }
    
    // army->setLF(max(0, min(1000, army->getLF())));
    // army->setEXP(max(0, min(500, army->getEXP())));
}

string SpecialZone::type() const { 
    return "Spec"; 
}