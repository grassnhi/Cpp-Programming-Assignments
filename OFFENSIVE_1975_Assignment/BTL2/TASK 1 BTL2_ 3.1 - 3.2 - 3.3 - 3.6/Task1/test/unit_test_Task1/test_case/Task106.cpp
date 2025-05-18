#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task106()
{
    // Test Infantry SPECIALFORCES với weight không phải số chính phương -> tăng số lượng
    string name = "Task106";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 15; // không phải số chính phương
    Position pos(6, 6);
    InfantryType it = SPECIALFORCES; // giá trị 4
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 4*56 + 10*15 = 224 + 150 = 374, không cộng bonus
    // computeSingleDigit(374,1975) cho ra 9 (>7) -> tăng 20%: thêm (10*20+99)/100 = 2, new quantity = 12.
    // Final score = 4*56 + 12*15 = 224 + 180 = 404.
    int expectedScore = 404;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
