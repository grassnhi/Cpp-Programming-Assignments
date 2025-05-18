#ifndef _H_ARVN_H_
#define _H_ARVN_H_

#include "Army.h"

class ARVN : public Army
{
    // TODO: implement
public:
    ARVN(Unit** unitArray, int size, string name);
    void fight(Army* enemy, bool defense=false) override;
    string str() const;

    // * Additional functions if possible
};

#endif