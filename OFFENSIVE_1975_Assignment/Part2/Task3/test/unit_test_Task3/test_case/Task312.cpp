#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task312() {
    string name = "Task312";
    //! data ------------------------------------
    Position pos(5, 5);
    Mountain mountain(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Test terrain effects on an army with no units
    Unit* emptyArray[0] = {};
    Army* emptyArmy = new LiberationArmy(emptyArray, 0, "EmptyArmy", nullptr);
    
    output << "Initial Empty Army: " << endl << emptyArmy->str() << endl;
    mountain.getEffect(emptyArmy);
    output << "After Mountain Effect: " << endl << emptyArmy->str() << endl;
    
    //! expect ----------------------------------
    // Mountain shouldn't change anything since there are no units
    string expect = "Initial Empty Army: \n"
                   "LiberationArmy[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"
                   "After Mountain Effect: \n"
                   "LiberationArmy[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n";
    
    //! cleanup ---------------------------------
    delete emptyArmy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}