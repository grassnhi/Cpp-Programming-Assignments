#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task112()
{
    // Test Position với số lớn
    string name = "Task112";
    //! data ------------------------------------
    int row = 1000;
    int col = 2000;
    string pos_str = "(1000,2000)";
    
    //! process ---------------------------------
    Position pos(row, col);
    string result = pos.str();
    
    //! expect ----------------------------------
    string expect = "(1000,2000)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
