#include "Unit.h"

//!----------------------------------------------
//! Lớp Unit
//!----------------------------------------------
Unit::Unit(int quantity, int weight, Position pos)
    : quantity(quantity), weight(weight), pos(pos)
{}
Unit::~Unit()
{
    // Virtual destructor – nếu có bộ nhớ động thì giải phóng ở đây.
}
Position Unit::getCurrentPosition() const
{
    // TODO: Implement
}

void Unit::setWeight(int weight) {
    // TODO: Implement
}

void Unit::setQuantity(int quantity) {
    // TODO: Implement
}