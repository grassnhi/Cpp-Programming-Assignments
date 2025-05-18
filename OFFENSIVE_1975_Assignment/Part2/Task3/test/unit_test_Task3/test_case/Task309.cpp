#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task309() {
    string name = "Task309";
    //! data ------------------------------------
    Position pos(6, 6);
    Urban urban(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Test Urban effects on different unit types at different distances
    Infantry* riNear1 = new Infantry(10, 5, Position(6, 6), REGULARINFANTRY); // Inside urban area
    Infantry* riNear2 = new Infantry(10, 5, Position(10, 6), REGULARINFANTRY); // ~1.4 units away
    Infantry* riFar = new Infantry(10, 5, Position(12, 6), REGULARINFANTRY); // ~2.8 units away
    Infantry* spNear = new Infantry(10, 5, Position(8, 8), SPECIALFORCES); // ~2.8 units away
    Infantry* spFar = new Infantry(10, 5, Position(11, 11), SPECIALFORCES); 
    Vehicle* vehicleInside = new Vehicle(10, 5, Position(6, 6), ARTILLERY); // Inside urban area
    Vehicle* vehicleNearby = new Vehicle(10, 5, Position(8, 6), ARTILLERY); // 2 units away
    Vehicle* vehicleFar = new Vehicle(10, 5, Position(10, 10), ARTILLERY); // ~5.7 units away
    
    Unit* unitArray[8] = {riNear1, riNear2, riFar, spNear, spFar, vehicleInside, vehicleNearby, vehicleFar};
    Army* army = new ARVN(unitArray, 8, "UrbanTest", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    urban.getEffect(army);
    output << "After Urban Effect: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // Urban areas should affect nearby units' experience
    string expect = "Initial Army: \n"
                   "ARVN[LF=159,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=24,weight=5,position=(8,8)],Infantry[infantryType=REGULARINFANTRY,quantity=27,weight=5,position=(6,6)],Vehicle[vehicleType=ARTILLERY,quantity=30,weight=5,position=(6,6)]],battleField=]\n"
                   "After Urban Effect: \n"
                   "ARVN[LF=159,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=24,weight=5,position=(8,8)],Infantry[infantryType=REGULARINFANTRY,quantity=27,weight=5,position=(6,6)],Vehicle[vehicleType=ARTILLERY,quantity=30,weight=5,position=(6,6)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 8; ++i) {
        delete unitArray[i];
    }
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}