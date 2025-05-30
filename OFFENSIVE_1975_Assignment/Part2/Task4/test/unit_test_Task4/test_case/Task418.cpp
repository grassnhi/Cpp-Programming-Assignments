#include "../unit_test_Task4.hpp"
bool UNIT_TEST_Task4::Task418() {
    string name = "Task418";
    
    string cfg = "test/unit_test_Task4/test_case/input/config418.txt";
    ofstream ofs(cfg);
    // Engineer in special zone heals neighboring infantry
    ofs << "NUM_COLS=6\n";
    ofs << "NUM_ROWS=6\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(3,3),(3,4),(4,3),(4,4)]\n";
    ofs << "EVENT_CODE=5\n";
    ofs << "UNIT_LIST=[ENGINEER(2,3,(3,3),0),REGULARINFANTRY(3,2,(3,4),0),TANK(1,5,(6,6),1)]\n";
    ofs.close();
    HCMCampaign* campaign = new HCMCampaign(cfg);
    string result = "** Before the fight\n";
    result += campaign->printResult();
    result += "\n** After the fight\n";
    campaign->run();
    result += campaign->printResult();
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=0,EXP=460]-ARVN[LF=61,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=460]-ARVN[LF=61,EXP=0]";
    delete campaign;
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}