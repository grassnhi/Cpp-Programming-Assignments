#include "BattleField.h"
//!-----------------------------------------------------
// CLASS BattleField
//!-----------------------------------------------------
BattleField::BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone) 
                : n_rows(n_rows), n_cols(n_cols) 
{
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = new Road(Position(i, j));
        }
    }

    for (int i = 0; i < (int)arrayForest.size(); ++i){
        Position* pos = arrayForest[i];
        replaceTerrain(pos, new Mountain(*pos));
    }
        
    for (int i = 0; i < (int)arrayRiver.size(); ++i){
        Position* pos = arrayRiver[i];
        replaceTerrain(pos, new River(*pos));
    }
        
    for (int i = 0; i < (int)arrayFortification.size(); ++i){
        Position* pos = arrayFortification[i];
        replaceTerrain(pos, new Fortification(*pos));
    }
        
    for (int i = 0; i < (int)arrayUrban.size(); ++i){
        Position* pos = arrayUrban[i];
        replaceTerrain(pos, new Urban(*pos));
    }
        
    for (int i = 0; i < (int)arraySpecialZone.size(); ++i){
        Position* pos = arraySpecialZone[i];
        replaceTerrain(pos, new SpecialZone(*pos));
    }    
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
    ss << "BattleField[n_rows=" << n_rows << ",n_cols=" << n_cols << "]" << endl;

    // cout << "Just for test: " << endl;
    // for (int i = 0; i < n_rows; ++i) {
    //     for (int j = 0; j < n_cols; ++j) {
    //         ss << terrain[i][j]->type() << "\t"; 
    //     }
    //     ss << "\n";
    // }
    return ss.str();
}


TerrainElement* BattleField::getElement(int r, int c) const {
    if (r < 0 || r >= n_rows || c < 0 || c >= n_cols)
        return nullptr;  
    return terrain[r][c];
}