#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task422() {
    string name = "Task422";
    
    string cfg = "test/unit_test_Task4/test_case/input/config422.txt";
    ofstream ofs(cfg);
    // Edge case: missing EVENT_CODE line -> default to 0 (Liberation attacks)
    ofs << "NUM_COLS=8\n";
    ofs << "NUM_ROWS=10\n";
    ofs << "ARRAY_FOREST=[(1,2),(3,5)]\n";
    ofs << "ARRAY_RIVER=[(0,0),(0,4)]\n";
    ofs << "ARRAY_FORTIFICATION=[(6,6)]\n";
    ofs << "ARRAY_URBAN=[(2,0)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(9,7)]\n";
    ofs << "EVENT_CODE=23\n";
    ofs << "UNIT_LIST=[TANK(5,2,(1,2),0),REGULARINFANTRY(5,2,(1,1),0),TANK(5,2,(3,2),1),REGULARINFANTRY(5,2,(3,3),1)]\n";
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
    } catch(exception &e) {
        result = e.what();
    }
    string expect = "** Before the fight\n"
                    "LIBERATIONARMY[LF=62,EXP=290]-ARVN[LF=62,EXP=290]\n"
                    "** After the fight\n"
                    "LIBERATIONARMY[LF=62,EXP=290]-ARVN[LF=0,EXP=0]";
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}
