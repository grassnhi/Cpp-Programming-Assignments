#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task4101()
{
    // Test Position với số dương
    string name = "Task101";
    //! data ------------------------------------
    int row = 15;
    int col = 8;
    string pos_str = "(15,8)";
    
    //! process ---------------------------------
    Position pos1(row, col);
    Position pos2(pos_str);
    string result = pos1.str() + "\n" + pos2.str();
    
    //! expect ----------------------------------
    string expect = "(15,8)\n(15,8)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    // Không có cấp phát động cần giải phóng.
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4102()
{
    // Test Position với số âm
    string name = "Task102";
    //! data ------------------------------------
    int row = 5;
    int col = 10;
    string pos_str = "(5,10)";
    
    //! process ---------------------------------
    Position pos1(row, col);
    Position pos2(pos_str);
    string result = pos1.str() + "\n" + pos2.str();
    
    //! expect ----------------------------------
    string expect = "(5,10)\n(5,10)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4103()
{
    // Test Vehicle: tính điểm tấn công với TRUCK
    string name = "Task103";
    //! data ------------------------------------
    int quantity = 3;
    int weight = 10;
    Position pos(1, 2);
    VehicleType vt = TRUCK; // TRUCK có giá trị 0
    //! process ---------------------------------
    Vehicle vehicle(quantity, weight, pos, vt);
    int score = vehicle.getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 1; // 0 + 30 = 30/30 = 1
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4104()
{
    // Test Vehicle: định dạng chuỗi xuất
    string name = "Task104";
    //! data ------------------------------------
    int quantity = 4;
    int weight = 12;
    Position pos(3, 4);
    VehicleType vt = ARTILLERY; // ARTILLERY có giá trị 5
    //! process ---------------------------------
    Vehicle vehicle(quantity, weight, pos, vt);
    string result = vehicle.str();
    
    //! expect ----------------------------------
    string expect = "Vehicle[vehicleType=ARTILLERY,quantity=4,weight=12,position=(3,4)]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4105()
{
    string name = "Task105";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 25; 
    Position pos(5, 5);
    InfantryType it = SPECIALFORCES; 
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 474;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4106()
{
    // Test Infantry SPECIALFORCES với weight không phải số chính phương -> tăng số lượng
    string name = "Task106";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 15; // không phải số chính phương
    Position pos(6, 6);
    InfantryType it = SPECIALFORCES; // giá trị 4
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 4*56 + 10*15 = 224 + 150 = 374, không cộng bonus
    // computeSingleDigit(374,1975) cho ra 9 (>7) -> tăng 20%: thêm (10*20+99)/100 = 2, new quantity = 12.
    // Final score = 4*56 + 12*15 = 224 + 180 = 404.
    int expectedScore = 404;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4107()
{
    // Test Infantry REGULARINFANTRY với giảm số lượng khi "số cá nhân" < 3
    string name = "Task107";
    //! data ------------------------------------
    int quantity = 50;
    int weight = 10;
    Position pos(7, 7);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 5*56 + 50*10 = 280 + 500 = 780.
    // computeSingleDigit(780,1975) cho ra digit < 3 -> giảm 10%: giảm 5 đơn vị, new quantity = 45.
    // Final score = 5*56 + 45*10 = 280 + 450 = 730.
    int expectedScore = 730;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4108()
{
    // Test Infantry ENGINEER không thay đổi số lượng
    string name = "Task108";
    //! data ------------------------------------
    int quantity = 20;
    int weight = 12;
    Position pos(8, 8);
    InfantryType it = ENGINEER; // giá trị 3
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 3*56 + 20*12 = 168 + 240 = 408, computeSingleDigit cho ra 7 -> không thay đổi.
    int expectedScore = 408;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4109()
{
    // Test Infantry SNIPER với tăng số lượng khi "số cá nhân" > 7
    string name = "Task109";
    //! data ------------------------------------
    int quantity = 1;
    int weight = 58;
    Position pos(9, 9);
    InfantryType it = SNIPER; // giá trị 0
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 0*56 + 1*58 = 58.
    // computeSingleDigit(58,1975) cho ra 8 -> tăng 20%: thêm 1, new quantity = 2.
    // Final score = 0*56 + 2*58 = 116.
    int expectedScore = 116;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4110()
{
    // Test Infantry MORTARSQUAD không điều chỉnh số lượng
    string name = "Task110";
    //! data ------------------------------------
    int quantity = 5;
    int weight = 8;
    Position pos(10, 10);
    InfantryType it = MORTARSQUAD; // giá trị 2
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 2*56 + 5*8 = 112 + 40 = 152, computeSingleDigit cho ra 3 -> không thay đổi.
    int expectedScore = 152;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4111()
{
    // Test Infantry REGULARINFANTRY với trường hợp không thay đổi số lượng (digit nằm giữa)
    string name = "Task111";
    //! data ------------------------------------
    int quantity = 10;
    int weight = 10;
    Position pos(11, 11);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 5*56 + 10*10 = 280 + 100 = 380, computeSingleDigit cho ra 6 (không thay đổi).
    int expectedScore = 380;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4112()
{
    // Test Position với số lớn
    string name = "Task112";
    //! data ------------------------------------
    int row = 1000;
    int col = 2000;
    string pos_str = "(1000,2000)";
    
    //! process ---------------------------------
    Position pos(row, col);
    string result = pos.str();
    
    //! expect ----------------------------------
    string expect = "(1000,2000)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4113()
{
    // Test Position với row = 0 và col âm
    string name = "Task113";
    //! data ------------------------------------
    int row = 0;
    int col = -7;
    string pos_str = "(0,-7)";
    
    //! process ---------------------------------
    Position pos(row, col);
    string result = pos.str();
    
    //! expect ----------------------------------
    string expect = "(0,-7)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4114()
{
    // Test đa hình: Unit* trỏ đến Vehicle
    string name = "Task114";
    //! data ------------------------------------
    Unit* unit = new Vehicle(7, 9, Position(12,12), ARMOREDCAR); // ARMOREDCAR có giá trị 3
    //! process ---------------------------------
    int score = unit->getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 33; // 912 + 63 = 975 / 30 = 32.5 => 33
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    delete unit;
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4115()
{
    // Test đa hình: Unit* trỏ đến Infantry
    string name = "Task115";
    //! data ------------------------------------
    Unit* unit = new Infantry(6, 7, Position(13,13), ANTIAIRCRAFTSQUAD); // ANTIAIRCRAFTSQUAD có giá trị 1
    //! process ---------------------------------
    int score = unit->getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 1 * 56 + 6 * 7; // 56 + 42 = 98
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    delete unit;
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4116()
{
    // Test nhiều đơn vị trong mảng và tính tổng điểm tấn công
    string name = "Task116";
    //! data ------------------------------------
    Unit* units[2];
    units[0] = new Vehicle(2, 10, Position(14,14), APC); // APC có giá trị 4 → score = 4*304 + 2*10 = 1216 + 20 = 1236
    units[1] = new Infantry(4, 8, Position(14,15), ENGINEER); // ENGINEER có giá trị 3 → score = 3*56 + 4*8 = 168 + 32 = 200
    //! process ---------------------------------
    int totalScore = 0;
    for (int i = 0; i < 2; i++) {
        totalScore += units[i]->getAttackScore();
    }
    
    //! expect ----------------------------------
    int expectedTotal = 42 + 200; // 1436
    stringstream expectStream;
    expectStream << expectedTotal;
    
    //! output ----------------------------------
    stringstream output;
    output << totalScore;
    
    //! remove data -----------------------------
    for (int i = 0; i < 2; i++) {
        delete units[i];
    }
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4117()
{
    // Test Infantry REGULARINFANTRY: số lượng không giảm dưới 1 khi giảm 10%
    string name = "Task117";
    //! data ------------------------------------
    int quantity = 1;
    int weight = 5;
    Position pos(15,15);
    InfantryType it = REGULARINFANTRY; // giá trị 5
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    int expectedScore = 5*56 + 1*5; // 280 + 5 = 285
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
bool UNIT_TEST_Task4::Task4118()
{
    // Test scenario: chuỗi xuất của Vehicle và Infantry
    string name = "Task118";
    //! data ------------------------------------
    Vehicle vehicle(3, 15, Position(16,16), MORTAR); // MORTAR có giá trị 1
    Infantry infantry(7, 10, Position(16,17), ANTIAIRCRAFTSQUAD); // ANTIAIRCRAFTSQUAD có giá trị 1
    //! process ---------------------------------
    string result = vehicle.str() + "\n" + infantry.str();
    
    //! expect ----------------------------------
    string expect = "Vehicle[vehicleType=MORTAR,quantity=3,weight=15,position=(16,16)]\n"
                    "Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=7,weight=10,position=(16,17)]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4119()
{
    // Test các hàm set và get của Position
    string name = "Task119";
    //! data ------------------------------------
    Position pos;
    pos.setRow(25);
    pos.setCol(30);
    
    //! process ---------------------------------
    int row = pos.getRow();
    int col = pos.getCol();
    string result = "(" + to_string(row) + "," + to_string(col) + ")";
    
    //! expect ----------------------------------
    string expect = "(25,30)";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Task4::Task4120()
{
    // Test Infantry MORTARSQUAD không điều chỉnh số lượng
    string name = "Task120";
    //! data ------------------------------------
    int quantity = 5;
    int weight = 8;
    Position pos(10, 10);
    InfantryType it = MORTARSQUAD; // giá trị 2
    //! process ---------------------------------
    Infantry infantry(quantity, weight, pos, it);
    int score = infantry.getAttackScore();
    
    //! expect ----------------------------------
    // Base: 2*56 + 5*8 = 112 + 40 = 152, computeSingleDigit cho ra 3 -> không thay đổi.
    int expectedScore = 152;
    stringstream expectStream;
    expectStream << expectedScore;
    
    //! output ----------------------------------
    stringstream output;
    output << score;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------
    return printResult(output.str(), expectStream.str(), name);
}
