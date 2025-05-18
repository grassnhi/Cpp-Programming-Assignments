#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task103()
{
    // Test Vehicle: tính điểm tấn công với TRUCK
    string name = "Task103";
    //! data ------------------------------------
    int quantity = 3;
    int weight = 10;
    Position pos(1, 2);
    VehicleType vt = TRUCK; // TRUCK có giá trị 0
    //! process ---------------------------------
    Vehicle vehicle(quantity, weight, pos, vt);
    int score = vehicle.getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 1; // 0 + 30 = 30/30 = 1
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
