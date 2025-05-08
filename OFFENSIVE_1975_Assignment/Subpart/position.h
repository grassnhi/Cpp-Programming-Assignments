#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "header.h"

using namespace std;

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
    this->quantity *= (1 - percent);
}

class Test_unit : public Unit {
public:
    Test_unit(int quantity, int weight, Position pos) 
        : Unit(quantity, weight, pos) {}

    ~Test_unit() {}

    int getAttackScore() {
        return this->quantity * this->weight; // dummy formula
    }

    string str() const {
        stringstream ss;
        ss << "quantity=" << this->quantity
        << ",weight=" << this->weight
        << ",pos=" << this->pos.str();  
        return ss.str();
    }

    bool isVehicle() const{
        return false;
    }
};

// --------- VEHICLE CLASS IMPLEMENTATION ---------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType) {}

int Vehicle::getAttackScore(){
    return (static_cast<int>(this->vehicleType) * 304 + this->quantity * this->weight) / 30;
}

string Vehicle::str() const{
    stringstream ss;
    ss << "Vehicle[vehicleType=" << static_cast<int>(vehicleType)  // Convert enum to int
       << ",quantity=" << this->quantity
       << ",weight=" << this->weight
       << ",pos=" << this->pos.str() << "]";  
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
    stringstream ss;
    ss << "Infantry[infantryType=" << static_cast<int>(this->infantryType)  // Convert enum to int
       << ",quantity=" << this->quantity
       << ",weight=" << this->weight
       << ",pos=" << this->pos.str() << "]";  
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
    int yearSum = 1 + 9 + 7 + 5;

    int scoreSum = 0;
    int temp = score;
    while (temp > 0) {
        scoreSum += temp % 10;  
        temp /= 10;             
    }

    int sum = scoreSum + yearSum;
    while (sum >= 10) {
        int tempSum = 0;
        while (sum > 0) {
            tempSum += sum % 10;
            sum /= 10;
        }
        sum = tempSum;
    }

    return sum; 
}

int Infantry::getAttackScore(){
    int score = (static_cast<int>(this->infantryType) * 56 + this->quantity * this->weight);

    // cout << "Score: " << score;

    if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
        score += 75;
        // cout << " -- Perfect -- " << score;
    }
    // SPECIALFORCES => duplicate personal perfect or NOT ???
    if(personalNumber(score) > 7){
        // cout << " (" << this->quantity << ") ";
        this->quantity = static_cast<int>(ceil(this->quantity * 1.2));
        
        score = (static_cast<int>(this->infantryType) * 56 + this->quantity * this->weight);

        // cout << " -- Personal7 -- " << score;
        cout << " (" << this->quantity << ") ";

        if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
            score += 75;
            // cout << " -- Perfect7 -- " << score;
        }
    }else if(personalNumber(score) < 3){
        // cout << " (" << this->quantity << ") ";
        this->quantity =  max(0, static_cast<int>(ceil(this->quantity * 0.9)));
        
        score = (static_cast<int>(this->infantryType) * 56 + this->quantity * this->weight);

        // cout << " -- Personal3 -- " << score;
        // cout << " (" << this->quantity << ") ";

        if (this->infantryType == SPECIALFORCES && isPerfectSquare(this->weight)) {
            score += 75;
            // cout << " -- Perfect3 -- " << score;
        }
    }

    // cout << " =>> ";

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
    if(this->size >= this->capacity){
        // cout << " Fail! " << this->capacity << "-" << this->size;
        return false;
    }

    bool isVehicle = (dynamic_cast<Vehicle*>(unit) != nullptr);
    bool isInfantry = (dynamic_cast<Infantry*>(unit) != nullptr);

    // Check if unit with same type already exists
    UnitNode* temp = head;
    while (temp) {
        if (isVehicle) {
            Vehicle* existVeh = dynamic_cast<Vehicle*>(temp->unit);
            Vehicle* newVeh = dynamic_cast<Vehicle*>(unit);
            if (existVeh && newVeh && existVeh->getVehicleType() == newVeh->getVehicleType()) {
                existVeh->increaseQuantity(unit->getQuantity());
                // cout << " Existed! ";
                return true;
            }
        } else if (isInfantry) {
            Infantry* existInf = dynamic_cast<Infantry*>(temp->unit);
            Infantry* newInf = dynamic_cast<Infantry*>(unit);
            if (existInf && newInf && existInf->getInfantryType() == newInf->getInfantryType()) {
                existInf->increaseQuantity(unit->getQuantity());
                // cout << " Existed! ";
                return true;
            }
        }
        temp = temp->next;
    }

    // If unit with same type doesn't exist, insert it
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
    // cout << " Add new! ";
    this->size++;

    if(isInfantry){
        count_infantry++;
    } 
    else if(isVehicle){
        count_vehicle++;
    }
    
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

bool UnitList::isSpecialNumber(int S) {
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


string UnitList::str() const {
    stringstream ss;
    ss << "UnitList[count_vehicle=" << count_vehicle
       << ";count_infantry=" << count_infantry << ";";

    UnitNode* temp = head;
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
            delete curr;
            this->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    // cout << "NOT Found!";
}

void UnitList::removeWeakUnits(){
    UnitNode* node = head;
    while (node)
    {
        if(node->unit->getAttackScore() <= 5){
            removeUnit(node->unit);
        }
        node = node->next;
    }
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
        temp->unit->reduceWeight(percent);
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
    UnitNode* temp = head; 
    
    while (temp) {
        UnitNode* next = temp->next;  
        otherList->insert(temp->unit);
        // cout << " Done insert! ";
        removeUnit(temp->unit);
        // cout << " Done remove! " << endl;
        temp = next;
    }

    head = tail = nullptr;
    size = 0;
    count_vehicle = 0;
    count_infantry = 0;
}

// --------- ARMY CLASS IMPLEMENTATION (ABSTRACT) ---------


Army::Army(Unit **unitArray, int size, string name, BattleField *battleField){
    this->name = name;
    this->battleField = battleField;
    this->LF = 0;
    this->EXP = 0;

    this->unitList = new UnitList(size*5); 
    // Khúc này bug vì cái size nè
    // cout << "Create " << endl;
    for(int i = 0; i < size; i++){
        // cout << "Insert ";
        this->unitList->insert(unitArray[i]);
        // cout << i << " ";
        if(unitArray[i]->isVehicle()){
            this->LF += unitArray[i]->getAttackScore();
            // cout << "isVehicle ";
        }else{
            this->EXP += unitArray[i]->getAttackScore();
            // cout << "isInfantry ";
        }
        // cout << "done " << endl;
    }

    this->LF = min(this->LF, 1000);
    this->EXP = min(this->EXP, 500);
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
            this->LF += temp->unit->getAttackScore();
        }else{
            this->EXP += temp->unit->getAttackScore();
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

class Test_army : public Army {
public:
    Test_army(Unit** unitArray, int size, string name, BattleField* battleField)
    : Army(unitArray, size, name, battleField){}

    void fight(Army* enemy, bool defense = false){
        if(defense){
            enemy->getUnitList()->transferTo(this->unitList);
        }else{
            this->unitList->transferTo(enemy->getUnitList());
        }
    }

    bool isLiberation() const{
        return false;
    }

    string str() const{
        cout << "Test Army" << endl;
    }
};

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

bool LiberationArmy::findSmallest(int target, vector<Unit*>& selectedUnits){
    vector<Unit*> thisUnits;

    UnitNode* node = this->unitList->getHead();
    while (node)
    {
        thisUnits.push_back(node->unit);
        node = node->next;
    }
    
    for (int i = 0; i < (int)thisUnits.size() - 1; i++)
    {
        for (int j = 0; (int)thisUnits.size() - i - 1; i++){
            if(thisUnits[j]->getAttackScore() > thisUnits[j+1]->getAttackScore()){
                Unit* temp = thisUnits[j];
                thisUnits[j] = thisUnits[j+1];
                thisUnits[j+1] = temp;
            }
        }
    }
    
    int bestScore = INT_MAX;
    vector<Unit*> bestGroup;
    for(int i = 0; i < thisUnits.size(); i++){
        int sum = 0;
        vector<Unit*> group;

        for(int j = i; j < thisUnits.size(); j++){
            sum += thisUnits[j]->getAttackScore();
            group.push_back(thisUnits[j]);

            if(sum >= target){
                if(sum < bestScore){
                    bestScore = sum;
                    bestGroup = group;
                }
                break;
            }
        }
    }

    if(!bestGroup.empty()){
        selectedUnits = bestGroup;
        return true;
    }
    
    return false;
}

void LiberationArmy::fight(Army* enemy, bool defense) {
    if(!enemy){
        return;
    }
    if(defense){
        this->EXP *= 1.3;
        this->LF *= 1.3;

        if(this->LF >= enemy->getLF() && this->EXP >= enemy->getEXP()){
            return;
        } else if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
            this->unitList->reduceQuantity(0.1);
        } else {
            UnitNode* temp = this->unitList->getHead();
            while (temp) {
                int newQuantity = getNearestFibonacci(temp->unit->getQuantity());
                temp->unit->increaseQuantity(newQuantity);
                temp = temp->next;
            }
            updateScore();

            // Continue ??? Again ???
            if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
                return;
            } else {
                this->unitList->reduceQuantity(0.1);
                updateScore();
                return;
            }
        }
    }else{
        this->EXP *= 1.5;
        this->LF *= 1.5;

        vector<Unit*> groupA;
        vector<Unit*> groupB;

        bool foundA = findSmallest(enemy->getEXP(), groupA);
        bool foundB = findSmallest(enemy->getLF(), groupB);

        if(foundA && foundB){
            for(int i = 0; i < groupA.size(); i++){
                this->unitList->removeUnit(groupA[i]);
            }
            for(int i = 0; i < groupB.size(); i++){
                this->unitList->removeUnit(groupB[i]);
            }
        }else if(foundA && this->EXP > enemy->getEXP()){
            for(int i = 0; i < groupA.size(); i++){
                this->unitList->removeUnit(groupA[i]);
            }
        }else if((foundB && this->LF > enemy->getLF())){
            for(int i = 0; i < groupB.size(); i++){
                this->unitList->removeUnit(groupB[i]);
            }
        }else{
            this->unitList->reduceWeight(0.1);
            updateScore();
            return;
        }

        enemy->getUnitList()->transferTo(unitList);
        updateScore();
    }
}

bool LiberationArmy::isLiberation() const  {
    return true;
}

string LiberationArmy::str() const {
    return "LiberationArmy[name=" + name + 
           ",LF=" + to_string(LF) + 
           ",EXP=" + to_string(EXP) + "," + 
           unitList->str() + "," +
           (battleField ? battleField->str() : "BattleField[null]") + "]";
}

// --------- ARVN CLASS IMPLEMENTATION ---------


ARVN::ARVN(Unit** unitArray, int size, string name, BattleField* battleField)
    : Army(unitArray, size, name, battleField) {}

void ARVN::fight(Army* enemy, bool defense){
    if (!enemy->isLiberation()){
        return;
    } 

    if(defense){
        if (enemy->getLF() >= this->LF && enemy->getEXP() >= this->EXP) {
            this->unitList->transferTo(enemy->getUnitList());
        } else {
            this->unitList->reduceWeight(0.2);
        }
        this->updateScore();
    }else{
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
        updateScore();
    }
}

bool ARVN::isLiberation() const  {
    return false;
}

string ARVN::str() const {
    stringstream ss;
    ss << "ARVN[name=" << name 
       << ",LF=" << LF 
       << ",EXP=" << EXP 
       << ",unitList=" << unitList->str()
       << "," << (battleField ? battleField->str() : "BattleField[null]") << "]";
    return ss.str();
}

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

// --------- BATTLEFIELD CLASS IMPLEMENTATION ---------


BattleField::BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone) 
                : n_rows(n_rows), n_cols(n_cols) 
{
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = new Road(Position(i, j));
        }
    }

    for (int i = 0; i < (int)arrayForest.size(); ++i){
        Position* pos = arrayForest[i];
        replaceTerrain(pos, new Mountain(*pos));
    }
        
    for (int i = 0; i < (int)arrayRiver.size(); ++i){
        Position* pos = arrayRiver[i];
        replaceTerrain(pos, new River(*pos));
    }
        
    for (int i = 0; i < (int)arrayFortification.size(); ++i){
        Position* pos = arrayFortification[i];
        replaceTerrain(pos, new Fortification(*pos));
    }
        
    for (int i = 0; i < (int)arrayUrban.size(); ++i){
        Position* pos = arrayUrban[i];
        replaceTerrain(pos, new Urban(*pos));
    }
        
    for (int i = 0; i < (int)arraySpecialZone.size(); ++i){
        Position* pos = arraySpecialZone[i];
        replaceTerrain(pos, new SpecialZone(*pos));
    }    
}

void BattleField::replaceTerrain(Position* pos, TerrainElement* newTerrain) {
    int r = pos->getRow();
    int c = pos->getCol();
    delete terrain[r][c];
    terrain[r][c] = newTerrain;
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
    ss << "BattleField[n_rows=" << n_rows << ",n_cols=" << n_cols << "]" << endl;

    cout << "Just for test: " << endl;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            ss << terrain[i][j]->type() << "\t"; 
        }
        ss << "\n";
    }
    return ss.str();
}

// --------- CONFIGURATION CLASS IMPLEMENTATION ---------
void Configuration::extractPosition(const string& data, vector<Position*>& target) {
    stringstream ss(data);
    string pos;
    while (getline(ss, pos, ')')) {
        if (!pos.empty()) {
            pos += ")"; // restore the closing parenthesis
            target.push_back(new Position(pos));
            ss.ignore(); // skip comma
        }
    }
}

Configuration::Configuration(const string& filepath){
    ifstream file(filepath.c_str());
    string line;
    while (getline(file, line)){
        if(line.find("NUM_ROWS=") == 0){
            this->num_rows = stoi(line.substr(9));
        }else if(line.find("NUM_COLS=") == 0){
            this->num_cols = stoi(line.substr(9));
        }else if(line.find("ARRAY_FOREST=") == 0){
            extractPosition(line.substr(13), this->arrayForest);
        }else if(line.find("ARRAY_RIVER=") == 0){
            extractPosition(line.substr(12), this->arrayRiver);
        }else if(line.find("ARRAY_FORTIFICATION=") == 0){
            extractPosition(line.substr(21), this->arrayFortification);
        }else if(line.find("ARRAY_URBAN=") == 0){
            extractPosition(line.substr(12), this->arrayUrban);
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

            file.close();

        }else if(line.find("EVENT_CODE=") == 0){
            this->eventCode = stoi(line.substr(11));
            if(this->eventCode <= 0){
                this->eventCode = 0;
            }else{
                this->eventCode = this->eventCode % 100;
            }
        }
    }
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

string Configuration::str() const {
    stringstream ss;
    ss << "Configuration[\n";
    ss << "NUM_ROWS=" << num_rows << "\n";
    ss << "NUM_COLS=" << num_cols << "\n";
    ss << "EVENT_CODE=" << eventCode << "\n";
    ss << "UNIT_LIST=[";
    cout << "Size: " << liberationUnits.size() << " - " << ARVNUnits.size() << endl;
    for (int i = 0; i < (int)liberationUnits.size(); ++i) {
        ss << liberationUnits[i]->str();
        if (i < liberationUnits.size() - 1 || !ARVNUnits.empty()) ss << ",";
    }
    for (int i = 0; i < (int)ARVNUnits.size(); ++i) {
        ss << ARVNUnits[i]->str();
        if (i < ARVNUnits.size() - 1) ss << ",";
    }
    ss << "]\n]";
    return ss.str();
}

// --------- HCMCAMPAIGN CLASS IMPLEMENTATION ---------
HCMCampaign::HCMCampaign(const string& config_file_path){
    this->config = new Configuration(config_file_path);

    this->battleField = new BattleField(  
        this->config->getNumRows(),
        this->config->getNumCols(),
        this->config->getArrayForest(),
        this->config->getArrayRiver(),
        this->config->getArrayFortification(),
        this->config->getArrayUrban(),
        this->config->getArraySpecialZone()
    );

    this->liberationArmy = new LiberationArmy(
        const_cast<Unit**>(this->config->getLiberationUnits().data()),
        this->config->getLiberationUnits().size(),
        "LiberationArmy",
        this->battleField
    );

    this->ARVNArmy = new ARVN(
        const_cast<Unit**>(this->config->getARVNUnits().data()),
        this->config->getARVNUnits().size(),
        "ARVN",
        this->battleField
    );
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
        ARVNArmy->fight(liberationArmy, true);   // defender
    }else{
        ARVNArmy->fight(liberationArmy, false);  // attacker
        liberationArmy->fight(ARVNArmy, true);   // counterattack
    }

    liberationArmy->getUnitList()->removeWeakUnits();
    ARVNArmy->getUnitList()->removeWeakUnits();
}

string HCMCampaign::printResult(){
    return "LIBERATIONARMY[LF=" + to_string(liberationArmy->getLF()) +
           ",EXP=" + to_string(liberationArmy->getEXP()) + "] - " +
           "ARVNArmy[LF=" + to_string(ARVNArmy->getLF()) +
           ",EXP=" + to_string(ARVNArmy->getEXP()) + "]";
}