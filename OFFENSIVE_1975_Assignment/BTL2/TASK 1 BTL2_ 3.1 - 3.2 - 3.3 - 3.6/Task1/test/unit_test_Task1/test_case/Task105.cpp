#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task105()
{
    // Test Infantry SPECIALFORCES với weight là số chính phương
    string name = "Task105";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 25; // 25 là số chính phương (5*5)
    Position pos(5, 5);
    InfantryType it = SPECIALFORCES; // SPECIALFORCES có giá trị 4
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Tính: baseScore = 4*56 + 10*25 = 224 + 250 = 474,
    // bonus 75 được cộng để tính "số cá nhân" nhưng không làm thay đổi score cuối cùng.
    int expectedScore = 549;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
