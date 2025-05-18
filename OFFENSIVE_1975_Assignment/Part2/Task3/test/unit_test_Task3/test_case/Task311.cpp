#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task311() {
    string name = "Task311";
    //! data ------------------------------------
    Position pos1(0, 0);
    Position pos2(1, 1);
    Mountain mountain(pos1);
    River river(pos2);
    stringstream output;
    
    //! process ---------------------------------
    // Test cumulative effects of multiple terrain elements
    Infantry* infantry = new Infantry(10, 5, Position(0, 1), SNIPER); // Near forest but also near river
    Vehicle* vehicle = new Vehicle(10, 5, Position(1, 0), TRUCK); // Near river and forest
    
    Unit* unitArray[2] = {infantry, vehicle};
    Army* army = new LiberationArmy(unitArray, 2, "MultiTerrainTest", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    mountain.getEffect(army);
    output << "After Forest Effect: " << endl << army->str() << endl;
    river.getEffect(army);
    output << "After Forest + River Effects: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // Should see cumulative effects - increased EXP from forest, decreased LF from river
    string expect = "Initial Army: \n"
                   "LiberationArmy[LF=2,EXP=60,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,0)]],battleField=]\n"
                   "After Forest Effect: \n"
                   "LiberationArmy[LF=2,EXP=78,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,0)]],battleField=]\n"
                   "After Forest + River Effects: \n"
                   "LiberationArmy[LF=2,EXP=78,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,0)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    delete infantry;
    delete vehicle;
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}