#ifndef _H_ARMY_H_
#define _H_ARMY_H_

#include "UnitList.h"
using namespace std;

class Army
{
protected:
    int LF, EXP;
    string name;
    UnitList *unitList;
    // BattleField *battleField;

public:
    Army(Unit **unitArray, int size, string name/*, BattleField *battleField*/);
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;

    virtual ~Army();
    virtual bool isLiberation() const = 0;

    int getLF() const;
    int getEXP() const;
    void setLF(int value);
    void setEXP(int value);

    void updateScore();
    bool isSpecialNumber(int S);

    UnitList* getUnitList() const;
    // BattleField* getBattleField() const;
};


#endif
