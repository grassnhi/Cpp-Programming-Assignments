#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task407() {
    string name = "Task407";

    
    
    string cfg = "test/unit_test_Task4/test_case/input/config407.txt";
    ofstream ofs(cfg);
    // Fortification benefits ARVN, Liberation penalized
    ofs << "NUM_COLS=7\n";
    ofs << "NUM_ROWS=7\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[(3,3),(4,5)]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=30\n";
    ofs << "UNIT_LIST=[REGULARINFANTRY(4,2,(3,2),0),TRUCK(2,3,(4,6),1)]\n";
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
"LIBERATIONARMY[LF=0,EXP=288]-ARVN[LF=1,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=288]-ARVN[LF=0,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}



