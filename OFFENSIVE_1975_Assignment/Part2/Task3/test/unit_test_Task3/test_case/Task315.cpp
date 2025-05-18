#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task315() {
    string name = "Task315";
    //! data ------------------------------------
    // Test TerrainElement base class constructor and position functionality
    int row = 7;
    int col = 5;

    TerrainElement*** map_element = new TerrainElement**[row];
    for (int i = 0; i < row; ++i) {
        map_element[i] = new TerrainElement*[col];
        for (int j = 0; j < col; ++j) {
            if (i % 2 == 0 && j % 3 == 0) {
                map_element[i][j] = new Road(Position(i, j));
            } else if (i % 2 == 0 && j % 3 == 1) {
                map_element[i][j] = new Mountain(Position(i, j));
            } else if (i % 2 == 0 && j % 3 == 2) {
                map_element[i][j] = new River(Position(i, j));
            } else if (i % 2 == 0 && j % 3 == 0) {
                map_element[i][j] = new SpecialZone(Position(i, j));
            } else if (i % 2 == 1 && j % 3 == 1) {
                map_element[i][j] = new Fortification(Position(i, j));
            } else if (i % 2 == 1 && j % 3 == 2) {
                map_element[i][j] = new Urban(Position(i, j));
            } else {
                map_element[i][j] = new Road(Position(i, j));
            }
        }
    }

    stringstream output;
    
    //! process ---------------------------------
    // Create a simple army to test basic functionality
    Infantry* sniper = new Infantry(10, 5, Position(3, 5), SNIPER); // Adjacent to element
    Infantry* antiarcraftsquad = new Infantry(8, 6, Position(3, 7), ANTIAIRCRAFTSQUAD); // Adjacent to element
    Vehicle* truck = new Vehicle(10, 5, Position(4, 4), TRUCK); // Adjacent to element
    Vehicle* mortar = new Vehicle(8, 6, Position(6, 4), MORTAR); // Adjacent to element
    Unit* unitArray[4] = {sniper, antiarcraftsquad, truck, mortar};
    Army* arvn = new ARVN(unitArray, 4, "TestArmy", nullptr);

    Infantry* engineer = new Infantry(5, 8, Position(0, 2), ENGINEER); // Within radius 2
    Infantry* specialforces = new Infantry(4, 9, Position(0, 3), SPECIALFORCES); // Within radius 2
    Infantry* regularinfantry = new Infantry(3, 10, Position(0, 3), REGULARINFANTRY); // Within radius 2
    Vehicle* apc = new Vehicle(4, 9, Position(0, 3), APC); // Within radius 2
    Vehicle* artillery = new Vehicle(3, 10, Position(0, 3), ARTILLERY);
    Vehicle* tank = new Vehicle(2, 11, Position(0, 4), TANK);
    Unit* unitArray2[6] = {engineer, specialforces, apc, regularinfantry, artillery, tank};
    Army* liber = new LiberationArmy(unitArray2, 6, "TestArmy", nullptr);
    
    output << "Initial Army: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "Liberation attack ARVN: " << endl;
    liber->fight(arvn, false);
    output << "After Attack: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "ARVN defends Liberation: " << endl;
    arvn->fight(liber, true);
    output << "After defends: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "Terrain Elements get effect: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            map_element[i][j]->getEffect(liber);
            map_element[i][j]->getEffect(arvn);
        }
    }
    output << "After Base Effect: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "ARVN attack Liberation: " << endl;
    arvn->fight(liber, false);
    output << "After Attack: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "Liberation defends ARVN: " << endl;
    liber->fight(arvn, true);
    output << "After defends: " << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;
    
    //! expect ----------------------------------
    // Base TerrainElement shouldn't modify army stats
    string expect = "Initial Army: \n"
                    "1. LiberationArmy[LF=156,EXP=500,unitList=UnitList[count_vehicle=3;count_infantry=3;"
                    "Infantry[infantryType=REGULARINFANTRY,quantity=4,weight=10,position=(0,3)],"
                    "Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],"
                    "Infantry[infantryType=ENGINEER,quantity=5,weight=8,position=(0,2)],"
                    "Vehicle[vehicleType=APC,quantity=4,weight=9,position=(0,3)],"
                    "Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],"
                    "Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)]],battleField=]\n"
                    "2. ARVN[LF=14,EXP=176,unitList=UnitList[count_vehicle=2;count_infantry=2;"
                    "Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],"
                    "Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(3,5)],"
                    "Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)],"
                    "Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)]],battleField=]\n"
                    "Liberation attack ARVN: \n"
                    "After Attack: \n"
                    "1. LiberationArmy[LF=128,EXP=500,unitList=UnitList[count_vehicle=4;count_infantry=4;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(3,5)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)]],battleField=]\n"
                    "2. ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"
                    "ARVN defends Liberation: \n"
                    "After defends: \n"
                    "1. LiberationArmy[LF=128,EXP=500,unitList=UnitList[count_vehicle=4;count_infantry=4;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(3,5)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)]],battleField=]\n"
                    "2. ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"
                    "Terrain Elements get effect: \n"
                    "After Base Effect: \n"
                    "1. LiberationArmy[LF=105,EXP=500,unitList=UnitList[count_vehicle=4;count_infantry=4;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(3,5)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)]],battleField=]\n"
                    "2. ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"
                    "ARVN attack Liberation: \n"
                    "After Attack: \n"
                    "1. LiberationArmy[LF=105,EXP=500,unitList=UnitList[count_vehicle=4;count_infantry=4;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(3,5)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)]],battleField=]\n"
                    "2. ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"
                    "Liberation defends ARVN: \n"
                    "After defends: \n"
                    "1. LiberationArmy[LF=137,EXP=500,unitList=UnitList[count_vehicle=4;count_infantry=4;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=6,position=(3,7)],Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(3,5)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=10,position=(0,3)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)],Vehicle[vehicleType=MORTAR,quantity=8,weight=6,position=(6,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(4,4)]],battleField=]\n"
                    "2. ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n";
    
    //! cleanup ---------------------------------
    delete sniper;
    delete antiarcraftsquad;
    delete truck;
    delete mortar;
    delete engineer;
    delete specialforces;
    delete regularinfantry;
    delete apc;
    delete artillery;
    delete tank;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            delete map_element[i][j];
        }
        delete[] map_element[i];
    }
    delete[] map_element;
    delete arvn;
    delete liber;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}