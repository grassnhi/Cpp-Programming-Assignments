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
    cout << "----- Triet's test 4 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf4.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
}

void g_satc_03() {
    cout << "----- Triet's test 3 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf3.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
}

void g_satc_07() {
    cout << "----- Triet's test 2 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf2.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
}

void printFile(const string& filename) {
    ifstream inFile(filename.c_str());
    if (!inFile) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}


void g_satc_ct_test1() {
    cout << "----- Testcase COMPLEX -----" << endl;
    HCMCampaign* campaign = new HCMCampaign("tests/ct_test2.txt");
    cout << "* Before the fight" << endl;
    cout << campaign->printResult() << endl;
    campaign->run();
    cout << "* After the fight" << endl;
    cout << campaign->printResult() << endl;
    delete campaign;
}

int main(int argc, const char * argv[]) {
    // g_satc_ct_test1();
    // g_satc_07();
    g_satc_03();
    // g_satc_02();

    return 0;
}
