#include "../unit_test_Task4.hpp"
bool UNIT_TEST_Task4::Task414() {
    string name = "Task414";
    
    
    string cfg = "test/unit_test_Task4/test_case/input/config414.txt";
    ofstream ofs(cfg);
    // Mixed armies with counter-attack scenario
    ofs << "NUM_COLS=6\n";
    ofs << "NUM_ROWS=6\n";
    ofs << "ARRAY_FOREST=[(2,3)]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=90\n";
    ofs << "UNIT_LIST=[TANK(2,3,(1,1),1),REGULARINFANTRY(3,2,(2,3),0),";
    ofs << "ANTIAIRCRAFT(1,2,(3,2),0)]\n";
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
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=21,EXP=286]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=21,EXP=286]-ARVN[LF=61,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

