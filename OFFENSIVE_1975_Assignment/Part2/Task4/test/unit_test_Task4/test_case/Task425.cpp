#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task425() {
    string name = "Task425";

    Unit** unitArrayOfLiber6 = new Unit*[1];
    Vehicle tankOfLiber6(20, 20, Position(1, 2), MORTAR);
    unitArrayOfLiber6[0] = &tankOfLiber6;

    LiberationArmy* liberationArmy6 = new LiberationArmy(unitArrayOfLiber6, 0, "LiberationArmy", 0);
    string result = liberationArmy6->str();
    string expect = "LiberationArmy[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]";

    delete liberationArmy6;
    delete[] unitArrayOfLiber6;

    return printResult(result, expect, name);
}