#include "Army.h"

Army::Army(Unit **unitArray, int size, string name, BattleField *battleField) : name(name),battleField(battleField)
{
    // TODO: Implement
}

Army::~Army() {
}

void Army::fight(Army* enemy, bool defense) {
}

string Army::str() const {
    return "Army[name=" + name + ",LF=" + to_string(LF) + ",EXP=" + to_string(EXP) + "]";
}