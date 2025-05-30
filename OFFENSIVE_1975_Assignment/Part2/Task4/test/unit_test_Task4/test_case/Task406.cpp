#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task406() {
    string name = "Task406";

    
    
    string cfg = "test/unit_test_Task4/test_case/input/config406.txt";
    ofstream ofs(cfg);
    // River-heavy map, infantry slow and penalized
    ofs << "NUM_COLS=5\n";
    ofs << "NUM_ROWS=5\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[(1,1),(1,5),(5,1),(5,5)]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=60\n";
    ofs << "UNIT_LIST=[MORTARSQUAD(3,2,(2,2),0),ENGINEER(2,3,(3,3),1)]\n";
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
"LIBERATIONARMY[LF=0,EXP=118]-ARVN[LF=0,EXP=174]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=118]-ARVN[LF=0,EXP=174]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

