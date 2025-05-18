#include "ARVN.h"

ARVN::ARVN(Unit** unitArray, int size, string name/*, BattleField* battleField*/)
    : Army(unitArray, size, name/*, battleField*/) {}

void ARVN::fight(Army* enemy, bool defense){
    if (!enemy->isLiberation()){
        return;
    } 

    if(defense){
        if (enemy->getLF() >= this->LF && enemy->getEXP() >= this->EXP) {
            this->unitList->transferTo(enemy->getUnitList());
            enemy->setLF(0);
            enemy->setEXP(0);
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
           ",unitList=" + unitList->str() + /*"," +
           (battleField ? battleField->str() : "battleField=") + */"]";
}
