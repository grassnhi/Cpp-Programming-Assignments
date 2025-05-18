#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task111()
{
    // Test Infantry REGULARINFANTRY với trường hợp không thay đổi số lượng (digit nằm giữa)
    string name = "Task111";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 10;
    Position pos(11, 11);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 5*56 + 10*10 = 280 + 100 = 380, computeSingleDigit cho ra 6 (không thay đổi).
    int expectedScore = 380;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
