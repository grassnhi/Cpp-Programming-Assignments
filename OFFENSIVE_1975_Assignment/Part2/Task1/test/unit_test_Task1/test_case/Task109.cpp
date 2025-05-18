#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task109()
{
    // Test Infantry SNIPER với tăng số lượng khi "số cá nhân" > 7
    string name = "Task109";
    //! data ------------------------------------
    int quantity = 1;
    int weight = 58;
    Position pos(9, 9);
    InfantryType it = SNIPER; // giá trị 0
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 0*56 + 1*58 = 58.
    // computeSingleDigit(58,1975) cho ra 8 -> tăng 20%: thêm 1, new quantity = 2.
    // Final score = 0*56 + 2*58 = 116.
    int expectedScore = 116;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
