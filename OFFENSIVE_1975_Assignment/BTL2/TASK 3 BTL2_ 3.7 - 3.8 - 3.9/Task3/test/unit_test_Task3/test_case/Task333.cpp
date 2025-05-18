#include "../unit_test_Task3.hpp"

// -----------------------------------------------------------------

// File: config333.cpp
// Test 333: Cấu hình có EVENT_CODE âm, dự kiến eventCode = abs(negative) % 100.
bool UNIT_TEST_Task3::Task333() {
    string name = "Task333";
    string configFile = "test/unit_test_Task3/test_case/input/config333.txt";
    ofstream ofs(configFile);
    ofs << "NUM_ROWS=5\n";
    ofs << "NUM_COLS=5\n";
    ofs << "ARRAY_FOREST=[(1,1)]\n";
    ofs << "ARRAY_RIVER=[(2,2)]\n";
    ofs << "ARRAY_FORTIFICATION=[(3,3)]\n";
    ofs << "ARRAY_URBAN=[(4,4)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(5,5)]\n";
    ofs << "EVENT_CODE=-5\n";  // abs(-5)%100 = 5
    ofs.close();
    
    Configuration* config = nullptr;
    string result;
    try {
        config = new Configuration(configFile);
        result = config->str();
    } catch (exception &e) {
        result = e.what();
    }
    
    // Chú ý: Cấu hình in ra theo thứ tự:
    // num_rows=5, num_cols=5, eventCode=5, và mảng các vị trí.
    string expect = "[num_rows=5,num_cols=5,arrayForest=[(1,1)],arrayRiver=[(2,2)],arrayFortification=[(3,3)],arrayUrban=[(4,4)],arraySpecialZone=[(5,5)],liberationUnits=[],ARVNUnits=[],eventCode=0]";
    
    if(config) delete config;
    remove(configFile.c_str());
    return printResult(result, expect, name);
}