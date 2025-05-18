#include "../unit_test_Configuration.hpp"

bool UNIT_TEST_Configuration::Configuration05()
{
    string name = "Configuration05";
    //! data ------------------------------------
    string filePath = "test/unit_test_Configuration/test_case/input/config5.txt";
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
R"expect(NUM_ROWS: 15
NUM_COLS: 1
URB
FOR
RIV
RIV
FOR
ROA
ROA
RIV
ROA
SPE
SPE
RIV
FOR
ROA
ROA
[
SNIPER(100,101,(0,5),0),
SNIPER(12,12,(0,6),1)
]
EVENT_CODE: 45
)expect";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}