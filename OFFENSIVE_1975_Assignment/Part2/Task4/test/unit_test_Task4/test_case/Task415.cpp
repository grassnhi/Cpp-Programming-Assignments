#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task415() {
    string name = "Task415";
    
    
    string cfg = "test/unit_test_Task4/test_case/input/config415.txt";
    ofstream ofs(cfg);
    // Full scenario: varied terrain, many units, multi-round
    ofs << "NUM_COLS=10\n";
    ofs << "NUM_ROWS=10\n";
    ofs << "ARRAY_FOREST=[(4,4),(6,6)]\n";
    ofs << "ARRAY_RIVER=[(1,10),(10,1)]\n";
    ofs << "ARRAY_FORTIFICATION=[(5,5)]\n";
    ofs << "ARRAY_URBAN=[(3,7),(7,3)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(8,8),(2,2)]\n";
    ofs << "EVENT_CODE=76\n";
    ofs << "UNIT_LIST=[TANK(3,4,(4,3),1),ARTILLERY(2,3,(5,6),1),";
    ofs << "REGULARINFANTRY(4,2,(6,6),0),SPECIALFORCES(1,6,(2,2),0),";
    ofs << "MORTARSQUAD(3,3,(7,7),1),ENGINEER(2,2,(3,7),0)]\n";
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
"LIBERATIONARMY[LF=0,EXP=500]-ARVN[LF=113,EXP=124]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=500]-ARVN[LF=113,EXP=124]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}