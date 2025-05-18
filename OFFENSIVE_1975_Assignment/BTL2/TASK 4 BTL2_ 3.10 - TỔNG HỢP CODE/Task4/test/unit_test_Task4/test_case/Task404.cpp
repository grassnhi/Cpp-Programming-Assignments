#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task404() {
    string name = "Task404";
    string cfg = "test/unit_test_Task4/test_case/input/config404.txt";
    ofstream ofs(cfg);
    // Terrain: forest affects infantry and vehicles
    ofs << "NUM_COLS=6\n";
    ofs << "NUM_ROWS=6\n";
    ofs << "ARRAY_FOREST=[(3,3)]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=10\n";
    ofs << "UNIT_LIST=[REGULARINFANTRY(2,2,(3,2),0),TANK(1,5,(3,4),1)]\n";
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
    // TODO: expected after applying forest effect and fight rules
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=0,EXP=286]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=286]-ARVN[LF=61,EXP=0]";

    remove(cfg.c_str());
    return printResult(result, expect, name);
}
