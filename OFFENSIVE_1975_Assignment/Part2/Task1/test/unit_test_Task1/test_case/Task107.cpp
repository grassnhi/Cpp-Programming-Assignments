#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task107()
{
    // Test Infantry REGULARINFANTRY với giảm số lượng khi "số cá nhân" < 3
    string name = "Task107";
    //! data ------------------------------------
    int quantity = 50;
    int weight = 10;
    Position pos(7, 7);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 5*56 + 50*10 = 280 + 500 = 780.
    // computeSingleDigit(780,1975) cho ra digit < 3 -> giảm 10%: giảm 5 đơn vị, new quantity = 45.
    // Final score = 5*56 + 45*10 = 280 + 450 = 730.
    int expectedScore = 730;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
