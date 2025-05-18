#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task102()
{
    // Test Position với số âm
    string name = "Task102";
    //! data ------------------------------------
    int row = -5;
    int col = -10;
    string pos_str = "(-5,-10)";
    
    //! process ---------------------------------
    Position pos1(row, col);
    Position pos2(pos_str);
    string result = pos1.str() + "\n" + pos2.str();
    
    //! expect ----------------------------------
    string expect = "(-5,-10)\n(-5,-10)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
