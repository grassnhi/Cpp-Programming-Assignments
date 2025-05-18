#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task115()
{
    // Test đa hình: Unit* trỏ đến Infantry
    string name = "Task115";
    //! data ------------------------------------
    Unit* unit = new Infantry(6, 7, Position(13,13), ANTIAIRCRAFTSQUAD); // ANTIAIRCRAFTSQUAD có giá trị 1
    //! process ---------------------------------
    int score = unit->getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 1 * 56 + 6 * 7; // 56 + 42 = 98
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    delete unit;
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
