#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task114()
{
    // Test đa hình: Unit* trỏ đến Vehicle
    string name = "Task114";
    //! data ------------------------------------
    Unit* unit = new Vehicle(7, 9, Position(12,12), ARMOREDCAR); // ARMOREDCAR có giá trị 3
    //! process ---------------------------------
    int score = unit->getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 33; // 912 + 63 = 975 / 30 = 32.5 => 33
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
