#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task306() {
    string name = "Task306";
    //! data ------------------------------------
    // Test TerrainElement base class constructor and position functionality
    Position pos(3, 4);
    TerrainElement* element = new River(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Create a simple army to test basic functionality
    Infantry* sniper = new Infantry(10, 5, Position(3, 5), SNIPER); // Adjacent to element
    Infantry* antiarcraftsquad = new Infantry(8, 6, Position(3, 7), ANTIAIRCRAFTSQUAD); // Adjacent to element
    Vehicle* truck = new Vehicle(10, 5, Position(4, 4), TRUCK); // Adjacent to element
    Vehicle* mortar = new Vehicle(8, 6, Position(6, 4), MORTAR); // Adjacent to element
    Unit* unitArray[4] = {sniper, antiarcraftsquad, truck, mortar};
    Army* army = new ARVN(unitArray, 4, "TestArmy", nullptr);
    
    output << "Initial Army: " << endl << army->str() << endl;
    element->getEffect(army);
    output << "After Base Effect: " << endl << army->str() << endl;
    
    //! expect ----------------------------------
    // Base TerrainElement shouldn't modify army stats
    string expect = "Initial Army: \n"
                   "ARVN[LF=14,EXP=176,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(3,5)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)]],battleField=]\n"
                   "After Base Effect: \n"
                   "ARVN[LF=14,EXP=176,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(3,5)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)]],battleField=]\n";
    
    //! cleanup ---------------------------------
    delete element;
    delete sniper;
    delete antiarcraftsquad;
    delete truck;
    delete mortar;
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}