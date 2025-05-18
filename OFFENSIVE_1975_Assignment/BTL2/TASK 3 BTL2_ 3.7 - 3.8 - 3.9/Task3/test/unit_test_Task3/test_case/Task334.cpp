#include "../unit_test_Task3.hpp"

// -----------------------------------------------------------------
bool UNIT_TEST_Task3::Task334() {
    string name = "Task334";
    string configFile = "test/unit_test_Task3/test_case/input/config334.txt";
    ofstream ofs(configFile);
    ofs << "NUM_ROWS=7\n";
    ofs << "NUM_COLS=7\n";
    ofs << "ARRAY_FOREST=[]\n";
    ofs << "ARRAY_RIVER=[]\n";
    ofs << "ARRAY_FORTIFICATION=[]\n";
    ofs << "ARRAY_URBAN=[]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[]\n";
    ofs << "EVENT_CODE=77\n";
    ofs.close();
    
    Configuration* config = nullptr;
    string result;
    try {
        config = new Configuration(configFile);
        result = config->str();
    } catch (exception &e) {
        result = e.what();
    }
    
    string expect = "[num_rows=7,num_cols=7,arrayForest=[],arrayRiver=[],arrayFortification=[],arrayUrban=[],arraySpecialZone=[],liberationUnits=[],ARVNUnits=[],eventCode=77]";
    
    if(config) delete config;
    remove(configFile.c_str());
    return printResult(result, expect, name);
}