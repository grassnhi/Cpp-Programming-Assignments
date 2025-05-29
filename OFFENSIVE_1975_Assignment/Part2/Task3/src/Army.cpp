#include "Army.h"
#include "BattleField.h"

bool Army::isSpecialNumber(int S) {
    // Check for each prime: 3, 5, 7
    int primes[] = {3, 5, 7}; 

    for (int i = 0; i < 3; ++i) {
        int k = primes[i];

        // cout << "\n>> Checking with base: " << k << endl;

        vector<int> powers; // To store powers of k: k^0, k^1, k^2, ...
        int power = 1;

        // Generate powers of k that are ≤ S
        // cout << "Generated powers of " << k << ": ";
        while (power <= S / k) { 
            // cout << power << " ";
            powers.push_back(power);
            power *= k;
        }
        powers.push_back(power); // include the last power 
        // cout << power << endl;

        int n = powers.size();
        int limit = (1 << n); // total subsets = 2^n

        // Try every subset using bitmask: mask as an n-bit binary number.
        // Each bit (0 or 1) indicates whether to include a specific power in the current subset.
        for (int mask = 0; mask < limit; ++mask) {
            int sum = 0;

            // cout << "  Mask " << mask << ": ";
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) { 
                    sum += powers[j];
                    // cout << powers[j] << " ";
                    if (sum > S) break;  
                }
            }

            // cout << "=> sum = " << sum << endl;

            // Check if this subset gives exact sum
            if (sum == S) {
                // cout << "  --> Found match with base " << k << "!" << endl;
                return true;
            }
        }
    }

    // cout << "  --> No match found for " << S << endl;
    return false;
}

Army::Army(Unit **unitArray, int size, string name, BattleField *battleField){
    this->name = name;
    this->battleField = battleField;
    this->LF = 0;
    this->EXP = 0;

    Unit** copyArray = new Unit*[size];
    for (int i = 0; i < size; i++) {
        if (unitArray[i]->isVehicle()) {
            copyArray[i] = new Vehicle(*(Vehicle*)unitArray[i]);  
        } else {
            copyArray[i] = new Infantry(*(Infantry*)unitArray[i]);  
        }
    }

    for (int i = 0; i < size; i++) {
        if (copyArray[i]->isVehicle()) {
            this->LF += copyArray[i]->getAttackScore();  
        } else {
            this->EXP += copyArray[i]->getAttackScore();
        }
    }

    this->LF = min(this->LF, 1000);
    this->EXP = min(this->EXP, 500);

    int S = this->LF + this->EXP;
    // cout << " S = " << S << endl;
    int capacity = isSpecialNumber(S) ? 12 : 8;

    this->unitList = new UnitList(capacity); 

    for(int i = 0; i < size; i++){
        this->unitList->insert(unitArray[i]);
    }

    for (int i = 0; i < size; i++) {
        delete copyArray[i];
    }
    delete[] copyArray;
}

Army::~Army(){
    UnitNode* temp = unitList->getHead();

    while (temp)
    {
        UnitNode* next = temp->next;
        delete temp;
        temp = next;
    }
}

int Army::getLF() const{
    return this->LF;
}

int Army::getEXP() const{
    return this->EXP;
}

void Army::setLF(int value){
    this->LF = value;
}

void Army::setEXP(int value){
    this->EXP = value;
}

void Army::updateScore(){
    this->LF = 0;
    this->EXP = 0;

    UnitNode* temp = unitList->getHead();
    while (temp)
    {
        if(temp->unit->isVehicle()){
            // cout << "\nveh attack:";
            this->LF += temp->unit->getAttackScore();
            // cout << "LF: " << this->LF << endl;
        }else{
            // cout << "\ninf attack:";
            this->EXP += temp->unit->getAttackScore();
            // cout << "EXP: " << this->EXP << endl;
        }
        temp = temp->next;
    }
    LF = min(LF, 1000);
    EXP = min(EXP, 500);
}

UnitList* Army::getUnitList() const{
    return this->unitList;
}

BattleField* Army::getBattleField() const{
    return this->battleField;
}
