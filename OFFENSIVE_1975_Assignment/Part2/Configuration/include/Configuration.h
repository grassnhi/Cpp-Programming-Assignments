#include "main.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

enum TerrainType
{
    ROAD,
    FOREST,
    RIVER,
    FORTIFICATION,
    URBAN,
    SPECIAL_ZONE
};

struct UNIT_NAME
{
    int quantity;
    int weight;
    int position_x;
    int position_y;
    bool armyBelong;
    InfantryType type;
};

void processFile(const string &filename, TerrainType **&battlefield, int &NUM_ROWS, int &NUM_COLS, vector<UNIT_NAME> &units, int &EVENT_CODE);
string print_battlefield(const TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS);
string print_UNIT_NAME(const vector<UNIT_NAME> &units);
void clearBattlefield(TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS);
