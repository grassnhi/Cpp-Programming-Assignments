#include "hcmcampaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////

  
// --------- POSITION CLASS IMPLEMENTATION ---------
Position::Position(int r, int c) : r(r), c(c) {}

Position::Position(const string &str_pos) {
    char dummy;
    stringstream ss(str_pos);
    ss >> dummy >> r >> dummy >> c >> dummy;
}

int Position::getRow() const{
    return r;
}

int Position::getCol() const{
    return c;
}

void Position::setRow(int r){
    this->r = r;
}

void Position::setCol(int c){
    this->c = c;
}

string Position::str() const{
    return "(" + to_string(r) + "," + to_string(c) + ")";
}
  
// --------- UNIT CLASS IMPLEMENTATION (ABSTRACT) ---------
Unit::Unit(int quantity, int weight, Position pos) 
    : quantity(quantity), weight(weight), pos(pos) {}

Unit::~Unit() {}

Position Unit::getCurrentPosition() const { 
    return pos; 
} // Returns a Position object

int Unit::getWeight() const {
    return weight;
}

void Unit::setWeight(int w) {
    weight = w;
}

int Unit::getQuantity() const {
    return quantity;
}

void Unit::setQuantity(int q) {
    quantity = q;
}

void Unit::increaseQuantity(int amount) {
    quantity += amount;
}

// --------- VEHICLE CLASS IMPLEMENTATION ---------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType) 
    : Unit(quantity, weight, pos), vehicleType(vehicleType) {}

int Vehicle::getAttackScore() {
    return (static_cast<int>(vehicleType) * 304 + quantity * weight) / 30;
}

string Vehicle::str() const {
    stringstream ss;
    ss << "Vehicle[vehicleType=" << static_cast<int>(vehicleType)  // Convert enum to int
       << ",quantity=" << quantity
       << ",weight=" << weight
       << ",pos=" << pos.str() << "]";  
    return ss.str();
}

VehicleType Vehicle::getVehicleType() const {
    return vehicleType;
}

// --------- INFANTRY CLASS IMPLEMENTATION ---------
bool isPerfectSquare(int num) {
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

int calculatePersonalNumber(int score) {
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

Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType) 
    : Unit(quantity, weight, pos), infantryType(infantryType) {}

int Infantry::getAttackScore() {
    int score = (static_cast<int>(infantryType) * 56) + (quantity * weight);

    if (infantryType == SPECIALFORCES && isPerfectSquare(weight)) {
        score += 75;
    }

    int personalNumber = calculatePersonalNumber(score);

    if (personalNumber > 7) {
        quantity += static_cast<int>(ceil(quantity * 0.2));  
    } else if (personalNumber < 3) {
        quantity = max(0, quantity - static_cast<int>(ceil(quantity * 0.1)));
    }

    return (static_cast<int>(infantryType) * 56) + (quantity * weight);
}

string Infantry::str() const {
    stringstream ss;
    ss << "Infantry[infantryType=" << static_cast<int>(infantryType)  // Convert enum to int
       << ",quantity=" << quantity
       << ",weight=" << weight
       << ",pos=" << pos.str() << "]";  // Use Position's str() method
    return ss.str();
}

InfantryType Infantry::getInfantryType() const {
    return infantryType;
}


// --------- UNITLIST CLASS IMPLEMENTATION (LINKED LIST) ---------

bool isSpecialNumber(int S) {
    int primes[] = {3, 5, 7}; 

    for (int i = 0; i < 3; ++i) {
        int k = primes[i];

        vector<int> powers; // list of powers
        int power = 1;
        while (power <= S / k) { // Overflow
            powers.push_back(power);
            power *= k;
        }
        powers.push_back(power); 

        int n = powers.size();
        int limit = (1 << n); // Có 2^n tổ hợp

        for (int mask = 0; mask < limit; ++mask) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)/* bit j high -> value at j*/) {
                    sum += powers[j];
                    if (sum > S) break; 
                }
            }
            if (sum == S) return true;
        }
    }
    return false;
}

UnitList::UnitList(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->count_vehicle = 0;
    this->count_infantry = 0;
    this->head = nullptr;
    this->tail = nullptr;
}


UnitList::~UnitList() {
    while (head) {
        UnitNode* temp = head;
        head = head->next;
        // delete temp->unit;
        delete temp;
    }
    tail = nullptr;
}

bool UnitList::insert(Unit* unit) {
    if (size >= capacity) return false;

    bool isVehicle = dynamic_cast<Vehicle*>(unit);
    bool isInfantry = dynamic_cast<Infantry*>(unit); 

    UnitNode* temp = head;
    while (temp) {
        if (isVehicle) {
            Vehicle* existVeh = dynamic_cast<Vehicle*>(temp->unit);
            Vehicle* newVeh = dynamic_cast<Vehicle*>(unit);
            if (existVeh && newVeh && existVeh->getVehicleType() == newVeh->getVehicleType()) {
                existVeh->increaseQuantity(unit->getQuantity());
                delete unit; // Prevent memory leak
                return true;
            }
        } else if (isInfantry) {
            Infantry* existInf = dynamic_cast<Infantry*>(temp->unit);
            Infantry* newInf = dynamic_cast<Infantry*>(unit);
            if (existInf && newInf && existInf->getInfantryType() == newInf->getInfantryType()) {
                existInf->increaseQuantity(unit->getQuantity());
                delete unit; // Prevent memory leak
                return true;
            }
        }
        temp = temp->next;
    }

    // if (size >= capacity) return false;

    UnitNode* newNode = new UnitNode(unit);
    if (!head) {
        head = tail = newNode;
    } else if (isInfantry) {
        newNode->next = head;
        head = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    if (isInfantry) count_infantry++;
    else count_vehicle++;

    size++;
    return true;
}


bool UnitList::isContain(VehicleType vehicleType) {
    UnitNode* temp = head;
    while (temp)
    {
        Vehicle* vehicle = dynamic_cast<Vehicle*>(temp->unit); 
        if (vehicle && vehicle->getVehicleType() == vehicleType){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool UnitList::isContain(InfantryType infantryType) {
    UnitNode* temp = head;
    while (temp)
    {
        Infantry* infantry = dynamic_cast<Infantry*>(temp->unit);
        if(infantry && infantry->getInfantryType() == infantryType){
            return true;
        }
        temp = temp->next;
    }
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

void UnitList::removeUnit(Unit* unit) {
    if (!head) return;

    UnitNode* prev = nullptr;
    UnitNode* temp = head;

    while (temp) {
        if (temp->unit == unit) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp == tail) {
                tail = prev;
            }
            delete temp->unit;
            delete temp;
            --size;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void UnitList::reduceWeight(double percent) {
    UnitNode* temp = head;
    while (temp) {
        int newW = temp->unit->getWeight() * (1 - percent);
        temp->unit->setWeight(newW);
        temp = temp->next;
    }
}

void UnitList::reduceQuantity(double percent) {
    UnitNode* temp = head;
    while (temp) {
        int newQ = temp->unit->getQuantity() * (1 - percent);
        temp->unit->setQuantity(newQ);
        temp = temp->next;
    }
}

void UnitList::transferTo(UnitList* otherList) {
    UnitNode* temp = head;
    while (temp) {
        Unit* copied = 0;
        Vehicle* v = dynamic_cast<Vehicle*>(temp->unit);
        Infantry* i = dynamic_cast<Infantry*>(temp->unit);
        if (v) {
            copied = new Vehicle(v->getQuantity(), v->getWeight(), v->getCurrentPosition(), v->getVehicleType());
        } else if (i) {
            copied = new Infantry(i->getQuantity(), i->getWeight(), i->getCurrentPosition(), i->getInfantryType());
        }
        if (copied) otherList->insert(copied);
        temp = temp->next;
    }

    while (head) {
        UnitNode* next = head->next;
        // delete head->unit;
        delete head;
        head = next;
    }
    tail = 0;
    size = 0;
    count_vehicle = 0;
    count_infantry = 0;
}

UnitNode* UnitList::getHead() const { 
    return head; 
}

// --------- ARMY CLASS IMPLEMENTATION (ABSTRACT) ---------
Army::Army(Unit** unitArray, int size, string name, BattleField* battleField)
    : name(name), battleField(battleField), LF(0), EXP(0) {
    unitList = new UnitList(size);
    
    for (int i = 0; i < size; i++) {
        unitList->insert(unitArray[i]);

        Vehicle* veh = dynamic_cast<Vehicle*>(unitArray[i]);
        Infantry* inf = dynamic_cast<Infantry*>(unitArray[i]);

        if (veh) LF += veh->getAttackScore();
        if (inf) EXP += inf->getAttackScore();
    }

    LF = min(LF, 1000);
    EXP = min(EXP, 500);
}

Army::~Army() {
    delete unitList;
}

void Army::updateStats() {
    LF = 0;
    EXP = 0;
    UnitNode* temp = unitList->getHead();

    while (temp) {
        Vehicle* v = dynamic_cast<Vehicle*>(temp->unit);
        Infantry* i = dynamic_cast<Infantry*>(temp->unit);

        if (v) LF += v->getAttackScore();
        if (i) EXP += i->getAttackScore();

        temp = temp->next;
    }

    LF = min(LF, 1000);
    EXP = min(EXP, 500);
}

int Army::getLF() const {
    return LF;
}

int Army::getEXP() const {
    return EXP;
}

void Army::setLF(int value) { 
    LF = value; 
}

void Army::setEXP(int value) { 
    EXP = value; 
}

UnitList* Army::getUnitList() const {
    return unitList;
}


// --------- LIBERATIONARMY CLASS IMPLEMENTATION ---------
LiberationArmy::LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField)
    : Army(unitArray, size, name, battleField) {}

bool LiberationArmy::findSmallest(int target, vector<Unit*>& selectedUnits) {
    vector<Unit*> allUnits;

    // Collect all units
    UnitNode* node = unitList->getHead();
    while (node) {
        allUnits.push_back(node->unit);
        node = node->next;
    }

    // Bubble sort by attackScore ascending
    for (int i = 0; i < (int)allUnits.size() - 1; ++i) {
        for (int j = 0; j < (int)allUnits.size() - i - 1; ++j) {
            if (allUnits[j]->getAttackScore() > allUnits[j + 1]->getAttackScore()) {
                Unit* tmpUnit = allUnits[j];
                allUnits[j] = allUnits[j + 1];
                allUnits[j + 1] = tmpUnit;
            }
        }
    }

    int bestScore = INT_MAX;
    vector<Unit*> bestGroup;

    // Try all groups starting from each unit
    for (size_t i = 0; i < allUnits.size(); ++i) {
        int sum = 0;
        vector<Unit*> group;

        for (size_t j = i; j < allUnits.size(); ++j) {
            sum += allUnits[j]->getAttackScore();
            group.push_back(allUnits[j]);

            if (sum >= target) {
                if (sum < bestScore) {
                    bestScore = sum;
                    bestGroup = group;
                }
                break; // no need to continue, units are sorted
            }
        }
    }

    if (!bestGroup.empty()) {
        selectedUnits = bestGroup;
        return true;
    }
    return false;
}



int LiberationArmy::getNearestFibonacci(int num) {
    int a = 0, b = 1;
    while (b < num) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}


void LiberationArmy::fight(Army* enemy, bool defense) {
    if (!enemy) return;

    if (!defense) { 
        LF *= 1.5;
        EXP *= 1.5;

        vector<Unit*> groupA;
        vector<Unit*> groupB;
        
        bool foundA = findSmallest(enemy->getEXP(), groupA);
        bool foundB = findSmallest(enemy->getLF(), groupB);

        if (foundA && foundB) {
            for (Unit* unit : groupA) unitList->removeUnit(unit);
            for (Unit* unit : groupB) unitList->removeUnit(unit);
        } else if (foundA || foundB) {
            if ((foundA && EXP > enemy->getEXP()) || (foundB && LF > enemy->getLF())) {
                for (Unit* unit : groupA) unitList->removeUnit(unit);
                for (Unit* unit : groupB) unitList->removeUnit(unit);
            } else {
                return;
            }
        } else {
            unitList->reduceWeight(0.1);
            updateStats();
            return;
        }

        enemy->getUnitList()->transferTo(unitList);
        updateStats();
    } else {
        LF *= 1.3;
        EXP *= 1.3;

        if (LF >= enemy->getLF() && EXP >= enemy->getEXP()) {
            return;
        } else if (LF < enemy->getLF() || EXP < enemy->getEXP()) {
            unitList->reduceQuantity(0.1);
        } else {
            UnitNode* temp = unitList->getHead();
            while (temp) {
                int newQuantity = getNearestFibonacci(temp->unit->getQuantity());
                temp->unit->setQuantity(newQuantity);
                temp = temp->next;
            }
            updateStats();
        }
    }
}

// string LiberationArmy::str() const {
//     return "LiberationArmy[name=" + name + ",LF=" + to_string(LF) + 
//            ",EXP=" + to_string(EXP) + "," + unitList->str() + "," + battleField->str() + "]";
// }

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

void ARVN::fight(Army* enemy, bool defense) {
    LiberationArmy* liberation = dynamic_cast<LiberationArmy*>(enemy);
    if (!liberation) return;

    if (!defense) {
        UnitNode* current = unitList->getHead();
        while (current) {
            UnitNode* next = current->next;
            Unit* u = current->unit;
            int newQ = static_cast<int>(ceil(u->getQuantity() * 0.8));
            u->setQuantity(newQ);
            if (newQ <= 1) {
                unitList->removeUnit(u);
            }
            current = next;
        }
        updateStats();
    } else {
        if (liberation->getLF() >= this->LF && liberation->getEXP() >= this->EXP) {
            unitList->transferTo(liberation->getUnitList());
        } else {
            unitList->reduceWeight(0.2);
        }
        updateStats();
    }
}


// string ARVN::str() const {
//     stringstream ss;
//     ss << "ARVN[name=" << name << ",LF=" << LF << ",EXP=" << EXP
//        << ",unitList=" << unitList->str() << ",battleField=" << battleField << "]";
//     return ss.str();
// }

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
    return position;
}

// --------- INDIVIDUAL TERRAIN CLASSES IMPLEMENTATION ---------
// --- Constructors ---
Road::Road(Position pos) : TerrainElement(pos) {}
Mountain::Mountain(Position pos) : TerrainElement(pos) {}
River::River(Position pos) : TerrainElement(pos) {}
Urban::Urban(Position pos) : TerrainElement(pos) {}
Fortification::Fortification(Position pos) : TerrainElement(pos) {}
SpecialZone::SpecialZone(Position pos) : TerrainElement(pos) {}


// --- ROAD ---
void Road::getEffect(Army* army) {
    // No effect
}


// --- MOUNTAIN ---
void Mountain::getEffect(Army* army) {
    UnitNode* node = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army);
    int radius = isLiberation ? 2 : 4;
    double infBoost = isLiberation ? 0.3 : 0.2;
    double vehPenalty = isLiberation ? 0.1 : 0.05;

    while (node) {
        Unit* u = node->unit;
        double dist = sqrt(pow(u->getCurrentPosition().getRow() - getPosition().getRow(), 2) +
                           pow(u->getCurrentPosition().getCol() - getPosition().getCol(), 2));
        if (dist <= radius) {
            int atk = u->getAttackScore();
            if (dynamic_cast<Infantry*>(u)) {
                army->setEXP(army->getEXP() + static_cast<int>(ceil(infBoost * atk)));
            } else if (dynamic_cast<Vehicle*>(u)) {
                army->setLF(army->getLF() - static_cast<int>(ceil(vehPenalty * atk)));
            }
        }
        node = node->next;
    }

    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, std::min(500, army->getEXP())));

}


// --- RIVER ---
void River::getEffect(Army* army) {
    UnitNode* node = army->getUnitList()->getHead();
    while (node) {
        Infantry* inf = dynamic_cast<Infantry*>(node->unit);
        if (inf) {
            double dist = sqrt(pow(inf->getCurrentPosition().getRow() - getPosition().getRow(), 2) +
                               pow(inf->getCurrentPosition().getCol() - getPosition().getCol(), 2));
            if (dist <= 2) {
                int atk = inf->getAttackScore();
                army->setEXP(army->getEXP() - static_cast<int>(ceil(0.1 * atk)));
            }
        }
        node = node->next;
    }

    army->setEXP(max(0, min(500, army->getEXP())));

}


// --- URBAN ---
void Urban::getEffect(Army* army) {
    UnitNode* node = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army);

    while (node) {
        Unit* u = node->unit;
        Position posU = u->getCurrentPosition();
        double dist = sqrt(pow(posU.getRow() - getPosition().getRow(), 2) +
                           pow(posU.getCol() - getPosition().getCol(), 2));
        int atk = u->getAttackScore();

        Infantry* inf = dynamic_cast<Infantry*>(u);
        Vehicle* veh = dynamic_cast<Vehicle*>(u);

        if (inf) {
            InfantryType type = inf->getInfantryType();
            if (isLiberation) {
                if ((type == SPECIALFORCES || type == REGULARINFANTRY) && dist <= 5) {
                    int delta = static_cast<int>(ceil((2.0 * atk) / dist));
                    army->setEXP(army->getEXP() + delta);
                }
            } else {
                if (type == REGULARINFANTRY && dist <= 3) {
                    int delta = static_cast<int>(ceil((3.0 * atk) / (2.0 * dist)));
                    army->setEXP(army->getEXP() + delta);
                }
            }
        } else if (veh && isLiberation && veh->getVehicleType() == ARTILLERY && dist <= 2) {
            int penalty = static_cast<int>(ceil(0.5 * atk));
            army->setLF(army->getLF() - penalty);
        }

        node = node->next;
    }

    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));

}


// --- FORTIFICATION ---
void Fortification::getEffect(Army* army) {
    UnitNode* node = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army);

    while (node) {
        Unit* u = node->unit;
        double dist = sqrt(pow(u->getCurrentPosition().getRow() - getPosition().getRow(), 2) +
                           pow(u->getCurrentPosition().getCol() - getPosition().getCol(), 2));
        int atk = u->getAttackScore();

        if (dist <= 2) {
            if (isLiberation) {
                int penalty = static_cast<int>(ceil(0.2 * atk));
                if (dynamic_cast<Infantry*>(u)) army->setEXP(army->getEXP() - penalty);
                else if (dynamic_cast<Vehicle*>(u)) army->setLF(army->getLF() - penalty);
            } else {
                int boost = static_cast<int>(ceil(0.2 * atk));
                if (dynamic_cast<Infantry*>(u)) army->setEXP(army->getEXP() + boost);
                else if (dynamic_cast<Vehicle*>(u)) army->setLF(army->getLF() + boost);
            }
        }

        node = node->next;
    }

    army->setLF(max(0, min(1000, army->getLF())));
    army->setEXP(max(0, min(500, army->getEXP())));

}


// --- SPECIAL ZONE ---
void SpecialZone::getEffect(Army* army) {
    UnitNode* node = army->getUnitList()->getHead();

    while (node) {
        Unit* u = node->unit;
        double dist = sqrt(pow(u->getCurrentPosition().getRow() - this->getPosition().getRow(), 2) +
                           pow(u->getCurrentPosition().getCol() - this->getPosition().getCol(), 2));
        if (dist <= 1) {
            if (dynamic_cast<Infantry*>(u)) {
                army->setEXP(army->getEXP() - u->getAttackScore());
            } else if (dynamic_cast<Vehicle*>(u)) {
                army->setLF(army->getLF() - u->getAttackScore());
            }
        }

        node = node->next;
    }

    army->setLF(std::max(0, std::min(1000, army->getLF())));
    army->setEXP(std::max(0, std::min(500, army->getEXP())));

}

// --------- BATTLEFIELD CLASS IMPLEMENTATION ---------
BattleField::BattleField(int n_rows, int n_cols,
                         vector<Position*> arrayForest,
                         vector<Position*> arrayRiver,
                         vector<Position*> arrayFortification,
                         vector<Position*> arrayUrban,
                         vector<Position*> arraySpecialZone)
    : n_rows(n_rows), n_cols(n_cols) {
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = new Road(Position(i, j));
        }
    }

    for (int i = 0; i < (int)arrayForest.size(); ++i)
        replaceTerrain(arrayForest[i], new Mountain(*arrayForest[i]));
    for (int i = 0; i < (int)arrayRiver.size(); ++i)
        replaceTerrain(arrayRiver[i], new River(*arrayRiver[i]));
    for (int i = 0; i < (int)arrayFortification.size(); ++i)
        replaceTerrain(arrayFortification[i], new Fortification(*arrayFortification[i]));
    for (int i = 0; i < (int)arrayUrban.size(); ++i)
        replaceTerrain(arrayUrban[i], new Urban(*arrayUrban[i]));
    for (int i = 0; i < (int)arraySpecialZone.size(); ++i)
        replaceTerrain(arraySpecialZone[i], new SpecialZone(*arraySpecialZone[i]));
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
    return ss.str();
}

// --------- CONFIGURATION CLASS IMPLEMENTATION ---------
Configuration::Configuration(const string& filepath) {
    ifstream file(filepath.c_str());
    string line;

    while (getline(file, line)) {
        if (line.find("NUM_ROWS=") == 0) {
            num_rows = stoi(line.substr(9));
        } else if (line.find("NUM_COLS=") == 0) {
            num_cols = stoi(line.substr(9));
        } else if (line.find("ARRAY_FOREST=") == 0) {
            stringstream ss(line.substr(13));
            string pos;
            while (getline(ss, pos, ')')) {
                if (!pos.empty()) {
                    pos += ")";
                    arrayForest.push_back(new Position(pos));
                    ss.ignore(); // Skip comma
                }
            }
        } else if (line.find("ARRAY_RIVER=") == 0) {
            stringstream ss(line.substr(12));
            string pos;
            while (getline(ss, pos, ')')) {
                if (!pos.empty()) {
                    pos += ")";
                    arrayRiver.push_back(new Position(pos));
                    ss.ignore();
                }
            }
        } else if (line.find("ARRAY_FORTIFICATION=") == 0) {
            stringstream ss(line.substr(21));
            string pos;
            while (getline(ss, pos, ')')) {
                if (!pos.empty()) {
                    pos += ")";
                    arrayFortification.push_back(new Position(pos));
                    ss.ignore();
                }
            }
        } else if (line.find("ARRAY_URBAN=") == 0) {
            stringstream ss(line.substr(12));
            string pos;
            while (getline(ss, pos, ')')) {
                if (!pos.empty()) {
                    pos += ")";
                    arrayUrban.push_back(new Position(pos));
                    ss.ignore();
                }
            }
        } else if (line.find("ARRAY_SPECIAL_ZONE=") == 0) {
            stringstream ss(line.substr(20));
            string pos;
            while (getline(ss, pos, ')')) {
                if (!pos.empty()) {
                    pos += ")";
                    arraySpecialZone.push_back(new Position(pos));
                    ss.ignore();
                }
            }
        } else if (line.find("UNIT_LIST=") == 0) {
            string unitsStr = line.substr(10); // after UNIT_LIST=
            unitsStr = unitsStr.substr(1, unitsStr.length() - 2); // remove [ ]

            vector<string> unitEntries;
            string current = "";
            int parenCount = 0;

            for (size_t i = 0; i < unitsStr.length(); ++i) {
                char ch = unitsStr[i];
                current += ch;

                if (ch == '(') parenCount++;
                else if (ch == ')') parenCount--;

                if (parenCount == 0 && !current.empty()) {
                    unitEntries.push_back(current);
                    current = "";
                    if (i + 1 < unitsStr.length() && unitsStr[i + 1] == ',') ++i;
                }
            }

            for (size_t i = 0; i < unitEntries.size(); ++i) {
                string entry = unitEntries[i];
                size_t p1 = entry.find('(');
                size_t p2 = entry.find_last_of(')');

                if (p1 == string::npos || p2 == string::npos) continue;

                string type = entry.substr(0, p1);
                string args = entry.substr(p1 + 1, p2 - p1 - 1); // "5,2,(1,2),0"

                stringstream ss(args);
                string qStr, wStr, posStr, belongStr;

                getline(ss, qStr, ',');
                getline(ss, wStr, ',');
                getline(ss, posStr, ')'); posStr += ")";
                ss.ignore(); // skip comma
                getline(ss, belongStr);

                try {
                    int quantity = stoi(qStr);
                    int weight = stoi(wStr);
                    Position pos(posStr);
                    int belong = stoi(belongStr);

                    Unit* unit = NULL;
                    if (type == "SNIPER") unit = new Infantry(quantity, weight, pos, SNIPER);
                    else if (type == "ANTIAIRCRAFTSQUAD") unit = new Infantry(quantity, weight, pos, ANTIAIRCRAFTSQUAD);
                    else if (type == "MORTARSQUAD") unit = new Infantry(quantity, weight, pos, MORTARSQUAD);
                    else if (type == "ENGINEER") unit = new Infantry(quantity, weight, pos, ENGINEER);
                    else if (type == "SPECIALFORCES") unit = new Infantry(quantity, weight, pos, SPECIALFORCES);
                    else if (type == "REGULARINFANTRY") unit = new Infantry(quantity, weight, pos, REGULARINFANTRY);
                    else if (type == "TRUCK") unit = new Vehicle(quantity, weight, pos, TRUCK);
                    else if (type == "MORTAR") unit = new Vehicle(quantity, weight, pos, MORTAR);
                    else if (type == "ANTIAIRCRAFT") unit = new Vehicle(quantity, weight, pos, ANTIAIRCRAFT);
                    else if (type == "ARMOREDCAR") unit = new Vehicle(quantity, weight, pos, ARMOREDCAR);
                    else if (type == "APC") unit = new Vehicle(quantity, weight, pos, APC);
                    else if (type == "ARTILLERY") unit = new Vehicle(quantity, weight, pos, ARTILLERY);
                    else if (type == "TANK") unit = new Vehicle(quantity, weight, pos, TANK);

                    if (unit) {
                        if (belong == 0) liberationUnits.push_back(unit);
                        else ARVNUnits.push_back(unit);
                    }
                } catch (const exception& e) {
                    cerr << "Error parsing UNIT_LIST entry: " << entry << " — " << e.what() << endl;
                }
            }
        } else if (line.find("EVENT_CODE=") == 0) {
            int raw = stoi(line.substr(11));
            eventCode = raw < 0 ? 0 : raw % 100;
        }
    }

    file.close();
}


Configuration::~Configuration() {
    for (int i = 0; i < (int)arrayForest.size(); ++i) delete arrayForest[i];
    for (int i = 0; i < (int)arrayRiver.size(); ++i) delete arrayRiver[i];
    for (int i = 0; i < (int)arrayFortification.size(); ++i) delete arrayFortification[i];
    for (int i = 0; i < (int)arrayUrban.size(); ++i) delete arrayUrban[i];
    for (int i = 0; i < (int)arraySpecialZone.size(); ++i) delete arraySpecialZone[i];

    for (int i = 0; i < (int)liberationUnits.size(); ++i) delete liberationUnits[i];
    for (int i = 0; i < (int)ARVNUnits.size(); ++i) delete ARVNUnits[i];
}


string Configuration::str() const {
    stringstream ss;
    ss << "Configuration[\n";
    ss << "NUM_ROWS=" << num_rows << "\n";
    ss << "NUM_COLS=" << num_cols << "\n";
    ss << "EVENT_CODE=" << eventCode << "\n";
    ss << "UNIT_LIST=[";
    for (size_t i = 0; i < liberationUnits.size(); ++i) {
        ss << liberationUnits[i]->str();
        if (i < liberationUnits.size() - 1 || !ARVNUnits.empty()) ss << ",";
    }
    for (size_t i = 0; i < ARVNUnits.size(); ++i) {
        ss << ARVNUnits[i]->str();
        if (i < ARVNUnits.size() - 1) ss << ",";
    }
    ss << "]\n]";
    return ss.str();
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


// --------- HCMCAMPAIGN CLASS IMPLEMENTATION ---------
HCMCampaign::HCMCampaign(const string& config_file_path) {
    config = new Configuration(config_file_path);

    battleField = new BattleField(
        config->getNumRows(),
        config->getNumCols(),
        config->getArrayForest(),
        config->getArrayRiver(),
        config->getArrayFortification(),
        config->getArrayUrban(),
        config->getArraySpecialZone()
    );

    liberationArmy = new LiberationArmy(
        const_cast<Unit**>(config->getLiberationUnits().data()),
        config->getLiberationUnits().size(),
        "LiberationArmy",
        battleField
    );

    ARVNArmy = new ARVN(
        const_cast<Unit**>(config->getARVNUnits().data()),
        config->getARVNUnits().size(),
        "ARVN",
        battleField
    );
}

HCMCampaign::~HCMCampaign() {
    delete liberationArmy;
    delete ARVNArmy;
    delete battleField;
    delete config;
}


string HCMCampaign::printResult() {
    return "LIBERATIONARMY[LF=" + to_string(liberationArmy->getLF()) +
           ",EXP=" + to_string(liberationArmy->getEXP()) + "] - " +
           "ARVNArmy[LF=" + to_string(ARVNArmy->getLF()) +
           ",EXP=" + to_string(ARVNArmy->getEXP()) + "]";
}

void HCMCampaign::run() {
    battleField->applyTerrainEffects(liberationArmy);
    battleField->applyTerrainEffects(ARVNArmy);

    if (config->getEventCode() % 2 == 0) {
        liberationArmy->fight(ARVNArmy, false);
        ARVNArmy->fight(liberationArmy, true);
    } else {
        ARVNArmy->fight(liberationArmy, false);
        liberationArmy->fight(ARVNArmy, true);
    }
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////