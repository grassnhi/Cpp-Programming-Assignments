#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task108()
{
    // Test Infantry ENGINEER không thay đổi số lượng
    string name = "Task108";
    //! data ------------------------------------
    int quantity = 20;
    int weight = 12;
    Position pos(8, 8);
    InfantryType it = ENGINEER; // giá trị 3
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 3*56 + 20*12 = 168 + 240 = 408, computeSingleDigit cho ra 7 -> không thay đổi.
    int expectedScore = 408;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
