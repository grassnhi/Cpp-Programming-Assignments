#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task416() {
    string name = "Task416";
    string cfg = "test/unit_test_Task4/test_case/input/config416.txt";
    ofstream ofs(cfg);
    // Large grid stress test: 20x20, random terrain clusters
    ofs << "NUM_COLS=20\n";
    ofs << "NUM_ROWS=20\n";
    ofs << "ARRAY_FOREST=[(5,5),(5,6),(6,5),(6,6),(15,15),(15,16),(16,15)]\n";
    ofs << "ARRAY_RIVER=[(1,10),(2,10),(3,10),(4,10),(10,1),(10,2)]\n";
    ofs << "ARRAY_FORTIFICATION=[(10,10),(11,10),(10,11)]\n";
    ofs << "ARRAY_URBAN=[(7,7),(7,8),(8,7),(8,8)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(20,20)]\n";
    ofs << "EVENT_CODE=65\n";
    ofs << "UNIT_LIST=[";
    // many units
    for(int i=0;i<10;i++) {
        ofs << "REGULARINFANTRY(3,2,("<<i+1<<","<<i+2<<"),0),";
    }
    for(int i=0;i<10;i++) {
        ofs << "TANK(2,5,("<<19-i<<","<<i%7+1<<"),0),";
    }
    for(int i=0;i<10;i++) {
        ofs << "TANK(2,5,("<<i+1<<","<<i+1<<"),1)";
        if(i<9) ofs<<",";
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
    } catch(exception &e) {
        result = e.what();
    }
    string expect = "** Before the fight\n"
"LIBERATIONARMY[LF=620,EXP=500]-ARVN[LF=620,EXP=0]\n"
"** After the fight\n"
"LIBERATIONARMY[LF=65,EXP=0]-ARVN[LF=0,EXP=0]";
    remove(cfg.c_str());
    return printResult(result, expect, name);
}

