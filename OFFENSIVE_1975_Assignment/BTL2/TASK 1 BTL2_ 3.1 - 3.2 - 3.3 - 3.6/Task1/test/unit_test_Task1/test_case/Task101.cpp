#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task101()
{
    // Test Position với số dương
    string name = "Task101";
    //! data ------------------------------------
    int row = 15;
    int col = 8;
    string pos_str = "(15,8)";
    
    //! process ---------------------------------
    Position pos1(row, col);
    Position pos2(pos_str);
    string result = pos1.str() + "\n" + pos2.str();
    
    //! expect ----------------------------------
    string expect = "(15,8)\n(15,8)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    // Không có cấp phát động cần giải phóng.
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
