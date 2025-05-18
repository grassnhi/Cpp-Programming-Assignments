#include "../unit_test_Task4.hpp"

// File: test_HCMCampaign.cpp
// Testcases for class HCMCampaign: Task4xx from Task401 to Task415

// Each test writes a configuration file, runs the campaign, then checks the results

bool UNIT_TEST_Task4::Task401() {
    string name = "Task401";
    string cfg = "test/unit_test_Task4/test_case/input/config401.txt";
    ofstream ofs(cfg);
    // Scenario: no units on either side, eventCode=0 (Liberation attacks)
    ofs << "NUM_COLS=5\n";
    ofs << "NUM_ROWS=5\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=0\n";
    ofs << "UNIT_LIST=[]\n";
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
    // Expect both armies LF=0,EXP=0
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=0,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=0]-ARVN[LF=0,EXP=0]";

    remove(cfg.c_str());
    return printResult(result, expect, name);
}