#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task420() {
    string name = "Task420";
    
    string cfg = "test/unit_test_Task4/test_case/input/config420.txt";
    ofstream ofs(cfg);
    // Edge case: missing EVENT_CODE line -> default to 0 (Liberation attacks)
    ofs << "NUM_COLS=4\n";
    ofs << "NUM_ROWS=4\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=179\n";
    ofs << "UNIT_LIST=[TANK(1,3,(2,2),1),SNIPER(1,2,(3,3),0)]\n";
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
    } catch(exception &e) {
        result = e.what();
    }
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=0,EXP=2]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=0,EXP=0]";
    if(campaign) delete campaign;
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}