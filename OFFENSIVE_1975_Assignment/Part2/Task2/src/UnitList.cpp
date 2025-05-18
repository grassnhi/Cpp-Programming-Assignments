#include "UnitList.h"

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
    bool isVehicle = unit->isVehicle();
    bool isInfantry = !isVehicle;

    // cout << "\n ";

    // Check if unit with same type already exists
    UnitNode* temp = head;
    while (temp) {
        if (isVehicle) {
            Vehicle* existVeh = dynamic_cast<Vehicle*>(temp->unit);
            Vehicle* newVeh = dynamic_cast<Vehicle*>(unit);
            if (existVeh && newVeh && existVeh->getVehicleType() == newVeh->getVehicleType()) {
                // cout << "V Existed! ";
                // cout << existVeh->getQuantity() << " ->> " << newVeh->getQuantity();
                existVeh->increaseQuantity(unit->getQuantity());
                // cout << " =>> " << existVeh->getQuantity();
                
                existVeh->getAttackScore(); 
                return true;
            }
        } else if (isInfantry) {
            Infantry* existInf = dynamic_cast<Infantry*>(temp->unit);
            Infantry* newInf = dynamic_cast<Infantry*>(unit);
            if (existInf && newInf && existInf->getInfantryType() == newInf->getInfantryType()) {
                cout << "I Existed! ";
                cout << existInf->getQuantity() << " + " << newInf->getQuantity();
                existInf->increaseQuantity(unit->getQuantity());
                cout << " = " << existInf->getQuantity() << endl;
                cout << existInf->str();
                existInf->getAttackScore(); //252
                cout << " => " << existInf->str() << endl;
                return true;
            }
        }
        temp = temp->next;
    }

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
    // cout << unit->str() << endl;
    
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
        cout << " NOT Found! \n";
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
    vector<Unit*> units;
    UnitNode* temp = head; 
    
    while (temp) {
        units.push_back(temp->unit);
        temp = temp->next;
    }

    for (int i = 0; i < (int)units.size(); ++i) {
        int idx = units.size() - 1 - i;
        otherList->insert(units[idx]);
        cout << "Insert + Remove: " << units[idx]->str() << endl;
        removeUnit(units[idx]);
    }

    cout << this->str() << endl;

    head = tail = nullptr;
    size = 0;
    count_vehicle = 0;
    count_infantry = 0;
}