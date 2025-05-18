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
class BattleField {
private:
    int n_rows, n_cols;
    // 2D mảng chứa con trỏ đến các đối tượng TerrainElement
    TerrainElement ***terrain;
public:
    // Constructor nhận các vector vị trí của các yếu tố địa hình
    BattleField(int n_rows, int n_cols, const vector<Position*>& arrayForest,
                const vector<Position*>& arrayRiver, const vector<Position*>& arrayFortification,
                const vector<Position*>& arrayUrban, const vector<Position*>& arraySpecialZone);
    ~BattleField();
    
    // Trả về đối tượng TerrainElement tại vị trí (r,c)
    TerrainElement* getElement(int r, int c) const;
    
    // Hàm str để biểu diễn thông tin của BattleField
    string str() const;
};

#endif