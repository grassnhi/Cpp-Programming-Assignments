#include "../unit_test_Task3.hpp"

// -----------------------------------------------------------------

bool UNIT_TEST_Task3::Task335() {
    string name = "Task335";
    string configFile = "test/unit_test_Task3/test_case/input/config335.txt";
    ofstream ofs(configFile);
    ofs << "   ARRAY_URBAN=[ (3,3) , (4,4) ]   \n";
    ofs << "\n";
    ofs << "EVENT_CODE=  99  \n";
    ofs << "NUM_ROWS=  12\n";
    ofs << "NUM_COLS=12  \n";
    ofs << "ARRAY_SPECIAL_ZONE=[(5,5)]\n";
    ofs << "ARRAY_FORTIFICATION=[(6,6)]\n";
    ofs << "ARRAY_RIVER=[(7,7)]\n";
    ofs << "ARRAY_FOREST=[(1,1),(2,2)]\n";
    ofs.close();
    
    Configuration* config = nullptr;
    string result;
    try {
        config = new Configuration(configFile);
        result = config->str();
    } catch (exception &e) {
        result = e.what();
    }
    // Dự kiến kết quả in theo thứ tự cố định (theo định nghĩa trong Configuration::str):
    // num_rows, num_cols, eventCode, ARRAY_FOREST, ARRAY_RIVER, ARRAY_FORTIFICATION, ARRAY_URBAN, ARRAY_SPECIAL_ZONE.
    string expect = "[num_rows=12,num_cols=12,arrayForest=[(1,1),(2,2)],arrayRiver=[(7,7)],arrayFortification=[(6,6)],arrayUrban=[(3,3),(4,4)],arraySpecialZone=[(5,5)],liberationUnits=[],ARVNUnits=[],eventCode=99]";
    
    if(config) delete config;
    remove(configFile.c_str());
    return printResult(result, expect, name);
}
