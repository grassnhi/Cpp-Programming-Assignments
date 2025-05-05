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

using namespace std;

// --------- POSITION CLASS IMPLEMENTATION ---------
class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos); // Example: str_pos = "(1,15)"
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const; // Example: returns "(1,15)"
};

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
class Unit
{
protected:
    int quantity, weight;
    Position pos;

public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0; // must be overridden by derived classes
    Position getCurrentPosition() const;
    virtual string str() const = 0; // Pure virtual functions cannot have an implementation in the base class
    
    int getWeight() const;
    void setWeight(int w);
    void reduceWeight(double percent);

    int getQuantity() const;  
    void setQuantity(int q);
    void increaseQuantity(int amount); 
    void reduceQuantity(double percent);

    virtual bool isVehicle() const = 0;
};

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
enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};

class Vehicle : public Unit {
private:
    VehicleType vehicleType;
public:
    Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType);
    int getAttackScore() override;
    string str() const override;
    VehicleType getVehicleType() const;
    bool isVehicle() const override;
};

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
enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Infantry : public Unit {
private:
    InfantryType infantryType;

public:
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);
    int getAttackScore() override;
    string str() const override;
    InfantryType getInfantryType() const;  // Getter for InfantryType
    int personalNumber(int score);
    bool isPerfectSquare(int num);
    bool isVehicle() const override;
};

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
class UnitNode {
public:
    Unit* unit;
    UnitNode* next;
    
    UnitNode(Unit* unit) : unit(unit), next(nullptr) {}
};

class UnitList
{
private:
    int capacity;
    // TODO
    int size;
    int count_vehicle;
    int count_infantry;
    UnitNode* head;
    UnitNode* tail;
public:
    UnitList(int capacity);
    bool insert(Unit *unit);                   
    bool isContain(VehicleType vehicleType);   
    bool isContain(InfantryType infantryType); 
    string str() const;
    // TODO
    ~UnitList();
    void removeUnit(Unit* unit);
    void reduceWeight(double percent);
    void reduceQuantity(double percent);
    void transferTo(UnitList* otherList);

    UnitNode* getHead() const;
    int getSize() const;

    bool isSpecialNumber(int S);
};

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
class BattleField;

class Army
{
protected:
    int LF, EXP;
    string name;
    UnitList *unitList;
    BattleField *battleField;

public:
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;

    virtual ~Army();
    virtual bool isLiberation() const = 0;

    int getLF() const;
    int getEXP() const;
    void setLF(int value);
    void setEXP(int value);

    void updateScore();

    UnitList* getUnitList() const;
};

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
class LiberationArmy : public Army {
public:
    LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;

    bool isLiberation() const override;

private:
    int getNearestFibonacci(int num);
    bool findSmallest(int target, vector<Unit*>& selectedUnits); 
};

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
class ARVN : public Army {
public:
    ARVN(Unit** unitArray, int size, string name, BattleField* battleField);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;

    bool isLiberation() const override;
};

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
class TerrainElement
{
private:
    Position position;
public:
    TerrainElement();
    TerrainElement(Position pos); 
    ~TerrainElement();
    virtual void getEffect(Army *army) = 0;
    Position getPosition() const;
};

TerrainElement::TerrainElement() {}

TerrainElement::TerrainElement(Position pos) : position(pos) {}

TerrainElement::~TerrainElement() {}

Position TerrainElement::getPosition() const {
    return this->position;
}

// --------- INDIVIDUAL TERRAIN CLASSES IMPLEMENTATION ---------
class Road : public TerrainElement {
public:
    Road(Position pos);
    void getEffect(Army* army) override;
};

Road::Road(Position pos) : TerrainElement(pos) {}

void Road::getEffect(Army* army) {
    // No effect
    cout << "No effect" << endl;
}

class Mountain : public TerrainElement {
public:
    Mountain(Position pos);
    void getEffect(Army* army) override;
};

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

class River : public TerrainElement {
public:
    River(Position pos);
    void getEffect(Army* army) override;
};

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

class Urban : public TerrainElement {
public:
    Urban(Position pos);
    void getEffect(Army* army) override;
};

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

class Fortification : public TerrainElement {
public:
    Fortification(Position pos);
    void getEffect(Army* army) override;
};

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

class SpecialZone : public TerrainElement {
public:
    SpecialZone(Position pos);
    void getEffect(Army* army) override;
};

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

// --------- BATTLEFIELD CLASS IMPLEMENTATION ---------
class BattleField
{
private:
    int n_rows, n_cols;
    // TODO
    TerrainElement*** terrain;
public:
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();

    void replaceTerrain(Position* pos, TerrainElement* newTerrain);
    void applyTerrainEffects(Army* army);
    string str() const;
};

BattleField::BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone) 
                : n_rows(n_rows), n_cols(n_cols) 
{
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
    ss << "BattleField[n_rows=" << n_rows << ",n_cols=" << n_cols << "]";

    cout << "Just for test: ";
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            ss << terrain[i][j] << "\t";  // Abbreviated for clarity
        }
        ss << "\n";
    }
    return ss.str();
}
