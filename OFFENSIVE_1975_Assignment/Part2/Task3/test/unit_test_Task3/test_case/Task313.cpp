#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task313() {
    string name = "Task313";
    //! data ------------------------------------
    Position pos(5, 5);
    SpecialZone specialZone(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Test units exactly at effect radius boundary
    Infantry* infantryEdge = new Infantry(10, 5, Position(8, 5), SNIPER); // Exactly 3 units away (at boundary)
    Infantry* infantryJustInside = new Infantry(10, 5, Position(5, 8), SNIPER); // 3 units away (at boundary)
    Infantry* infantryJustOutside = new Infantry(10, 5, Position(5, 9), SNIPER); // 4 units away (outside range)
    
    Unit* unitArray[3] = {infantryEdge, infantryJustInside, infantryJustOutside};
    Army* army = new LiberationArmy(unitArray, 3, "BoundaryTest", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    specialZone.getEffect(army);
    output << "After Special Zone Effect: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // Units at exactly 3 units away should be affected (inclusively within radius)
    string expect = "Initial Army: \n"
                   "LiberationArmy[LF=0,EXP=180,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=36,weight=5,position=(8,5)]],battleField=]\n"
                   "After Special Zone Effect: \n"
                   "LiberationArmy[LF=0,EXP=180,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=36,weight=5,position=(8,5)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 3; ++i) {
        delete unitArray[i];
    }
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}