#ifndef _H_BATTLEFIELD_H_
#define _H_BATTLEFIELD_H_

#include "main.h"
#include "Position.h"
#include "Army.h"
class TerrainElement; // Forward declaration
#include "TerrainElement.h"

//!-----------------------------------------------------
//! CLASS BattleField
//!-----------------------------------------------------

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
    // Trả về đối tượng TerrainElement tại vị trí (r,c)
    TerrainElement* getElement(int r, int c) const;

    string str() const;
};

#endif