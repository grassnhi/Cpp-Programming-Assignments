#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task405() {
    string name = "Task405";
    string cfg = "test/unit_test_Task4/test_case/input/config405.txt";
    ofstream ofs(cfg);
    // All terrain types scattered, multiple units per side
    ofs << "NUM_COLS=10\n";
    ofs << "NUM_ROWS=10\n";
    ofs << "ARRAY_FOREST=[(2,2),(7,7)]\n";
    ofs << "ARRAY_RIVER=[(4,1),(1,5),(8,3)]\n";
    ofs << "ARRAY_FORTIFICATION=[(3,6),(6,4)]\n";
    ofs << "ARRAY_URBAN=[(5,5),(2,7)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(1,8),(8,1)]\n";
    ofs << "EVENT_CODE=20\n";
    ofs << "UNIT_LIST=[TANK(2,3,(2,1),0),ARTILLERY(1,4,(2,3),0),";
    ofs << "REGULARINFANTRY(3,2,(3,2),1),SPECIALFORCES(1,5,(6,4),1),";
    ofs << "MORTARSQUAD(2,3,(7,7),0),ARMOREDCAR(1,4,(1,5),1)]\n";
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
"LIBERATIONARMY[LF=112,EXP=118]-ARVN[LF=31,EXP=500]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=112,EXP=118]-ARVN[LF=31,EXP=500]";
    remove(cfg.c_str());
    return printResult(result, expect, name);
}

