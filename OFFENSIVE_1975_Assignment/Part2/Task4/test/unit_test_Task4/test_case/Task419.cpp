#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task419() {
    string name = "Task419";
    string cfg = "test/unit_test_Task4/test_case/input/config419.txt";
    ofstream ofs(cfg);
    // Full chaos: mixed terrain, max capacity, random units
    ofs << "NUM_COLS=15\n";
    ofs << "NUM_ROWS=15\n";
    ofs << "ARRAY_FOREST=[(2,2),(2,14),(14,2),(14,14)]\n";
    ofs << "ARRAY_RIVER=[(8,1),(8,2),(8,3),(8,4)]\n";
    ofs << "ARRAY_FORTIFICATION=[(1,8),(2,8)]\n";
    ofs << "ARRAY_URBAN=[(7,7),(7,8),(8,7),(8,8)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(5,5),(10,10)]\n";
    ofs << "EVENT_CODE=89\n";
    ofs << "UNIT_LIST=[";
    // Random mix of 20 units
    vector<string> units = {"TANK(1,4,(3,3),1)","ARTILLERY(2,3,(4,4),1)","REGULARINFANTRY(3,2,(5,5),0)","SNIPER(1,3,(6,6),0)","MORTARSQUAD(2,3,(7,7),1)","ARMOREDCAR(1,5,(8,8),1)","SPECIALFORCES(1,9,(10,10),0)","ENGINEER(2,2,(11,11),0)"};
    for(int i=0;i<20;i++) {
        ofs << units[i % units.size()];
        if(i<19) ofs<<",";
    }
    ofs << "]\n";
    ofs.close();

    HCMCampaign* campaign = new HCMCampaign(cfg);
    string result = "** Before the fight\n";
    result += campaign->printResult();
    result += "\n** After the fight\n";
    campaign->run();
    result += campaign->printResult();
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=0,EXP=500]-ARVN[LF=398,EXP=236]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=0,EXP=500]-ARVN[LF=145,EXP=124]";
    delete campaign;
    remove(cfg.c_str());
    return printResult(result, expect, name);
}
