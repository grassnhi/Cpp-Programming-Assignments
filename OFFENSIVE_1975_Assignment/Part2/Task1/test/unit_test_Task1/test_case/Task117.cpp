#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task117()
{
    // Test Infantry REGULARINFANTRY: số lượng không giảm dưới 1 khi giảm 10%
    string name = "Task117";
    //! data ------------------------------------
    int quantity = 1;
    int weight = 5;
    Position pos(15,15);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 5*56 + 1*5; // 280 + 5 = 285
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
