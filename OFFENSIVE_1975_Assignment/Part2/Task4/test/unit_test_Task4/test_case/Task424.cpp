#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task424() {
    string name = "Task424";
    

    Vehicle tankOfLiber5(20, 20, Position(1, 2), MORTAR);
    string result = tankOfLiber5.str();
    string expect = "Vehicle[vehicleType=MORTAR,quantity=20,weight=20,position=(1,2)]";

    
    return printResult(result, expect, name);
}