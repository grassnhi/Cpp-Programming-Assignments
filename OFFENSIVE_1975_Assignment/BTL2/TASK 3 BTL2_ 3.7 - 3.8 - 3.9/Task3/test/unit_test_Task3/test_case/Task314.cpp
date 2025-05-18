#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task314() {
    string name = "Task314";
    //! data ------------------------------------
    Position pos(10, 10);
    Mountain mountain(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Test with very distant and very close units
    Infantry* infantryVeryClose = new Infantry(10, 5, Position(10, 10), SNIPER); // Distance = 0
    Infantry* infantryMaxRange = new Infantry(10, 5, Position(7, 10), SNIPER); // Distance = 3 (max effective range)
    Infantry* infantryDistant = new Infantry(10, 5, Position(100, 100), SNIPER); // Very far away
    Infantry* infantryNegativePos = new Infantry(10, 5, Position(-10, -10), SNIPER); // Negative coordinates (very far)
    
    Unit* unitArray[4] = {infantryVeryClose, infantryMaxRange, infantryDistant, infantryNegativePos};
    Army* army = new LiberationArmy(unitArray, 4, "DistanceTest", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    mountain.getEffect(army);
    output << "After Forest Effect: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // Only units within range should be affected
    string expect = "Initial Army: \n"
                   "LiberationArmy[LF=0,EXP=240,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=44,weight=5,position=(10,10)]],battleField=]\n"
                   "After Forest Effect: \n"
                   "LiberationArmy[LF=0,EXP=306,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=44,weight=5,position=(10,10)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 4; ++i) {
        delete unitArray[i];
    }
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}