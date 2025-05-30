#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task408() {
    string name = "Task408";

    
    
    string cfg = "test/unit_test_Task4/test_case/input/config408.txt";
    ofstream ofs(cfg);
    // Urban areas boost infantry, penalize artillery
    ofs << "NUM_COLS=5\n";
    ofs << "NUM_ROWS=5\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[(2,2),(4,4)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=10\n";
    ofs << "UNIT_LIST=[ARTILLERY(2,5,(2,2),1),REGULARINFANTRY(3,3,(3,3),0)]\n";
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
"LIBERATIONARMY[LF=0,EXP=289]-ARVN[LF=51,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=289]-ARVN[LF=51,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

