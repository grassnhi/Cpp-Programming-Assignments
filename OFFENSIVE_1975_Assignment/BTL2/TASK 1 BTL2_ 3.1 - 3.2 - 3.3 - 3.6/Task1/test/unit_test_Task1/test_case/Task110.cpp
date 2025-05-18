#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task110()
{
    // Test Infantry MORTARSQUAD không điều chỉnh số lượng
    string name = "Task110";
    //! data ------------------------------------
    int quantity = 5;
    int weight = 8;
    Position pos(10, 10);
    InfantryType it = MORTARSQUAD; // giá trị 2
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 2*56 + 5*8 = 112 + 40 = 152, computeSingleDigit cho ra 3 -> không thay đổi.
    int expectedScore = 152;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
