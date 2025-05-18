#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task302() {
    string name = "Task302";
    //! data ------------------------------------
    // Test TerrainElement constructor with Position
    Position pos("(0,0)");
    Road road(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Check if the position is correctly stored (indirectly through effect)
    Infantry* sniper = new Infantry(10, 5, Position(0, 1), SNIPER); // Within radius 2
    Infantry* antiarcraftsquad = new Infantry(8, 6, Position(0, 1), ANTIAIRCRAFTSQUAD); // Within radius 2
    Infantry* mortarsquad = new Infantry(6, 7, Position(0, 2), MORTARSQUAD); // Within radius 2
    Infantry* engineer = new Infantry(5, 8, Position(0, 2), ENGINEER); // Within radius 2
    Infantry* specialforces = new Infantry(4, 9, Position(0, 3), SPECIALFORCES); // Within radius 2
    Infantry* regularinfantry = new Infantry(3, 10, Position(0, 3), REGULARINFANTRY); // Within radius 2
    Vehicle* truck = new Vehicle(10, 5, Position(0, 1), TRUCK); // Within radius 2
    Vehicle* mortar = new Vehicle(8, 6, Position(0, 1), MORTAR); // Within radius 2
    Vehicle* antiaircraft = new Vehicle(6, 7, Position(0, 2), ANTIAIRCRAFT); // Within radius 2
    Vehicle* armoredcar = new Vehicle(5, 8, Position(0, 2), ARMOREDCAR); // Within radius 2
    Vehicle* apc = new Vehicle(4, 9, Position(0, 3), APC); // Within radius 2
    Vehicle* artillery = new Vehicle(3, 10, Position(0, 3), ARTILLERY);
    Vehicle* tank = new Vehicle(2, 11, Position(0, 4), TANK); 
    Unit* unitArray1[13] = {sniper, antiarcraftsquad, mortarsquad, engineer, specialforces, regularinfantry,
                         truck, mortar, antiaircraft, armoredcar, apc, artillery, tank};
    Army* army1 = new ARVN(unitArray1, 13, "Army1", 0);
    output << "Init Info:" << endl << army1->str() << endl;
    road.getEffect(army1);
    output << "After Road Effect:" << endl << army1->str() << endl;
    
    //! expect ----------------------------------
    // Road doesn't affect army stats
    string expect = "Init Info:\n"
                    "ARVN[LF=224,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=6;Infantry[infantryType=REGULARINFANTRY,quantity=4,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Infantry[infantryType=ENGINEER,quantity=5,weight=8,position=(0,2)],Infantry[infantryType=MORTARSQUAD,quantity=6,weight=7,position=(0,2)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(0,1)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(0,1)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(0,1)]],battleField=]\n"
                    "After Road Effect:\n"
                    "ARVN[LF=224,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=6;Infantry[infantryType=REGULARINFANTRY,quantity=4,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Infantry[infantryType=ENGINEER,quantity=5,weight=8,position=(0,2)],Infantry[infantryType=MORTARSQUAD,quantity=6,weight=7,position=(0,2)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(0,1)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(0,1)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(0,1)]],battleField=]\n";
    
    //! output ----------------------------------
    
    //! remove data -----------------------------
    for (int i = 0; i < 13; ++i) {
        delete unitArray1[i];
    }
    delete army1;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}