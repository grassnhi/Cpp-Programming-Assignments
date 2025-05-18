#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task119()
{
    // Test các hàm set và get của Position
    string name = "Task119";
    //! data ------------------------------------
    Position pos;
    pos.setRow(25);
    pos.setCol(-30);
    
    //! process ---------------------------------
    int row = pos.getRow();
    int col = pos.getCol();
    string result = "(" + to_string(row) + "," + to_string(col) + ")";
    
    //! expect ----------------------------------
    string expect = "(25,-30)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
