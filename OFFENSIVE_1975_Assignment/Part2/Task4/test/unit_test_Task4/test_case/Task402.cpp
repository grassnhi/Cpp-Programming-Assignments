#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task402() {
    string name = "Task402";
    string cfg = "test/unit_test_Task4/test_case/input/config402.txt";
    ofstream ofs(cfg);
    // Scenario: one infantry each, no terrain, eventCode=50 (<75)
    ofs << "NUM_COLS=3\n";
    ofs << "NUM_ROWS=3\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=50\n";
    ofs << "UNIT_LIST=[REGULARINFANTRY(1,1,(1,1),0),REGULARINFANTRY(1,1,(2,2),1)]\n";
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
"LIBERATIONARMY[LF=0,EXP=281]-ARVN[LF=0,EXP=281]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=281]-ARVN[LF=0,EXP=281]";

    remove(cfg.c_str());
    return printResult(result, expect, name);
}