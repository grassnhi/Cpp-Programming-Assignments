#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task113()
{
    // Test Position với row = 0 và col âm
    string name = "Task113";
    //! data ------------------------------------
    int row = 0;
    int col = -7;
    string pos_str = "(0,-7)";
    
    //! process ---------------------------------
    Position pos(row, col);
    string result = pos.str();
    
    //! expect ----------------------------------
    string expect = "(0,-7)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
