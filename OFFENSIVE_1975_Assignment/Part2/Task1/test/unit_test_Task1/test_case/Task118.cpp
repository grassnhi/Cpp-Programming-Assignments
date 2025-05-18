#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task118()
{
    // Test scenario: chuỗi xuất của Vehicle và Infantry
    string name = "Task118";
    //! data ------------------------------------
    Vehicle vehicle(3, 15, Position(16,16), MORTAR); // MORTAR có giá trị 1
    Infantry infantry(7, 10, Position(16,17), ANTIAIRCRAFTSQUAD); // ANTIAIRCRAFTSQUAD có giá trị 1
    //! process ---------------------------------
    string result = vehicle.str() + "\n" + infantry.str();
    
    //! expect ----------------------------------
    string expect = "Vehicle[vehicleType=MORTAR,quantity=3,weight=15,position=(16,16)]\n"
                    "Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=7,weight=10,position=(16,17)]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
