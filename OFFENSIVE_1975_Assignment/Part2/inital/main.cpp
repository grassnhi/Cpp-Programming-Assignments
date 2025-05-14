/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 2
* Programming Fundamentals Spring 2025
* Date: 02.02.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "hcmcampaign.h"
#include <fstream> 

using namespace std;

void g_satc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    Configuration* config = new Configuration("config.txt");
    cout << "[num_rows=10,num_cols=8,arrayForest=[(1,2),(3,5)],arrayRiver=[(0,0),(0,4)],arrayFortification=[(6,6)],arrayUrban=[(2,0)],arraySpecialZone=[(9,7)],liberationUnits=[Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(1,2)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=2,position=(1,1)]],ARVNUnits=[Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(3,2)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=2,position=(3,3)]],eventCode=23]" << endl;
    cout << "----" << endl;
    cout << config->str() << endl;
    delete config;
}

void g_satc_02() {
    ofstream ofs("or.txt"); 
    if (!ofs.is_open()) return; 

    Vehicle tankOfLiber(5, 2, Position(1, 2), TANK);
    Vehicle truckOfLiber(3, 1, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(5, 2, Position(1, 1), SNIPER);

    Vehicle tankOfAr(5, 2, Position(3, 2), TANK);
    Vehicle truckOfAr(3, 1, Position(3, 1), TRUCK);
    Infantry sniperOfAr(5, 2, Position(3, 3), SNIPER);

    Unit** unitArrayOfLiber = new Unit*[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;

    Unit** unitArrayOfAr = new Unit*[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "LiberationArmy", 0);
    cout << "Create liberationArmy\n" << liberationArmy->str() << endl;
    ofs << liberationArmy->str() << std::endl;

    ARVN* arvn = new ARVN(unitArrayOfAr, 3, "ARVN", 0);
    cout << "Create ARVN\n" << arvn->str() << endl;
    ofs << arvn->str() << std::endl;

    Army* enemyLiber = arvn;
    liberationArmy->fight(enemyLiber, false);

    cout << "----" << endl;
    
    cout << liberationArmy->str() << std::endl;
    cout << arvn->str() << std::endl;

    cout << "----" << endl;

    Army* enemyAr = liberationArmy;
    arvn->fight(enemyAr, false);

    ofs << "* After the fight" << std::endl;
    ofs << liberationArmy->str() << std::endl;
    ofs << arvn->str() << std::endl;

    delete liberationArmy;
    delete arvn;
    delete[] unitArrayOfLiber;
    delete[] unitArrayOfAr;

    ofs.close();
}

void g_satc_03() {
    cout << "----- Sample Testcase 03 -----" << endl;
    HCMCampaign* campaign = new HCMCampaign("config.txt");

    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;

    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;

    delete campaign;
}

void g_satc_07() {
    cout << "----- Sample Testcase 07 -----" << endl;
    Vehicle tankOfLiber1(20, 20, Position(1, 2), MORTAR);
    Vehicle tankOfLiber2(5, 20, Position(3, 2), MORTAR);
    Infantry sniperOfLiber1(10, 20, Position(1, 0), SNIPER);
    Infantry sniperOfLiber2(10, 20, Position(1, 1), SNIPER);
    Unit** unitArrayOfLiber8 = new Unit*[4];
    unitArrayOfLiber8[0] = &tankOfLiber1;
    unitArrayOfLiber8[1] = &tankOfLiber2;
    unitArrayOfLiber8[2] = &sniperOfLiber1;
    unitArrayOfLiber8[3] = &sniperOfLiber2;
    LiberationArmy* liberationArmy8 = new LiberationArmy(unitArrayOfLiber8, 4, "LiberationArmy", 0);
    cout << liberationArmy8->str() << endl;

    cout << " - - - " << endl;
    cout << "\nLiberationArmy[LF=38,EXP=400,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=20,position=(1,0)],Vehicle[vehicleType=MORTAR,quantity=25,weight=20,position=(1,2)]],battleField=]" << endl;

}


int main(int argc, const char * argv[]) {
    // g_satc_01();
    g_satc_02();
    // g_satc_03();
    // g_satc_07();
    return 0;
}
