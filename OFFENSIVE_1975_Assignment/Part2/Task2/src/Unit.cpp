#include "Unit.h"

//!----------------------------------------------
//! Lớp Unit
//!----------------------------------------------
Unit::Unit(int quantity, int weight, Position pos) 
    : quantity(quantity), weight(weight), pos(pos) {}

Unit::~Unit() {}

int Unit::getScore() const{
    return this->unitScore;
}

void Unit::storeAttackScore(int attackScore){
    this->unitScore = attackScore;
}

Position Unit::getCurrentPosition() const{
    return this->pos;
}

int Unit::getWeight() const{
    return this->weight;
}

int Unit::getQuantity() const{
    return this->quantity;
}

void Unit::reduceWeight(double percent){
    double temp = this->weight * (1 - percent);
    this->weight = ceil(temp);
}

void Unit::setWeight(int w){
    this->weight = w;
}

void Unit::setQuantity(int q){
    this->quantity = q;
}

void Unit::increaseQuantity(int amount){
    this->quantity += amount;
}

void Unit::reduceQuantity(double percent){
    // cout << "\n Old: " << this->quantity;
    double temp = this->quantity * (1 - percent);
    this->quantity = ceil(temp);
    // cout << " - New: " << this->quantity;
}