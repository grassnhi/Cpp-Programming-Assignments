#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task304() {
    string name = "Task304";
    //! data ------------------------------------
    // Test TerrainElement constructor with Position
    Position pos(0, 0);
    Mountain mountain(pos);
    stringstream output;
    
    //! process ---------------------------------
    // Check if the position is correctly stored (indirectly through effect)
    Infantry* sniper = new Infantry(10, 5, Position(0, 1), SNIPER); // Within radius 2
    Infantry* antiarcraftsquad = new Infantry(8, 6, Position(0, 2), ANTIAIRCRAFTSQUAD); // Within radius 2
    Infantry* mortarsquad = new Infantry(6, 7, Position(0, 3), MORTARSQUAD); // Within radius 2
    Vehicle* truck = new Vehicle(10, 5, Position(0, 0), TRUCK); // Within radius 2
    Vehicle* mortar = new Vehicle(8, 6, Position(0, 1), MORTAR); // Within radius 2
    Vehicle* antiaircraft = new Vehicle(6, 7, Position(0, 2), ANTIAIRCRAFT); // Within radius 2
    Vehicle* armoredcar = new Vehicle(5, 8, Position(0, 3), ARMOREDCAR); // Within radius 2
    Infantry* engineer = new Infantry(5, 8, Position(0, 4), ENGINEER); // Within radius 2
    Infantry* specialforces = new Infantry(4, 9, Position(0, 5), SPECIALFORCES); // Within radius 2
    Infantry* regularinfantry = new Infantry(3, 10, Position(0, 0), REGULARINFANTRY); // Within radius 2
    Vehicle* apc = new Vehicle(4, 9, Position(0, 4), APC); // Within radius 2
    Vehicle* artillery = new Vehicle(3, 10, Position(0, 5), ARTILLERY);
    Vehicle* tank = new Vehicle(2, 11, Position(0, 6), TANK);  
    Unit* unitArray1[13] = {sniper, antiarcraftsquad, mortarsquad, truck, mortar, antiaircraft, engineer, specialforces, regularinfantry, armoredcar, apc, artillery, tank};
    Army* army1 = new ARVN(unitArray1, 13, "Army1", 0);
    output << "Init Info:" << endl << army1->str() << endl;
    mountain.getEffect(army1);
    output << "After Mountain Effect:" << endl << army1->str() << endl;
    
    //! expect ----------------------------------
    // Road doesn't affect army stats
    string expect = "Init Info:\n"
                    "ARVN[LF=224,EXP=500,unitList=UnitList[count_vehicle=3;count_infantry=5;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,5)],Infantry[infantryType=ENGINEER,quantity=5,weight=8,position=(0,4)],Infantry[infantryType=MORTARSQUAD,quantity=6,weight=7,position=(0,3)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(0,0)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(0,1)],Vehicle[vehicleType=ANTIAIRCRAFT,quantity=6,weight=7,position=(0,2)]],battleField=]\n"
                    "After Mountain Effect:\n"
                    "ARVN[LF=223,EXP=500,unitList=UnitList[count_vehicle=3;count_infantry=5;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,5)],Infantry[infantryType=ENGINEER,quantity=5,weight=8,position=(0,4)],Infantry[infantryType=MORTARSQUAD,quantity=6,weight=7,position=(0,3)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(0,0)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(0,1)],Vehicle[vehicleType=ANTIAIRCRAFT,quantity=6,weight=7,position=(0,2)]],battleField=]\n";
    
    //! output ----------------------------------
    
    //! remove data -----------------------------
    for (int i = 0; i < 13; ++i) {
        delete unitArray1[i];
    }
    delete army1;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}