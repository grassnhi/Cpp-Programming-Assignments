#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task116()
{
    // Test nhiều đơn vị trong mảng và tính tổng điểm tấn công
    string name = "Task116";
    //! data ------------------------------------
    Unit* units[2];
    units[0] = new Vehicle(2, 10, Position(14,14), APC); // APC có giá trị 4 → score = 4*304 + 2*10 = 1216 + 20 = 1236
    units[1] = new Infantry(4, 8, Position(14,15), ENGINEER); // ENGINEER có giá trị 3 → score = 3*56 + 4*8 = 168 + 32 = 200
    //! process ---------------------------------
    int totalScore = 0;
    for (int i = 0; i < 2; i++) {
        totalScore += units[i]->getAttackScore();
    }
    
    //! expect ----------------------------------
    int expectedTotal = 42 + 200; // 1436
    stringstream expectStream;
    expectStream << expectedTotal;
    
    //! output ----------------------------------
    stringstream output;
    output << totalScore;
    
    //! remove data -----------------------------
    for (int i = 0; i < 2; i++) {
        delete units[i];
    }
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
