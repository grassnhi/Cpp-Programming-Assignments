#include "../unit_test_Configuration.hpp"

bool UNIT_TEST_Configuration::Configuration07()
{
    string name = "Configuration07";
    //! data ------------------------------------
    string filePath = "test/unit_test_Configuration/test_case/input/config7.txt";
    int NUM_ROWS = 0;
    int NUM_COLS = 0;
    vector<UNIT_NAME> units;
    int EVENT_CODE = 0;
    TerrainType **battlefield;

    //! process ---------------------------------
    processFile(filePath, battlefield, NUM_ROWS, NUM_COLS, units, EVENT_CODE);
    string result;
    result += "NUM_ROWS: " + to_string(NUM_ROWS) + "\n";
    result += "NUM_COLS: " + to_string(NUM_COLS) + "\n";
    result += print_battlefield((const TerrainType**)battlefield, NUM_ROWS, NUM_COLS) + "\n";
    result += print_UNIT_NAME(units) + "\n";
    result += "EVENT_CODE: ";
    result += to_string(EVENT_CODE) + "\n";

    clearBattlefield(battlefield, NUM_ROWS, NUM_COLS);

    //! expect ----------------------------------
    string expect = 
R"expect(NUM_ROWS: 5
NUM_COLS: 7
ROA FOR FOR ROA ROA ROA ROA
FOR FOR ROA ROA ROA ROA ROA
ROA ROA FOR FOR ROA ROA SPE
URB ROA RIV ROA ROA ROA ROA
URB URB SPE RIV RIV RIV RIV
[
SNIPER(6,2,(0,4),0),
ANTIAIRCRAFTSQUAD(2,6,(4,1),0),
MORTARSQUAD(9,3,(3,1),0),
ANTIAIRCRAFTSQUAD(7,1,(2,2),1),
REGULARINFANTRY(9,2,(0,6),1),
ENGINEER(6,5,(4,2),1),
SPECIALFORCES(10,2,(3,3),1),
MORTARSQUAD(6,6,(0,1),1),
ENGINEER(18,12,(1,1),0),
SPECIALFORCES(17,7,(2,1),0),
REGULARINFANTRY(7,12,(3,6),0),
SNIPER(5,2,(4,0),1)
]
EVENT_CODE: 23
)expect";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}