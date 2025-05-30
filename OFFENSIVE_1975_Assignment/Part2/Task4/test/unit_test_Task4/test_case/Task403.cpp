#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task403() {
    string name = "Task403";
    
    
    string cfg = "test/unit_test_Task4/test_case/input/config403.txt";
    ofstream ofs(cfg);
    // Scenario: eventCode >=75, ARVN attacks and Liberation counter-attacks
    ofs << "NUM_COLS=4\n";
    ofs << "NUM_ROWS=4\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=80\n";
    ofs << "UNIT_LIST=[TANK(1,2,(1,1),1),REGULARINFANTRY(2,2,(3,2),0),TANK(2,2,(2,2),0)]\n";
    ofs.close();

    HCMCampaign* campaign = nullptr;
    string result;
    try {
        campaign = new HCMCampaign(cfg);
        result = "** Before the fight\n";
        result += campaign->printResult();
        result += "\n** After the fight\n";
        campaign->run();
        result += campaign->printResult();
        delete campaign;
    } catch (exception &e) {
        result = e.what();
    }
    // TODO: set expected after manual calculation
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=61,EXP=286]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=0,EXP=0]";

    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}