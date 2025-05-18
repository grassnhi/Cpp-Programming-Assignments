#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task310() {
    string name = "Task310";
    //! data ------------------------------------
    Position pos(1, 1);
    SpecialZone specialZone(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Test Special Zone effects on different armies
    Infantry* infantry1 = new Infantry(10, 5, Position(1, 1), SNIPER); // At special zone
    Infantry* infantry2 = new Infantry(8, 6, Position(1, 3), ANTIAIRCRAFTSQUAD); // 2 units away
    Vehicle* vehicle1 = new Vehicle(10, 5, Position(2, 2), TRUCK); // ~1.4 units away
    Vehicle* vehicle2 = new Vehicle(8, 6, Position(3, 3), MORTAR); // ~2.8 units away
    
    Unit* unitArray[4] = {infantry1, infantry2, vehicle1, vehicle2};
    Army* liberationArmy = new LiberationArmy(unitArray, 4, "LiberationTest", nullptr);
    
    output << "Initial Liberation Army: " << endl << liberationArmy->str() << endl;
    specialZone.getEffect(liberationArmy);
    output << "After Special Zone Effect (Liberation Army): " << endl << liberationArmy->str() << endl;
    
    //! expect ----------------------------------
    // Special zone should increase LF for Liberation Army but have no effect on ARVN
    string expect = "Initial Liberation Army: \n"
                   "LiberationArmy[LF=14,EXP=176,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(1,3)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(1,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(2,2)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(3,3)]],battleField=]\n"
                   "After Special Zone Effect (Liberation Army): \n"
                   "LiberationArmy[LF=14,EXP=176,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(1,3)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(1,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(2,2)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(3,3)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    for (int i = 0; i < 4; ++i) {
        delete unitArray[i];
    }
    delete liberationArmy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}