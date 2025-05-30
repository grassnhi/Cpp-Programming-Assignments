#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task409() {
    string name = "Task409";
    string cfg = "test/unit_test_Task4/test_case/input/config409.txt";
    ofstream ofs(cfg);
    // Special zones nullify all nearby units
    ofs << "NUM_COLS=6\n";
    ofs << "NUM_ROWS=6\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(3,3)]\n";
    ofs << "EVENT_CODE=40\n";
    ofs << "UNIT_LIST=[ANTIAIRCRAFT(1,4,(3,2),0),SNIPER(2,3,(2,3),1)]\n";
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
"LIBERATIONARMY[LF=21,EXP=0]-ARVN[LF=0,EXP=6]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=21,EXP=0]-ARVN[LF=0,EXP=0]";
    remove(cfg.c_str());
    return printResult(result, expect, name);
}

