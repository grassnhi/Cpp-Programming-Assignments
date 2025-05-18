#include "../unit_test_Configuration.hpp"

bool UNIT_TEST_Configuration::Configuration10()
{
    string name = "Configuration10";
    //! data ------------------------------------
    string filePath = "test/unit_test_Configuration/test_case/input/config10.txt";
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
R"expect(NUM_ROWS: 2
NUM_COLS: 2
ROA ROA
RIV ROA
[
MORTARSQUAD(4,3,(0,1),0)
]
EVENT_CODE: 7
)expect";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}