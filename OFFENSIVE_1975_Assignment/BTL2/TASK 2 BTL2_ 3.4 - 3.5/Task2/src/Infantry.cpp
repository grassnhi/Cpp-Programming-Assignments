#include "Infantry.h"

// TODO: implement

// ? Kiểm tra n có phải là số chính phương không
bool isPerfectSquare(int n) {
    // TODO: implement
}

// ? Tính tổng các chữ số của n
int sumDigits(int n) {
    // TODO: implement
}

// ? Tính “số cá nhân”: tổng các chữ số của score và năm (1975), sau đó tiếp tục tính đến khi ra 1 chữ số.
int computeSingleDigit(int score, int year) {
    // TODO: implement
}

int safeCeilInf(double value) {
    // TODO: implement
}

//!----------------------------------------------
//! Lớp Infantry
//!----------------------------------------------
Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType)
    : Unit(quantity, weight, pos), infantryType(infantryType)
{
}

int Infantry::getAttackScore() {
    // TODO: implement
}

string Infantry::str() const {
    // TODO: implement
}