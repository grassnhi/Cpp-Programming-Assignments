#include "../unit_test_Task2.hpp"

bool UNIT_TEST_Task2::Task251()
{
    string name = "Task221";
    //! data ------------------------------------
    Vehicle tankOfLiber(20, 20, Position(1, 2), MORTAR);
    Vehicle truckOfLiber(15, 10, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(10, 20, Position(1, 1), SNIPER);

    Vehicle tankOfAr(5, 20, Position(3, 2), MORTAR);
    Vehicle truckOfAr(1, 10, Position(3, 1), TRUCK);
    Infantry sniperOfAr(7, 20, Position(3, 3), SNIPER);

    Unit** unitArrayOfLiber = new Unit*[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;

    Unit** unitArrayOfAr = new Unit*[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "LiberationArmy");
    ARVN* arvn = new ARVN(unitArrayOfAr, 3, "ARVN"); 
    stringstream output;
    output << liberationArmy->str() << endl;
    output << arvn->str() << endl;   
    
    //! process ---------------------------------
    Army* enemyLiber = arvn;
    liberationArmy->fight(enemyLiber, false);
    Army* enemyAr = liberationArmy;
    arvn->fight(enemyAr, false);
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=29,EXP=200,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=10,weight=20,position=(1,1)],Vehicle[vehicleType=MORTAR,quantity=20,weight=20,position=(1,2)],Vehicle[vehicleType=TRUCK,quantity=15,weight=10,position=(2,2)]]]\n"
                    "ARVN[LF=15,EXP=180,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=9,weight=20,position=(3,3)],Vehicle[vehicleType=MORTAR,quantity=5,weight=20,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=1,weight=10,position=(3,1)]]]\n"
                    "* After the fight\n"
                    "LiberationArmy[LF=20,EXP=180,unitList=UnitList[count_vehicle=2;count_infantry=1;"
                    "Infantry[infantryType=SNIPER,quantity=9,weight=20,position=(3,3)],"
                    "Vehicle[vehicleType=TRUCK,quantity=16,weight=10,position=(2,2)],"
                    "Vehicle[vehicleType=MORTAR,quantity=5,weight=20,position=(3,2)]]]\n"
                    "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0]]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    output << "* After the fight" << endl;
    output << liberationArmy->str() << endl;
    output << arvn->str() << endl;
    
    //! remove data -----------------------------
    delete liberationArmy;
    delete arvn;
    delete[] unitArrayOfLiber;
    delete[] unitArrayOfAr;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task252()
{
    string name = "Task222";
    //! data ------------------------------------
    Vehicle tankOfLiber1(20, 20, Position(1, 2), MORTAR);
    Vehicle tankOfLiber2(5, 20, Position(3, 2), MORTAR);
    Infantry sniperOfLiber1(10, 20, Position(1, 0), SNIPER);
    Infantry sniperOfLiber2(10, 20, Position(1, 1), SNIPER);
    Unit** unitArrayOfLiber8 = new Unit*[4];
    unitArrayOfLiber8[0] = &tankOfLiber1;
    unitArrayOfLiber8[1] = &tankOfLiber2;
    unitArrayOfLiber8[2] = &sniperOfLiber1;
    unitArrayOfLiber8[3] = &sniperOfLiber2;
    LiberationArmy* liberationArmy8 = new LiberationArmy(unitArrayOfLiber8, 4, "LiberationArmy");
    
    //! process ---------------------------------
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=38,EXP=400,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=20,weight=20,position=(1,0)],Vehicle[vehicleType=MORTAR,quantity=25,weight=20,position=(1,2)]]]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    stringstream output;
    output << liberationArmy8->str() << endl;
    
    //! remove data -----------------------------
    delete liberationArmy8;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}