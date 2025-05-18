#include "Infantry.h"

// TODO: implement

Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType)
        : Unit(quantity, weight, pos), infantryType(infantryType) {}

string Infantry::str() const{
    string infantryTypeStr;
    switch (infantryType) {
        case SNIPER: infantryTypeStr = "SNIPER"; break;
        case ANTIAIRCRAFTSQUAD: infantryTypeStr = "ANTIAIRCRAFTSQUAD"; break;
        case MORTARSQUAD: infantryTypeStr = "MORTARSQUAD"; break;
        case ENGINEER: infantryTypeStr = "ENGINEER"; break;
        case SPECIALFORCES: infantryTypeStr = "SPECIALFORCES"; break;
        case REGULARINFANTRY: infantryTypeStr = "REGULARINFANTRY"; break;
        default: infantryTypeStr = "UNKNOWN"; break;
    }

    stringstream ss;
    ss << "Infantry[infantryType=" << infantryTypeStr
       << ",quantity=" << this->quantity
       << ",weight=" << this->weight
       << ",position=" << this->pos.str() << "]";  
    return ss.str();
}

InfantryType Infantry::getInfantryType() const{
    return this->infantryType;
}

bool Infantry::isPerfectSquare(int num) {
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

int Infantry::personalNumber(int score) {
    int yearSum = 22;

    // Rút gọn score trước
    int scoreSum = 0;
    while (score > 0) {
        scoreSum += score % 10;
        score /= 10;
    }

    // Rút gọn từng phần riêng
    while (scoreSum >= 10) {
        int temp = 0;
        while (scoreSum > 0) {
            temp += scoreSum % 10;
            scoreSum /= 10;
        }
        scoreSum = temp;
    }

    while (yearSum >= 10) {
        int temp = 0;
        while (yearSum > 0) {
            temp += yearSum % 10;
            yearSum /= 10;
        }
        yearSum = temp;
    }

    int total = scoreSum + yearSum;

    // Rút gọn tổng cuối cùng
    while (total >= 10) {
        int temp = 0;
        while (total > 0) {
            temp += total % 10;
            total /= 10;
        }
        total = temp;
    }

    return total;
}

int Infantry::getAttackScore(bool donoth){
    int score = ceil(static_cast<int>(this->infantryType) * 56.0 + this->quantity * this->weight);

    cout << "\nScore: " << score;

    if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
        score += 75;
        cout << " -- Perfect -- " << score;
    }
    // SPECIALFORCES => duplicate personal perfect or NOT ???
    if(personalNumber(score) > 7){
        // cout << " (" << this->quantity << ") ";
        if(!donoth){
            this->quantity = static_cast<int>(ceil(this->quantity * 1.2));
        }
        
        
        // score = (static_cast<int>(this->infantryType) * 56 + this->quantity * this->weight);

        cout << " -- Personal7 -- " << score;
        // cout << " (" << this->quantity << ") ";

        // if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
        //     score += 75;
        //     // cout << " -- Perfect7 -- " << score;
        // }
    }else if(personalNumber(score) < 3){
        // cout << " (" << this->quantity << ") ";
        
        if(!donoth){
            this->quantity =  max(0, static_cast<int>(ceil(this->quantity * 0.9)));
        }
        // score = (static_cast<int>(this->infantryType) * 56 + this->quantity * this->weight);

        cout << " -- Personal3 -- " << score;
        // cout << " (" << this->quantity << ") ";

        // if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
        //     score += 75;
        //     // cout << " -- Perfect3 -- " << score;
        // }
    }

    score = ceil(static_cast<int>(this->infantryType) * 56.0 + this->quantity * this->weight);

    cout << " =>> ";

    return score;
}

bool Infantry::isVehicle() const {
    return false;
}
