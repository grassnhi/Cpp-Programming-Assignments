#ifndef _H_ARVN_H_
#define _H_ARVN_H_

#include "Army.h"

class ARVN : public Army {
public:
    ARVN(Unit** unitArray, int size, string name/*, BattleField* battleField*/);
    void fight(Army* enemy, bool defense = false) override;
    string str() const override;

    bool isLiberation() const override;
};

#endif