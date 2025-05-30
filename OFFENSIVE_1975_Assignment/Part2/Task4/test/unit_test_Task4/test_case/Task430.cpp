#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task430() {
    string name = "Task430";
    
    string cfg = "test/unit_test_Task4/test_case/input/config421.txt";
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

    string result;
    Configuration* config = nullptr;
    try {
        config = new Configuration(cfg);
        result = config->str();
    } catch(exception &e) {
        result = e.what();
    }
    string expect = "[num_rows=10,num_cols=8,arrayForest=[(1,2),(3,5)],arrayRiver=[(0,0),(0,4)],arrayFortification=[(6,6)],arrayUrban=[(2,0)],arraySpecialZone=[(9,7)],liberationUnits=[Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(1,2)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=2,position=(1,1)]],ARVNUnits=[Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(3,2)],Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=2,position=(3,3)]],eventCode=23]";
    if(config) delete config;
    remove(cfg.c_str());
    
    return printResult(result, expect, name);
}

