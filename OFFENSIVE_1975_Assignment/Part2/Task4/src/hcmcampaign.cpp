#include "hcmcampaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////


// --------- POSITION CLASS IMPLEMENTATION ---------
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

// --------- UNIT CLASS IMPLEMENTATION (ABSTRACT) ---------
Unit::Unit(int quantity, int weight, Position pos) 
    : quantity(quantity), weight(weight), pos(pos) {}

Unit::~Unit() {}

int Unit::getScore() const{
    return this->unitScore;
}

void Unit::storeAttackScore(int attackScore){
    if(attackScore < 0){
        attackScore = 0;
    }
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
    int temp = static_cast<int>(ceil(this->weight * (1.0 - percent)));
    this->weight = temp;
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
    double temp = this->quantity * (1.0 - percent);
    this->quantity = static_cast<int>(ceil(temp));
    // cout << " - New: " << this->quantity;
}

// --------- VEHICLE CLASS IMPLEMENTATION ---------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType) {
        // cout << "vehicleType: " << vehicleType << endl;
    }

int Vehicle::getAttackScore(bool donoth){
    // string vehicleTypeStr;
    // switch (vehicleType) {
    //     case TRUCK: vehicleTypeStr = "TRUCK"; break;
    //     case MORTAR: vehicleTypeStr = "MORTAR"; break;
    //     case ANTIAIRCRAFT: vehicleTypeStr = "ANTIAIRCRAFT"; break;
    //     case ARMOREDCAR: vehicleTypeStr = "ARMOREDCAR"; break;
    //     case APC: vehicleTypeStr = "APC"; break;
    //     case ARTILLERY: vehicleTypeStr = "ARTILLERY"; break;
    //     case TANK: vehicleTypeStr = "TANK"; break;
    //     default: vehicleTypeStr = "UNKNOWN"; break;
    // }

    double score;

    if(donoth){
        score = this->unitScore;
    }else{
        score = (static_cast<int>(this->vehicleType) * 304.0 + this->quantity * this->weight) / 30.0;
    
        this->unitScore = static_cast<int>(ceil(score));
    } 
    
    return static_cast<int>(ceil(score));
}

string Vehicle::str() const{
    string vehicleTypeStr;
    switch (vehicleType) {
        case TRUCK: vehicleTypeStr = "TRUCK"; break;
        case MORTAR: vehicleTypeStr = "MORTAR"; break;
        case ANTIAIRCRAFT: vehicleTypeStr = "ANTIAIRCRAFT"; break;
        case ARMOREDCAR: vehicleTypeStr = "ARMOREDCAR"; break;
        case APC: vehicleTypeStr = "APC"; break;
        case ARTILLERY: vehicleTypeStr = "ARTILLERY"; break;
        case TANK: vehicleTypeStr = "TANK"; break;
        default: vehicleTypeStr = "UNKNOWN"; break;
    }
    stringstream ss;
    ss << "Vehicle[vehicleType=" << vehicleTypeStr  
       << ",quantity=" << this->quantity
       << ",weight=" << this->weight
       << ",position=" << this->pos.str() << "]";  
    return ss.str();
}

VehicleType Vehicle::getVehicleType() const{
    return this->vehicleType;
}

bool Vehicle::isVehicle() const {
    return true;
}

// --------- INFANTRY CLASS IMPLEMENTATION ---------
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

    // cout << "\nScore: " << score;
    if(donoth){
        score = this->unitScore;
    }else{
        if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
            score += 75;
            // cout << " -- Perfect -- " << score;
        }

        // cout << "personalNumber(score): " << personalNumber(score);
        if(personalNumber(score) > 7){
            // if(!donoth){
            //     this->quantity = static_cast<int>(ceil(this->quantity * 1.2));
            // }
            // cout << " => " << this->quantity;
            this->quantity = static_cast<int>(ceil(this->quantity * 1.2));
            // cout << " => " << this->str() << endl;
        }else if(personalNumber(score) < 3){
            // if(!donoth){
            //     this->quantity =  max(0, static_cast<int>(ceil(this->quantity * 0.9)));
            // }
            // cout << " => " << this->quantity;
            this->quantity =  max(0, static_cast<int>(ceil(this->quantity * 0.9)));
            // cout << " => " << this->str() << endl;
        }
        else{
            // cout << " => " << this->str() << endl;
        }

        score = ceil(static_cast<int>(this->infantryType) * 56.0 + this->quantity * this->weight);

        this->unitScore = score;
    }

    // cout << "Score: " << score << endl;

    return score;
}

bool Infantry::isVehicle() const {
    return false;
}

// --------- UNITLIST CLASS IMPLEMENTATION (LINKED LIST) ---------
UnitList::UnitList(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->count_infantry = 0;
    this->count_vehicle = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

UnitList::~UnitList(){
    while(this->head){
        UnitNode* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->tail = nullptr;
}

bool UnitList::insert(Unit *unit){
    // cout << "Go to ";
    if(unit == nullptr){
        return false;
    }

    // cout << "Insert! " << unit->str() << endl;

    bool isVehicle = unit->isVehicle();
    bool isInfantry = !isVehicle;

    if (isVehicle) {
        Vehicle* newVeh = dynamic_cast<Vehicle*>(unit);
        if (!newVeh) {
            // cout << "Invalid vehicle cast!" << endl;
            return false;
        }
        int vt = static_cast<int>(newVeh->getVehicleType());
        if (vt < TRUCK || vt > TANK) {
            return false;
        }
    } else {
        Infantry* newInf = dynamic_cast<Infantry*>(unit);
        if (!newInf) {
            // cout << "Invalid infantry cast!" << endl;
            return false;
        }
        int it = static_cast<int>(newInf->getInfantryType());
        if (it < SNIPER || it > REGULARINFANTRY) {
            return false;
        }
    }


    // cout << " Checked type: ";

    // Check if unit with same type already exists
    UnitNode* temp = head;
    while (temp) {
        if (isVehicle) {
            Vehicle* existVeh = dynamic_cast<Vehicle*>(temp->unit);
            Vehicle* newVeh = dynamic_cast<Vehicle*>(unit);
            if (existVeh && newVeh && existVeh->getVehicleType() == newVeh->getVehicleType()) {
                // cout << "V Existed! ";
                // cout << existVeh->getQuantity() << " ->> " << newVeh->getQuantity();
                // newVeh->getAttackScore();
                existVeh->increaseQuantity(unit->getQuantity());
                // cout << " =>> " << existVeh->getQuantity();
                if(newVeh->getWeight() > existVeh->getWeight()){
                    existVeh->setWeight(newVeh->getWeight());
                }
                existVeh->getAttackScore(); 
                return false;
            }
        } else if (isInfantry) {
            Infantry* existInf = dynamic_cast<Infantry*>(temp->unit);
            Infantry* newInf = dynamic_cast<Infantry*>(unit);
            if (existInf && newInf && existInf->getInfantryType() == newInf->getInfantryType()) {
                // cout << "I Existed! ";
                // newInf->getAttackScore(); 
                // cout << existInf->getQuantity() << " + " << newInf->getQuantity();
                existInf->increaseQuantity(unit->getQuantity());
                if(newInf->getWeight() > existInf->getWeight()){
                    existInf->setWeight(newInf->getWeight());
                }
                // cout << " = " << existInf->getQuantity() << endl;
                // cout << existInf->str();
                existInf->getAttackScore(); 
                // cout << " => " << existInf->getScore() << endl;
                return false;
            }
        }
        temp = temp->next;
    }

    // cout << "Not existed!";

    // If unit with same type doesn't exist, insert it
    if(this->size >= this->capacity){
        // cout << " Fail! " << this->capacity << "-" << this->size;
        return false;
    }

    UnitNode* newNode = new UnitNode(unit);
    if(this->size == 0){
        this->head = this->tail = newNode;
    }else if(isVehicle){
        this->tail->next = newNode;
        this->tail = newNode;
    }else if(isInfantry){
        newNode->next = this->head;
        this->head = newNode;
    }
    // cout << " Add new! " << newNode->unit->str();
    this->size++;

    if(isInfantry){
        count_infantry++;
    } 
    else if(isVehicle){
        count_vehicle++;
    }
    // cout << "Add new: " << unit->str() + " -> ";
    unit->getAttackScore();
    // cout << unit->str() << " - " << unit->getScore() << endl;
    
    return true;
}

bool UnitList::isContain(VehicleType vehicleType){
    UnitNode* temp = head;
    while (temp)
    {
        Vehicle* veh = dynamic_cast<Vehicle*>(temp->unit);
        if(veh && veh->getVehicleType() == vehicleType){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool UnitList::isContain(InfantryType infantryType){
    UnitNode* temp = head;
    while (temp)
    {
        Infantry* inf = dynamic_cast<Infantry*>(temp->unit);
        if(inf && inf->getInfantryType() == infantryType){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

string UnitList::str() const {
    stringstream ss;
    ss << "UnitList[count_vehicle=" << count_vehicle
       << ";count_infantry=" << count_infantry;

    UnitNode* temp = head;
    if (temp) {
        ss << ";";  
    }
    while (temp) {
        ss << temp->unit->str();
        if (temp->next) ss << ",";
        temp = temp->next;
    }
    
    ss << "]";
    return ss.str();
}

void UnitList::removeUnit(Unit* unit){
    UnitNode* prev = nullptr;
    UnitNode* curr = this->head;
    if(!curr){
        // cout << " NOT Found! \n";
    }
    while (curr)
    {
        if(curr->unit == unit){
            
            if (unit->isVehicle()){
                count_vehicle--;
                // cout << "Found vehicle!";
            }
            else{
                count_infantry--;
                // cout << "Found infantry!";
            }
            if(prev){
                prev->next = curr->next;
            }else{
                this->head = curr->next;
            }
            if(curr == tail){
                this->tail = prev;
            }
            // cout << " remove: " << curr->unit->str() << endl;
            delete curr;
            this->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
}

void UnitList::removeWeakUnits(){
    UnitNode* node = head;
    while (node)
    {
        UnitNode* next = node->next;
        if(node->unit->getScore() <= 5){
            // cout << "Remove: " << node->unit->str() << endl;
            removeUnit(node->unit);
            // cout << "done remove" << endl;
        }
        node = next;
    }
    // cout << "end remove weak" << endl;
}

UnitNode* UnitList::getHead() const{
    return this->head;
}

int UnitList::getSize() const{
    return this->size;
}

void UnitList::reduceWeight(double percent){
    UnitNode* temp = head;
    while (temp)
    {
        // cout << " weight: " << temp->unit->str();
        temp->unit->reduceWeight(percent);
        // cout << " reduced " << percent << " : " << temp->unit->getWeight() << endl;
        temp = temp->next;
    }
}

void UnitList::reduceQuantity(double percent){
    UnitNode* temp = head;
    while (temp)
    {
        temp->unit->reduceQuantity(percent);
        temp = temp->next;
    }
}

void UnitList::transferTo(UnitList* otherList){
    vector<Unit*> units;
    UnitNode* temp = head; 
    
    while (temp) {
        units.push_back(temp->unit);
        temp = temp->next;
    }

    for (int i = 0; i < (int)units.size(); ++i) {
        int idx = units.size() - 1 - i;
        otherList->insert(units[idx]);
        // cout << "Insert + Remove: " << units[idx]->str() << endl;
        removeUnit(units[idx]);
    }

    // cout << this->str() << endl;

    head = tail = nullptr;
    size = 0;
    count_vehicle = 0;
    count_infantry = 0;
}

// --------- ARMY CLASS IMPLEMENTATION (ABSTRACT) ---------
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

// --------- LIBERATIONARMY CLASS IMPLEMENTATION ---------
LiberationArmy::LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField)
                : Army(unitArray, size, name, battleField) {}

int LiberationArmy::getNearestFibonacci(int num){
    int a = 0, b = 1;
    while (b < num)
    {
        int temp = b;
        b = a + b;
        b = temp;
    }
    return b;
}

bool Army::findSmallest(int target, vector<Unit*>& selectedUnits, bool veh){
    vector<Unit*> thisUnits;

    UnitNode* node = this->unitList->getHead();
    while (node)
    {
        if ((veh && node->unit->isVehicle()) || (!veh && !node->unit->isVehicle())) {
            thisUnits.push_back(node->unit);
        }
        node = node->next;
    }
    
    // Bubble sort by attackScore ascending
    for (int i = 0; i < (int)thisUnits.size() - 1; i++)
    {
        for (int j = 0; j < (int)thisUnits.size() - i - 1; j++){
            if(thisUnits[j]->getScore() > thisUnits[j+1]->getScore()){
                // cout << thisUnits[j]->str() << endl;
                Unit* temp = thisUnits[j];
                thisUnits[j] = thisUnits[j+1];
                thisUnits[j+1] = temp;
            }
        }
    }

    // for (int i = 0; i < (int)thisUnits.size(); i++)
    // {
    //     cout << thisUnits[i]->str() << " - ";
    // }
    // cout << endl;
    
    int bestScore = INT_MAX;
    vector<Unit*> bestGroup;
    for(int i = 0; i < (int)thisUnits.size(); i++){
        int sum = 0;
        vector<Unit*> group;

        for(int j = i; j < (int)thisUnits.size(); j++){
            // cout << "CK: " << thisUnits[j]->str() << " -> ";
            sum += thisUnits[j]->getScore();
            // cout << thisUnits[j]->str() << endl;
            group.push_back(thisUnits[j]);
            
            if(sum >= target){
                // cout << " sum: " << sum << " tar: " << target;
                if(sum < bestScore){
                    bestScore = sum;
                    bestGroup = group;
                    // cout << " best score: " << bestScore;
                }
                break;
            }
        }
    }

    // cout << "\nBest group: ";
    // for (int i = 0; i < (int)bestGroup.size(); i++)
    // {
    //     cout << bestGroup[i]->str() << " - ";
    // }
    // cout << endl;

    if(!bestGroup.empty()){
        selectedUnits = bestGroup;
        return true;
    }
    
    return false;
}

void LiberationArmy::fight(Army* enemy, bool defense) {
    if(enemy == nullptr){
        return;
    }
    isBattle = false;
    // updateScore(true);
    // enemy->updateScore(true);
    if(!enemy){
        return;
    }
    if(defense){
        // cout << "LiberationArmy: Defense = true: ";
        this->EXP = ceil(this->EXP*1.3);
        this->LF = ceil(this->LF*1.3);

        

        if(this->LF >= enemy->getLF() && this->EXP >= enemy->getEXP()){
            this->LF = min(this->LF, 1000);
            this->EXP = min(this->EXP, 500);
            // cout << "Case 1: Winnn \n";
            return;
        } else if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
            // cout << "Case 2: Reduce 10% \n";
            this->unitList->reduceQuantity(0.1);
        } else {
            // cout << "Case 3: Need help \n";
            UnitNode* temp = this->unitList->getHead();
            while (temp) {
                int newQuantity = getNearestFibonacci(temp->unit->getQuantity());
                temp->unit->increaseQuantity(newQuantity);
                temp = temp->next;
            }
            // updateScore();

            // Continue ??? Again ???
            // if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
            //     return;
            // } else {
            //     this->unitList->reduceQuantity(0.1);
            //     updateScore();
            //     return;
            // }
        }
        this->updateScore();
    }else{
        // cout << "LiberationArmy: Defense = false: ";
        this->EXP = ceil(this->EXP*1.5);
        this->LF = ceil(this->LF*1.5);

        this->LF = min(this->LF, 1000);
        this->EXP = min(this->EXP, 500);

        vector<Unit*> groupA; // Inf mình > EXP enemy
        vector<Unit*> groupB; // Veh mình > LF enemy

        // cout << "\nTarget A (EXP - Inf): " << enemy->getEXP() << " - Target B (LF - Veh): " << enemy->getLF() << endl;

        // cout << "Gr A: ";
        bool foundA = findSmallest(enemy->getEXP(), groupA, false);
        // cout << "Gr B: ";
        bool foundB = findSmallest(enemy->getLF(), groupB, true);

        if(foundA && foundB){
            // cout << "Case 1: Win -> Remove \n";
            for(int i = 0; i < groupA.size(); i++){
                // cout << " GrA :";
                this->unitList->removeUnit(groupA[i]);
            }
            for(int i = 0; i < groupB.size(); i++){
                // cout << " GrB :" ;
                this->unitList->removeUnit(groupB[i]);
            }
            // isBattle = true;
            // cout << "Then liber: " << this->unitList->str() << " \n vs arvn: " << enemy->getUnitList()->str() << endl; 
        }else if(foundA && this->LF > enemy->getLF()){
            // cout << "Case 2.1: Fair but Win \n";
            for(int i = 0; i < groupA.size(); i++){
                this->unitList->removeUnit(groupA[i]);
            }
            UnitNode* node = this->unitList->getHead();
            while (node) {
                Unit* temp = node->unit;
                node = node->next;
                if (temp->isVehicle()){
                    this->unitList->removeUnit(temp);
                } 
            }
            // isBattle = true;
        }else if((foundB && this->EXP > enemy->getEXP())){
            // cout << "Case 2.2: Fair but Win \n";
            for(int i = 0; i < groupB.size(); i++){
                // cout << "remove: " << groupB[i]->str() << endl;
                this->unitList->removeUnit(groupB[i]);
            }
            UnitNode* node = this->unitList->getHead();
            while (node) {
                Unit* temp = node->unit;
                node = node->next;
                if (!temp->isVehicle()){
                    // cout << "remove: " << temp->str() << endl;
                    this->unitList->removeUnit(temp);
                } 
            }
            // isBattle = true;
            // cout << "Then liber: " << this->unitList->str() << " \n vs arvn: " << enemy->getUnitList()->str() << endl; 

        }else{
            // cout << "Case 3: No fight \n";
            this->unitList->reduceWeight(0.1);
            this->updateScore();
            // cout << "Liber LF: " << this->LF << " - Liber EXP: " << this->EXP << endl;
            // cout << "Enemy (EXP - Inf): " << enemy->getEXP() << " - Enemy (LF - Veh): " << enemy->getLF() << endl;
            isBattle = false;
            return;
        }

        enemy->getUnitList()->transferTo(unitList);
        // enemy->setLF(0);
        // enemy->setEXP(0);
        enemy->updateScore();
        this->updateScore();

        // cout << "Then liber: " << this->unitList->str() << " \n vs arvn: " << enemy->getUnitList()->str() << endl; 
    }
    // cout << endl;

    // cout << "Liber LF: " << this->LF << " - Liber EXP: " << this->EXP << endl;
    // cout << "Enemy (EXP - Inf): " << enemy->getEXP() << " - Enemy (LF - Veh): " << enemy->getLF() << endl;
}

bool LiberationArmy::isLiberation() const  {
    return true;
}

string LiberationArmy::str() const {
    return "LiberationArmy[LF=" + to_string(LF) + 
           ",EXP=" + to_string(EXP) + 
           ",unitList=" + unitList->str() + "," +
           (battleField ? ("battleField=" + battleField->str()) : "battleField=") + "]";
}

// --------- ARVN CLASS IMPLEMENTATION ---------
ARVN::ARVN(Unit** unitArray, int size, string name, BattleField* battleField)
    : Army(unitArray, size, name, battleField) {}

void ARVN::fight(Army* enemy, bool defense){
    if(enemy == nullptr){
        return;
    }
    // updateScore(true);
    // enemy->updateScore(true);
    if (!enemy->isLiberation()){
        return;
    } 

    if(defense){
        // cout << "ARVN: Defense = true: \n";
        // enemy->fight(this, false);

        vector<Unit*> groupA; // Inf mình > EXP enemy
        vector<Unit*> groupB; // Veh mình > LF enemy

        // cout << "\nTarget A (EXP - Inf): " << enemy->getEXP() << " - Target B (LF - Veh): " << enemy->getLF() << endl;

        // cout << "Gr A: ";
        bool foundA = enemy->findSmallest(this->getEXP(), groupA, false);
        // cout << "Gr B: ";
        bool foundB = enemy->findSmallest(this->getLF(), groupB, true);

        if(foundA && foundB){
        // if (enemy->isBattle) {
            // cout << "Case 1: Win" << endl;
            this->unitList->transferTo(enemy->getUnitList());
            // this->setLF(0);
            // this->setEXP(0);
            enemy->updateScore();
            this->updateScore();
        } else if((foundA && this->LF < enemy->getLF()) || (foundB && this->EXP < enemy->getEXP())){
            // cout << "Case 2: Fail" << endl;
            this->unitList->reduceWeight(0.2);
            this->updateScore();

            // cout << "ARVN LF: " << this->LF << " - ARVN EXP: " << this->EXP << endl;
            // cout << "Enemy EXP: " << enemy->getEXP() << " - Enemy LF: " << enemy->getLF() << endl;
            
        }else{
            // cout << "Case 1: No fight" << endl;
        }
        // this->updateScore();
    }else{
        // cout << "ARVN: Defense = false: \n";
        UnitNode* temp = this->unitList->getHead();
        while (temp)
        {
            UnitNode* next = temp->next;
            temp->unit->reduceQuantity(0.2);
            if(temp->unit->getQuantity() <= 1){
                this->unitList->removeUnit(temp->unit);
            }
            temp = next;
        }
        this->updateScore();
    }
}

bool ARVN::isLiberation() const  {
    return false;
}

string ARVN::str() const {
    // stringstream ss;
    // ss << "ARVN[LF=" << LF 
    //    << ",EXP=" << EXP 
    //    << ",unitList=" << unitList->str()
    //    << "," << (battleField ? battleField->str() : "battleField=") << "]";
    // return ss.str();
    return "ARVN[LF=" + to_string(LF) + 
           ",EXP=" + to_string(EXP) + 
           ",unitList=" + unitList->str() + "," +
           (battleField ? ("battleField=" + battleField->str()) : "battleField=") + "]";
}

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
    if(army == nullptr || army->getUnitList() == nullptr || army->getUnitList()->getHead() == nullptr){
        return;
    }
    bool isLiberation = army->isLiberation();
    double radius = isLiberation ? 2.0 : 4.0;
    double incrEXP = isLiberation ? 0.3 : 0.2;
    double descrLF = isLiberation ? 0.1 : 0.05;

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if (distance <= radius) {
            // cout << "Effect Mountain: " << node->unit->str() << endl;

            int score = node->unit->getScore();

            if (node->unit->isVehicle()) {
                double descr = ceil(score * descrLF);
                // cout << " => score: " << score << " - descrLF: " << descrLF << " => descr: " << descr << " => distance: " << distance << " => radius: " << radius << endl;

                int newLF = army->getLF() - static_cast<int>(descr);
                army->setLF(newLF);
            } else {
                double incr = ceil(score * 1.0 * incrEXP);
                // cout << " => score: " << score << " - incrEXP: " << incrEXP << " => incr: " << static_cast<int>(incr) << " => distance: " << distance << " => radius: " << radius << endl;

                int newEXP = army->getEXP() + static_cast<int>(incr);
                army->setEXP(newEXP);
            }
        }

        node = node->next;
    }
    
    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));
    // cout << "LF: " << army->getLF() << " - EXP: " << army->getEXP() << endl;
}

string Mountain::type() const { 
    return "Moun"; 
}

River::River(Position pos) : TerrainElement(pos) {}

void River::getEffect(Army* army){
    if(army == nullptr || army->getUnitList() == nullptr || army->getUnitList()->getHead() == nullptr){
        return;
    }
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 2){
            if(!(node->unit->isVehicle())){
                // cout << "Effect River: " << node->unit->str() << endl;
                double newScore = node->unit->getScore() * 0.9;
                // cout << "difference: " << node->unit->getScore() * 0.1 << endl;
                node->unit->storeAttackScore(static_cast<int>(ceil(newScore)));
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
    if(army == nullptr || army->getUnitList() == nullptr || army->getUnitList()->getHead() == nullptr){
        return;
    }
    bool isLiberation = army->isLiberation();

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(isLiberation){
            if(node->unit->isVehicle()){
                Vehicle* veh = dynamic_cast<Vehicle*>(node->unit);
                if(veh->getVehicleType() == ARTILLERY && distance <= 2){
                    // cout << "Effect urban: " << veh->str() << endl;
                    veh->storeAttackScore(veh->getScore() + static_cast<int>(ceil(veh->getScore() * 0.5)));
                }
            }else{
                Infantry* inf = dynamic_cast<Infantry*>(node->unit);
                if((inf->getInfantryType() == SPECIALFORCES || inf->getInfantryType() == REGULARINFANTRY) && distance <= 5){
                    // cout << "Effect urban: " << inf->str() << endl;
                    int delta = static_cast<int>(ceil((2.0 * node->unit->getScore()) / distance));
                    inf->storeAttackScore(inf->getScore() + delta);
                }
            }
        }else if(!node->unit->isVehicle()){
            Infantry* inf = dynamic_cast<Infantry*>(node->unit);
            if(inf->getInfantryType() == REGULARINFANTRY && distance <= 3){
                // cout << "Effect urban: " << inf->str() << endl;
                int delta = static_cast<int>(ceil((3 * node->unit->getScore()) / (2 * distance)));
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
    if(army == nullptr || army->getUnitList() == nullptr || army->getUnitList()->getHead() == nullptr){
        return;
    }
    bool isLiberation = army->isLiberation();

    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 2){
            // cout << "Effect Fort: " << node->unit->str() << endl;
            int delta = static_cast<int>(ceil(node->unit->getScore() * 0.2));
            // cout << " => delta: " << delta << " => node->unit->getScore(): " << node->unit->getScore() << endl;
            if(isLiberation){
                node->unit->storeAttackScore(node->unit->getScore() - delta);
            }else{
                node->unit->storeAttackScore(node->unit->getScore() + delta);
            }
            // cout << " => newScore: " << node->unit->getScore() << endl;
        }
        node = node->next;
    }
}

string Fortification::type() const { 
    return "Fort"; 
}

SpecialZone::SpecialZone(Position pos) : TerrainElement(pos) {}

void SpecialZone::getEffect(Army* army){
    if(army == nullptr || army->getUnitList() == nullptr || army->getUnitList()->getHead() == nullptr){
        return;
    }
    UnitNode* node = army->getUnitList()->getHead();
    while (node)
    {
        double distance = calculateDistance(node->unit->getCurrentPosition(), this->getPosition());
        if(distance <= 1){
            if(node->unit->isVehicle()){
                // cout << "Vehicle effected: " << node->unit->str() << " - " << node->unit->getScore() << endl;
                node->unit->storeAttackScore(0);
            }else{
                // cout << "Inf effected: " << node->unit->str()  << " - " << node->unit->getScore() << endl;
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

// --------- BATTLEFIELD CLASS IMPLEMENTATION ---------
BattleField::BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone) 
                : n_rows(n_rows), n_cols(n_cols) 
{
    // cout << "BattleField constructor called with n_rows=" << n_rows 
    //      << ", n_cols=" << n_cols << endl;

    if (n_rows <= 0 || n_cols <= 0) {
        // cout << "Invalid battlefield size." << endl;
        return;
    }

    // cout << "arrayForest size = " << (int)arrayForest.size() << endl;
    // cout << "arrayRiver size = " << (int)arrayRiver.size() << endl;
    // cout << "arrayFortification size = " << (int)arrayFortification.size() << endl;
    // cout << "arrayUrban size = " << (int)arrayUrban.size() << endl;
    // cout << "arraySpecialZone size = " << (int)arraySpecialZone.size() << endl;

    // cout << "[DEBUG] Creating TerrainElement..." << endl;
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = new Road(Position(i, j));
        }
    }
    
    // cout << "[DEBUG] Creating Mountain..." << endl;
    for (int i = 0; i < (int)arrayForest.size(); ++i){
        Position* pos = arrayForest[i];
        replaceTerrain(pos, new Mountain(*pos));
    }
        
    // cout << "[DEBUG] Creating River..." << endl;
    for (int i = 0; i < (int)arrayRiver.size(); ++i){
        Position* pos = arrayRiver[i];
        // cout << "pos: " << pos->str() << endl;
        replaceTerrain(pos, new River(*pos));
    }
        
    // cout << "[DEBUG] Creating Fortification..." << endl;
    for (int i = 0; i < (int)arrayFortification.size(); ++i){
        Position* pos = arrayFortification[i];
        replaceTerrain(pos, new Fortification(*pos));
    }
        
    // cout << "[DEBUG] Creating Urban..." << endl;
    for (int i = 0; i < (int)arrayUrban.size(); ++i){
        Position* pos = arrayUrban[i];
        replaceTerrain(pos, new Urban(*pos));
    }
        
    // cout << "[DEBUG] Creating SpecialZone..." << endl;
    for (int i = 0; i < (int)arraySpecialZone.size(); ++i){
        Position* pos = arraySpecialZone[i];
        replaceTerrain(pos, new SpecialZone(*pos));
    }    
}

void BattleField::replaceTerrain(Position* pos, TerrainElement* newTerrain) {
    int r = pos->getRow();
    int c = pos->getCol();
    if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
        delete terrain[r][c];
        terrain[r][c] = newTerrain;
    }
}

BattleField::~BattleField() {
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            delete terrain[i][j];
        }
        delete[] terrain[i];
    }
    delete[] terrain;
}

void BattleField::applyTerrainEffects(Army* army) {
    
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (terrain[i][j]) {
                terrain[i][j]->getEffect(army);
            }
        }
    }
}

string BattleField::str() const {
    stringstream ss;
    ss << "BattleField[n_rows=" << n_rows << ",n_cols=" << n_cols << "]";

    // cout << "Just for test: " << endl;
    // for (int i = 0; i < n_rows; ++i) {
    //     for (int j = 0; j < n_cols; ++j) {
    //         ss << terrain[i][j]->type() << "\t"; 
    //     }
    //     ss << "\n";
    // }
    return ss.str();
}

TerrainElement* BattleField::getElement(int r, int c) const {
    if (r < 0 || r >= n_rows || c < 0 || c >= n_cols)
        return nullptr;  
    return terrain[r][c];
}

// --------- CONFIGURATION CLASS IMPLEMENTATION ---------
void Configuration::extractPosition(const string& data, vector<Position*>& target) {
    if(data == "]" || data == " ]"){
        return;
    }
    stringstream ss(data);
    string pos;
    while (getline(ss, pos, ')')) {
        if (!pos.empty()) {
            pos += ")"; // restore the closing parenthesis
            target.push_back(new Position(pos));
            ss.ignore(); // skip comma
            // cout << "read: " << pos << endl;
        }
    }
    // for(int i = 0; i < (int)target.size(); i++){
    //     cout << "Check: " << target[i]->str() << " ";
    // }
    // cout << endl;
}

Configuration::Configuration(const string& filepath){
    // cout << "?????????????????" << endl;
    ifstream file(filepath.c_str());
    // if (!file.is_open()) {
    //     cout << "FAILED TO OPEN FILE: " << filepath << endl;
    //     return; // or handle the error appropriately
    // }
    string line;
    while (getline(file, line)){
        // cout << "can we getline" << endl;
        if(line.find("NUM_ROWS=") == 0){
            this->num_rows = stoi(line.substr(9));
        }else if(line.find("NUM_COLS=") == 0){
            this->num_cols = stoi(line.substr(9));
        }else if(line.find("ARRAY_FOREST=") == 0){
            // cout << "ARRAY_FOREST: ";
            extractPosition(line.substr(14), this->arrayForest);
            // for(int i = 0; i < (int)arrayForest.size(); i++){
            //     cout << "Check: " << arrayForest[i]->str() << " ";
            // }
        }else if(line.find("ARRAY_RIVER=") == 0){
            extractPosition(line.substr(13), this->arrayRiver);
        }else if(line.find("ARRAY_FORTIFICATION=") == 0){
            extractPosition(line.substr(21), this->arrayFortification);
        }else if(line.find("ARRAY_URBAN=") == 0){
            extractPosition(line.substr(13), this->arrayUrban);
        }else if(line.find("ARRAY_SPECIAL_ZONE=") == 0){
            extractPosition(line.substr(20), this->arraySpecialZone);
        }else if(line.find("UNIT_LIST=") == 0){
            string unitsStr = line.substr(10); // after UNIT_LIST=
            unitsStr = unitsStr.substr(1, unitsStr.length() - 2); // remove [ ]

            // cout << "hey: " << unitsStr << endl;
            
            vector<string> unitEntries;
            string current = "";
            int parenCount = 0;
            bool tp = false;

            for(int i = 0; i < (int)unitsStr.length(); i++){
                char ch = unitsStr[i];
                
                current += ch;

                if(ch == '('){
                    parenCount++;
                    tp = true;
                }else if(ch == ')'){
                    parenCount--;
                }

                // cout << ch << " pa:" << parenCount << " cur:" << current << " tp:" << tp << endl;

                if(parenCount == 0 && !current.empty() && tp){
                    tp = false;
                    unitEntries.push_back(current);
                    // cout << current << ":";
                    current = "";
                    if(i+1 < unitsStr.length() && unitsStr[i+1] == ','){
                        i++;
                    }
                }
            }

            for(int i = 0; i < (int)unitEntries.size(); i++){
                string entry = unitEntries[i];
                int pa1 = entry.find('(');
                int pa2 = entry.find_last_of(')');

                // cout << " halo: " << entry << ": " << pa1 << " - " << pa2;

                if(pa1 == string::npos || pa2 == string::npos){
                    continue;
                }

                // cout << "\nhalo: " << entry << ": " << pa1 << " - " << pa2;

                string type = entry.substr(0, pa1);
                string args = entry.substr(pa1 + 1, pa2 - pa1 - 1);

                // cout << " type: " << type;

                stringstream ss(args);
                string qua, wei, pos, own;
                char com;

                getline(ss, qua, ',');
                getline(ss, wei, ',');
                getline(ss, pos, ')');
                pos += ")";
                ss.ignore(); // skip comma
                getline(ss, own);

                // cout << " own: " << own;

                int quantity = stoi(qua);
                int weight = stoi(wei);
                Position position(pos);
                int owner = stoi(own);

                // cout << " - " << owner;

                Unit* unit = nullptr;

                if(type == "SNIPER"){
                    unit = new Infantry(quantity, weight, position, SNIPER);
                }else if(type == "ANTIAIRCRAFTSQUAD"){
                    unit = new Infantry(quantity, weight, position, ANTIAIRCRAFTSQUAD);
                }else if(type == "MORTARSQUAD"){
                    unit = new Infantry(quantity, weight, position, MORTARSQUAD);
                }else if(type == "ENGINEER"){
                    unit = new Infantry(quantity, weight, position, ENGINEER);
                }else if(type == "SPECIALFORCES"){
                    unit = new Infantry(quantity, weight, position, SPECIALFORCES);
                }else if(type == "REGULARINFANTRY"){
                    unit = new Infantry(quantity, weight, position, REGULARINFANTRY);
                }else if(type == "TRUCK"){
                    unit = new Vehicle(quantity, weight, position, TRUCK);
                }else if(type == "MORTAR"){
                    unit = new Vehicle(quantity, weight, position, MORTAR);
                }else if(type == "ANTIAIRCRAFT"){
                    unit = new Vehicle(quantity, weight, position, ANTIAIRCRAFT);
                }else if(type == "ARMOREDCAR"){
                    unit = new Vehicle(quantity, weight, position, ARMOREDCAR);
                }else if(type == "APC"){
                    unit = new Vehicle(quantity, weight, position, APC);
                }else if(type == "ARTILLERY"){
                    unit = new Vehicle(quantity, weight, position, ARTILLERY);
                }else if(type == "TANK"){
                    unit = new Vehicle(quantity, weight, position, TANK);
                }

                if(unit){
                    // cout << "Owner: " << owner;
                    if(owner){
                        ARVNUnits.push_back(unit);
                        // cout << " -> ARV okila ";
                    }else{
                        liberationUnits.push_back(unit);
                        // cout << " -> LBR okila ";
                    }
                    // cout << endl;
                }
            }
        }else if(line.find("EVENT_CODE=") == 0){
            this->eventCode = stoi(line.substr(11));
            // cout << this->eventCode << endl;
            if(this->eventCode <= 0){
                this->eventCode = 0;
            }else if(this->eventCode > 100){
                this->eventCode = this->eventCode % 100;
            }
            // cout << this->eventCode << endl;
        }
    }
    // cout << "arrayForest size = " << (int)arrayForest.size() << endl;
    // cout << "arrayRiver size = " << (int)arrayRiver.size() << endl;
    // cout << "arrayFortification size = " << (int)arrayFortification.size() << endl;
    // cout << "arrayUrban size = " << (int)arrayUrban.size() << endl;
    // cout << "arraySpecialZone size = " << (int)arraySpecialZone.size() << endl;

    file.close();
}

Configuration::~Configuration(){
    for(int i = 0; i < (int)arrayForest.size(); i++){
        delete arrayForest[i];
    }
    for(int i = 0; i < (int)arrayFortification.size(); i++){
        delete arrayFortification[i];
    }
    for(int i = 0; i < (int)arrayRiver.size(); i++){
        delete arrayRiver[i];
    }
    for(int i = 0; i < (int)arraySpecialZone.size(); i++){
        delete arraySpecialZone[i];
    }
    for(int i = 0; i < (int)arrayUrban.size(); i++){
        delete arrayUrban[i];
    }

    for(int i = 0; i < (int)liberationUnits.size(); i++){
        delete liberationUnits[i];
    }
    for(int i = 0; i < (int)ARVNUnits.size(); i++){
        delete ARVNUnits[i];
    }
}


int Configuration::getNumRows() const {
    return num_rows;
}

int Configuration::getNumCols() const {
    return num_cols;
}

const vector<Position*>& Configuration::getArrayForest() const {
    return arrayForest;
}

const vector<Position*>& Configuration::getArrayRiver() const {
    return arrayRiver;
}

const vector<Position*>& Configuration::getArrayFortification() const {
    return arrayFortification;
}

const vector<Position*>& Configuration::getArrayUrban() const {
    return arrayUrban;
}

const vector<Position*>& Configuration::getArraySpecialZone() const {
    return arraySpecialZone;
}

const vector<Unit*>& Configuration::getLiberationUnits() const {
    return liberationUnits;
}

const vector<Unit*>& Configuration::getARVNUnits() const {
    return ARVNUnits;
}

int Configuration::getEventCode() const {
    return eventCode;
}

string Configuration::printPositions(const string& label, const vector<Position*>& positions) const {
    stringstream ss;
    ss << "," << label << "=[";
    for (size_t i = 0; i < positions.size(); ++i) {
        ss << "(" << positions[i]->getRow() << "," << positions[i]->getCol() << ")";
        // cout << "(" << positions[i]->getRow() << "," << positions[i]->getCol() << ")\n";
        if (i < positions.size() - 1) {
            ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

string Configuration::str() const {
    stringstream ss;
    ss << "[";
    ss << "num_rows=" << num_rows;
    ss << ",num_cols=" << num_cols;

    // cout << "arrayForest: ";
    ss << printPositions("arrayForest", arrayForest);
    ss << printPositions("arrayRiver", arrayRiver);
    ss << printPositions("arrayFortification", arrayFortification);
    ss << printPositions("arrayUrban", arrayUrban);
    ss << printPositions("arraySpecialZone", arraySpecialZone);

    ss << ",liberationUnits=[";
    for (size_t i = 0; i < liberationUnits.size(); ++i) {
        ss << liberationUnits[i]->str();
        if (i < liberationUnits.size() - 1) ss << ",";
    }
    ss << "],ARVNUnits=[";
    for (size_t i = 0; i < ARVNUnits.size(); ++i) {
        ss << ARVNUnits[i]->str();
        if (i < ARVNUnits.size() - 1) ss << ",";
    }
    ss << "]";

    ss << ",eventCode=" << eventCode;
    ss << "]";

    return ss.str();
}

// --------- HCMCAMPAIGN CLASS IMPLEMENTATION ---------
HCMCampaign::HCMCampaign(const string& config_file_path){
    this->config = new Configuration(config_file_path);

    // cout << "HCMC: Configuration: " << this->config->str() << endl;

    // cout << "[DEBUG] Creating BattleField..." << endl;
    this->battleField = new BattleField(
        this->config->getNumRows(),
        this->config->getNumCols(),
        this->config->getArrayForest(),
        this->config->getArrayRiver(),
        this->config->getArrayFortification(),
        this->config->getArrayUrban(),
        this->config->getArraySpecialZone()
    );

    // cout << "[DEBUG] Creating LiberationArmy..." << endl;
    this->liberationArmy = new LiberationArmy(
        const_cast<Unit**>(this->config->getLiberationUnits().data()),
        this->config->getLiberationUnits().size(),
        "LiberationArmy",
        this->battleField
    );

    // cout << "[DEBUG] Creating ARVNArmy..." << endl;
    this->ARVNArmy = new ARVN(
        const_cast<Unit**>(this->config->getARVNUnits().data()),
        this->config->getARVNUnits().size(),
        "ARVN",
        this->battleField
    );

    // cout << "HCMC: BattleFile: " << this->battleField->str() << endl;
    // cout << "HCMC: LBRA: " << this->liberationArmy->str() << endl;
    // cout << "HCMC: ARVN: " << this->ARVNArmy->str() << endl;
}

HCMCampaign::~HCMCampaign() {
    delete liberationArmy;
    delete ARVNArmy;
    delete battleField;
    delete config;
}

void HCMCampaign::run() {
    this->battleField->applyTerrainEffects(liberationArmy);
    this->battleField->applyTerrainEffects(ARVNArmy);

    if(this->config->getEventCode() < 75){
        liberationArmy->fight(ARVNArmy, false);  // attacker
        // cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        // cout << "PRINT: ARVN: " << this->ARVNArmy->str() << endl;
        ARVNArmy->fight(liberationArmy, true);   // defender
        // cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        // cout << "PRINT: ARVN: " << this->ARVNArmy->str() << endl;
    }else{
        ARVNArmy->fight(liberationArmy, false);  // attacker
        // cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        // cout << "PRINT: ARVN: " << this->ARVNArmy->str() << endl;
        liberationArmy->fight(ARVNArmy, false);   // counterattack
        // cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        // cout << "PRINT: ARVN: " << this->ARVNArmy->str() << endl;
    }

    liberationArmy->getUnitList()->removeWeakUnits();
    ARVNArmy->getUnitList()->removeWeakUnits();

    // cout << "REMOVED: LBRA: " << this->liberationArmy->str() << endl;
    // cout << "REMOVED: ARVN: " << this->ARVNArmy->str() << endl;

    liberationArmy->updateScore();
    ARVNArmy->updateScore();
}

string HCMCampaign::printResult(){
    // cout << "PRINT: BattleFile: " << this->battleField->str() << endl;
    // cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
    // cout << "PRINT: ARVN: " << this->ARVNArmy->str() << endl;

    return "LIBERATIONARMY[LF=" + to_string(liberationArmy->getLF()) +
           ",EXP=" + to_string(liberationArmy->getEXP()) + "]-" +
           "ARVN[LF=" + to_string(ARVNArmy->getLF()) +
           ",EXP=" + to_string(ARVNArmy->getEXP()) + "]";
}

Configuration* HCMCampaign::getConfig() const {
    return config;
}

BattleField* HCMCampaign::getBattleField() const {
    return battleField;
}

LiberationArmy* HCMCampaign::getLiberationArmy() const {
    return liberationArmy;
}

ARVN* HCMCampaign::getARVNArmy() const {
    return ARVNArmy;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////