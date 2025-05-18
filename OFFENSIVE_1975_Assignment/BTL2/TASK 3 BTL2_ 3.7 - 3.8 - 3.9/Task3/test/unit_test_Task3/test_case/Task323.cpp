#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task323() {
    string name = "Task323";
    stringstream output;

    // Tạo các đối tượng TerrainElement và gọi getEffect với nullptr
    Road road(Position(0,0));
    Mountain mountain(Position(1,1));
    River river(Position(2,2));
    Urban urban(Position(3,3));
    Fortification fort(Position(4,4));
    SpecialZone sz(Position(5,5));
    
    // Gọi hàm getEffect với Army=nullptr (sẽ không gây crash)
    road.getEffect(nullptr);
    mountain.getEffect(nullptr);
    river.getEffect(nullptr);
    urban.getEffect(nullptr);
    fort.getEffect(nullptr);
    sz.getEffect(nullptr);
    
    output << "Null Army test passed";
    
    string result = output.str();
    string expect = "Null Army test passed";
    
    return printResult(result, expect, name);
}