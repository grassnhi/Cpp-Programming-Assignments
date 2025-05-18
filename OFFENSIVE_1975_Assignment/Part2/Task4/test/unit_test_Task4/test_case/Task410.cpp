#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task410() {
    string name = "Task410";
    string cfg = "test/unit_test_Task4/test_case/input/config410.txt";
    ofstream ofs(cfg);
    // Capacity limit: many units added, list should cap at 12 or 8
    ofs << "NUM_COLS=10\n";
    ofs << "NUM_ROWS=10\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=5\n";
    ofs << "UNIT_LIST=[";
    for (int i = 0; i < 15; ++i) {
        ofs << "TANK(1,1,(" << (i%10+1) << "," << (i%10+1) << "),0)";
        if (i < 14) ofs << ",";
    }
    for (int i = 0; i < 15; ++i) {
        ofs << "TRUCK(3,3,(" << (i%10+1) << "," << (i%10+1) << "),1)";
        if (i < 14) ofs << ",";
    }
    ofs << "]\n";
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
"LIBERATIONARMY[LF=915,EXP=0]-ARVN[LF=15,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=62,EXP=0]-ARVN[LF=5,EXP=0]";
    remove(cfg.c_str());
    return printResult(result, expect, name);
}
