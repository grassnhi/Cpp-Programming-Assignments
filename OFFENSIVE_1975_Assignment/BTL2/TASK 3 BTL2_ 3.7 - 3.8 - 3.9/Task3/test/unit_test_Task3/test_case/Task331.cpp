#include "../unit_test_Task3.hpp"// File: config331.cpp
// Test 331: Cấu hình hợp lệ đầy đủ, các dòng ở thứ tự hỗn hợp.
// Nội dung file:
//   NUM_COLS=10
//   NUM_ROWS=8
//   ARRAY_FOREST=[(1,2),(2,3)]
//   ARRAY_RIVER=[(3,4)]
//   ARRAY_FORTIFICATION=[(4,5)]
//   ARRAY_URBAN=[(5,6)]
//   ARRAY_SPECIAL_ZONE=[(6,7)]
//   EVENT_CODE=123
//   UNIT_LIST=[TANK(5,2,(1,2),0),REGULARINFANTRY(5,2,(3,3),1)]
bool UNIT_TEST_Task3::Task331() {
    string name = "Task331";
    string configFile = "test/unit_test_Task3/test_case/input/config331.txt";
    // Tạo file cấu hình với nội dung đã nêu
    ofstream ofs(configFile);
    ofs << "NUM_COLS=10\n";
    ofs << "NUM_ROWS=8\n";
    ofs << "ARRAY_FOREST=[(1,2),(2,3)]\n";
    ofs << "ARRAY_RIVER=[(3,4)]\n";
    ofs << "ARRAY_FORTIFICATION=[(4,5)]\n";
    ofs << "ARRAY_URBAN=[(5,6)]\n";
    ofs << "ARRAY_SPECIAL_ZONE=[(6,7)]\n";
    ofs << "EVENT_CODE=123\n";
    ofs << "UNIT_LIST=[TANK(5,2,(1,2),0),REGULARINFANTRY(5,2,(3,3),1)]\n";
    ofs.close();

    // Khởi tạo đối tượng Configuration từ file vừa tạo
    Configuration* config = nullptr;
    string result;
    try {
        config = new Configuration(configFile);
        result = config->str();
    } catch (exception &e) {
        result = e.what();
    }
    // Dự kiến eventCode = abs(123)%100 = 23.
    string expect = "[num_rows=8,num_cols=10,arrayForest=[(1,2),(2,3)],arrayRiver=[(3,4)],arrayFortification=[(4,5)],arrayUrban=[(5,6)],arraySpecialZone=[(6,7)],liberationUnits=[Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(1,2)]],ARVNUnits=[Infantry[infantryType=REGULARINFANTRY,quantity=5,weight=2,position=(3,3)]],eventCode=23]";

    // Cleanup
    if(config) delete config;
    remove(configFile.c_str());

    return printResult(result, expect, name);
}