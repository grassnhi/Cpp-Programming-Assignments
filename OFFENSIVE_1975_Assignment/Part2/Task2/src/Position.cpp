#include "Position.h"

//!----------------------------------------------
//! Lớp Position
//!----------------------------------------------
Position::Position(int r, int c) : r(r), c(c) {}

Position::Position(const string &str_pos) {
    char dummy;
    stringstream ss(str_pos);
    ss >> dummy >> this->r >> dummy >> this->c >> dummy;
}

int Position::getRow() const{
    return this->r;
}

int Position::getCol() const{
    return this->c;
}

void Position::setRow(int r){
    this->r = r;
}

void Position::setCol(int c){
    this->c = c;
}

string Position::str() const{
    return "(" + to_string(this->r) + "," + to_string(this->c) + ")";
}
