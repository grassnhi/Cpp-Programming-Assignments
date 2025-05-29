#ifndef _H_ARMY_H_
#define _H_ARMY_H_

#include "UnitList.h"
using namespace std;
class BattleField
{
private:
    int n_rows, n_cols;
public:
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();

    string str() const{

    };
};

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
    bool isSpecialNumber(int S);

    UnitList* getUnitList() const;
    BattleField* getBattleField() const;
};



#endif
