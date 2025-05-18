#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task308() {
    string name = "Task308";
    //! data ------------------------------------
    Position pos(3, 3);
    Fortification fortification(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Create armies to test fortification effects on both army types
    Infantry* infantryNear = new Infantry(10, 5, Position(3, 4), SNIPER); // 1 unit away
    Vehicle* vehicleNear = new Vehicle(10, 5, Position(4, 3), TRUCK); // 1 unit away
    Infantry* infantryFar = new Infantry(10, 5, Position(3, 8), SNIPER); // 5 units away
    Vehicle* vehicleFar = new Vehicle(10, 5, Position(8, 3), TRUCK); // 5 units away
    
    Unit* unitArray[4] = {infantryNear, vehicleNear, infantryFar, vehicleFar};
    Army* liberationArmy = new LiberationArmy(unitArray, 4, "LiberationTest", nullptr);

    // Create armies to test fortification effects on both army types
    Infantry* infantryNear2 = new Infantry(10, 5, Position(3, 4), SNIPER); // 1 unit away
    Vehicle* vehicleNear2 = new Vehicle(10, 5, Position(4, 3), TRUCK); // 1 unit away
    Infantry* infantryFar2 = new Infantry(10, 5, Position(3, 8), SNIPER); // 5 units away
    Vehicle* vehicleFar2 = new Vehicle(10, 5, Position(8, 3), TRUCK); // 5 units away
    Unit* unitArray2[4] = {infantryNear2, vehicleNear2, infantryFar2, vehicleFar2};
    Army* arvnArmy = new ARVN(unitArray2, 4, "ARVNTest", nullptr);
    
    output << "Initial Liberation Army: " << endl << liberationArmy->str() << endl;
    fortification.getEffect(liberationArmy);
    output << "After Fortification Effect (Liberation Army): " << endl << liberationArmy->str() << endl;
    
    output << "Initial ARVN Army: " << endl << arvnArmy->str() << endl;
    fortification.getEffect(arvnArmy);
    output << "After Fortification Effect (ARVN Army): " << endl << arvnArmy->str() << endl;
    
    //! expect ----------------------------------
    // Fortification should increase LF for Liberation Army but decrease for ARVN
    string expect = "Initial Liberation Army: \n"
                   "LiberationArmy[LF=4,EXP=120,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=5,position=(3,4)],Vehicle[vehicleType=TRUCK,quantity=20,weight=5,position=(4,3)]],battleField=]\n"
                   "After Fortification Effect (Liberation Army): \n"
                   "LiberationArmy[LF=4,EXP=120,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=5,position=(3,4)],Vehicle[vehicleType=TRUCK,quantity=20,weight=5,position=(4,3)]],battleField=]\n"
                   "Initial ARVN Army: \n"
                   "ARVN[LF=4,EXP=120,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=5,position=(3,4)],Vehicle[vehicleType=TRUCK,quantity=20,weight=5,position=(4,3)]],battleField=]\n"
                   "After Fortification Effect (ARVN Army): \n"
                   "ARVN[LF=4,EXP=120,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=5,position=(3,4)],Vehicle[vehicleType=TRUCK,quantity=20,weight=5,position=(4,3)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 4; ++i) {
        delete unitArray[i];
    }
    for (int i = 0; i < 4; ++i) {
        delete unitArray2[i];
    }
    delete liberationArmy;
    delete arvnArmy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}