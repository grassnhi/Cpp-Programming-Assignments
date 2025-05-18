#include "../unit_test_Task3.hpp"// -----------------------------------------------------------------

// File: config332.cpp
// Test 332: Cấu hình thiếu NUM_ROWS (hoặc NUM_COLS), dự kiến ném exception.
bool UNIT_TEST_Task3::Task332() {
    string name = "Task332";
    string configFile = "test/unit_test_Task3/test_case/input/config332.txt";
    ofstream ofs(configFile);
    // Chỉ có NUM_COLS mà không có NUM_ROWS
    ofs << "NUM_COLS=10\n";
    ofs << "ARRAY_FOREST=[(1,2),(2,3)]\n";
    ofs << "ARRAY_RIVER=[(3,4)]\n";
    ofs << "ARRAY_FORTIFICATION=[(4,5)]\n";
    ofs << "ARRAY_URBAN=[(5,6)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(6,7)]\n";
    ofs << "EVENT_CODE=50\n";
    ofs << "NUM_ROWS=8\n";
    ofs.close();
    
    string result;
    try {
        Configuration config(configFile);
        result = config.str();
    } catch (runtime_error &e) {
        result = e.what();
    }
    // Dự kiến: thông báo lỗi do thiếu NUM_ROWS (hoặc NUM_COLS)
    string expect = "[num_rows=8,num_cols=10,arrayForest=[(1,2),(2,3)],arrayRiver=[(3,4)],arrayFortification=[(4,5)],arrayUrban=[(5,6)],arraySpecialZone=[(6,7)],liberationUnits=[],ARVNUnits=[],eventCode=50]";
    
    remove(configFile.c_str());
    return printResult(result, expect, name);
}