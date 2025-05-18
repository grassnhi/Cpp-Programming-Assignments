#include "Unit.h"

Unit::Unit(int quantity, int weight, Position pos) 
    : quantity(quantity), weight(weight), pos(pos) {}

Unit::~Unit() {}

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
    this->weight *= (1 - percent);
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
    cout << "\n Old: " << this->quantity;
    this->quantity *= (1 - percent);
    cout << " - New: " << this->quantity;
}