#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task307() {
    string name = "Task307";
    //! data ------------------------------------
    Position pos(7, 7);
    River river(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Create various units to test river's effect (should reduce LF for nearby units)
    Infantry* infantryAtRiver = new Infantry(10, 5, Position(7, 7), SNIPER); // At the river
    Infantry* infantryNearby = new Infantry(10, 5, Position(7, 9), SNIPER); // 2 units away
    Infantry* infantryFar = new Infantry(10, 5, Position(7, 12), SNIPER); // 5 units away
    Vehicle* vehicleAtRiver = new Vehicle(10, 5, Position(7, 7), TRUCK); // At the river
    Vehicle* vehicleNearby = new Vehicle(10, 5, Position(9, 7), TRUCK); // 2 units away
    Vehicle* vehicleFar = new Vehicle(10, 5, Position(12, 7), TRUCK); // 5 units away
    
    Unit* unitArray[6] = {infantryAtRiver, infantryNearby, infantryFar, vehicleAtRiver, vehicleNearby, vehicleFar};
    Army* army = new LiberationArmy(unitArray, 6, "RiverTest", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    river.getEffect(army);
    output << "After River Effect: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // River should reduce combat effectiveness (LF)
    string expect = "Initial Army: \n"
                   "LiberationArmy[LF=6,EXP=180,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=36,weight=5,position=(7,7)],Vehicle[vehicleType=TRUCK,quantity=30,weight=5,position=(7,7)]],battleField=]\n"
                   "After River Effect: \n"
                   "LiberationArmy[LF=6,EXP=180,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=36,weight=5,position=(7,7)],Vehicle[vehicleType=TRUCK,quantity=30,weight=5,position=(7,7)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 6; ++i) {
        delete unitArray[i];
    }
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}