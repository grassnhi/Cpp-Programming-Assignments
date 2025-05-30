#include "../unit_test_Task4.hpp"

// Edge cases: invalid EVENT_CODE mapping
bool UNIT_TEST_Task4::Task411() {
    string name = "Task411";
    
    
    string cfg = "test/unit_test_Task4/test_case/input/config411.txt";
    ofstream ofs(cfg);
    ofs << "NUM_COLS=3\n";
    ofs << "NUM_ROWS=3\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=150\n"; // should map to 50
    ofs << "UNIT_LIST=[REGULARINFANTRY(1,1,(1,1),0)]\n";
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
"LIBERATIONARMY[LF=0,EXP=281]-ARVN[LF=0,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=281]-ARVN[LF=0,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

