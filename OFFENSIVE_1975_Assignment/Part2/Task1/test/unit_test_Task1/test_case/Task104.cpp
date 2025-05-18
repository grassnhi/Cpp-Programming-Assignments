#include "../unit_test_Task1.hpp"

bool UNIT_TEST_Task1::Task104()
{
    // Test Vehicle: định dạng chuỗi xuất
    string name = "Task104";
    //! data ------------------------------------
    int quantity = 4;
    int weight = 12;
    Position pos(3, 4);
    VehicleType vt = ARTILLERY; // ARTILLERY có giá trị 5
    //! process ---------------------------------
    Vehicle vehicle(quantity, weight, pos, vt);
    string result = vehicle.str();
    
    //! expect ----------------------------------
    string expect = "Vehicle[vehicleType=ARTILLERY,quantity=4,weight=12,position=(3,4)]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
