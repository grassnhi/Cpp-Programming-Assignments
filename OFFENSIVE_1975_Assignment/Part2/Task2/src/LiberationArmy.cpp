#include "LiberationArmy.h"

LiberationArmy::LiberationArmy(Unit** unitArray, int size, string name/*, BattleField* battleField*/)
                : Army(unitArray, size, name/*, battleField*/) {}

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

bool LiberationArmy::findSmallest(int target, vector<Unit*>& selectedUnits, bool veh){
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
            if(thisUnits[j]->getAttackScore() > thisUnits[j+1]->getAttackScore()){
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
            sum += thisUnits[j]->getAttackScore();
            group.push_back(thisUnits[j]);
            
            if(sum >= target){
                cout << " sum: " << sum << " tar: " << target;
                if(sum < bestScore){
                    bestScore = sum;
                    bestGroup = group;
                    cout << " best score: " << bestScore;
                }
                break;
            }
        }
    }

    cout << "\nBest group: ";
    for (int i = 0; i < (int)bestGroup.size(); i++)
    {
        cout << bestGroup[i]->str() << " - ";
    }
    cout << endl;

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
        cout << "Defense = true: ";
        this->EXP = ceil(this->EXP*1.3);
        this->LF = ceil(this->LF*1.3);

        

        if(this->LF >= enemy->getLF() && this->EXP >= enemy->getEXP()){
            this->LF = min(this->LF, 1000);
            this->EXP = min(this->EXP, 500);
            cout << "Case 1: Winnn \n";
            return;
        } else if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
            cout << "Case 2: Reduce 10% \n";
            this->unitList->reduceQuantity(0.1);
        } else {
            cout << "Case 3: Need help \n";
            UnitNode* temp = this->unitList->getHead();
            while (temp) {
                int newQuantity = getNearestFibonacci(temp->unit->getQuantity());
                temp->unit->increaseQuantity(newQuantity);
                temp = temp->next;
            }
            updateScore();

            // Continue ??? Again ???
            // if (this->LF < enemy->getLF() || this->EXP < enemy->getEXP()) {
            //     return;
            // } else {
            //     this->unitList->reduceQuantity(0.1);
            //     updateScore();
            //     return;
            // }
        }
        
    }else{
        cout << "Defense = false: ";
        this->EXP = ceil(this->EXP*1.5);
        this->LF = ceil(this->LF*1.5);

        // this->LF = min(this->LF, 1000);
        // this->EXP = min(this->EXP, 500);

        vector<Unit*> groupA; // Inf mình > EXP enemy
        vector<Unit*> groupB; // Veh mình > LF enemy

        cout << "\nTarget A (EXP - Inf): " << enemy->getEXP() << " - Target B (LF - Veh): " << enemy->getLF() << endl;

        cout << "Gr A: ";
        bool foundA = findSmallest(enemy->getEXP(), groupA, false);
        cout << "Gr B: ";
        bool foundB = findSmallest(enemy->getLF(), groupB, true);

        if(foundA && foundB){
            cout << "Case 1: Win -> Remove \n";
            for(int i = 0; i < groupA.size(); i++){
                // cout << " GrA :";
                this->unitList->removeUnit(groupA[i]);
            }
            for(int i = 0; i < groupB.size(); i++){
                // cout << " GrB :" ;
                this->unitList->removeUnit(groupB[i]);
            }
            // cout << "Then: " << this->unitList->str() << " \n vs " << enemy->getUnitList()->str() << endl; 
        }else if(foundA && this->LF > enemy->getLF()){
            cout << "Case 2.1: Fair but Win \n";
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
        }else if((foundB && this->EXP > enemy->getEXP())){
            cout << "Case 2.2: Fair but Win \n";
            for(int i = 0; i < groupB.size(); i++){
                this->unitList->removeUnit(groupB[i]);
            }
            UnitNode* node = this->unitList->getHead();
            while (node) {
                Unit* temp = node->unit;
                node = node->next;
                if (!temp->isVehicle()){
                    this->unitList->removeUnit(temp);
                } 
            }
        }else{
            cout << "Case 3: No fight \n";
            this->unitList->reduceWeight(0.1);
            updateScore();
            return;
        }

        enemy->getUnitList()->transferTo(unitList);
        enemy->setLF(0);
        enemy->setEXP(0);
        updateScore();

        // cout << "Then: " << this->unitList->str() << " \n vs " << enemy->getUnitList()->str() << endl; 
    }
    // cout << endl;
}

bool LiberationArmy::isLiberation() const  {
    return true;
}

string LiberationArmy::str() const {
    return "LiberationArmy[LF=" + to_string(LF) + 
           ",EXP=" + to_string(EXP) + 
           ",unitList=" + unitList->str() + /*"," +
           (battleField ? battleField->str() : "battleField=") + */"]";
}
