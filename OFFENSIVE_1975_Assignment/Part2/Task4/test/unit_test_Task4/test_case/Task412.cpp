#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task412() {
    string name = "Task412";
    
    
    string cfg = "test/unit_test_Task4/test_case/input/config412.txt";
    ofstream ofs(cfg);
    ofs << "NUM_COLS=4\n";
    ofs << "NUM_ROWS=4\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=-5\n"; // should clamp to 0
    ofs << "UNIT_LIST=[TANK(1,1,(2,2),1)]\n";
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
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=61,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

