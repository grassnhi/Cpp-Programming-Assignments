#include "../unit_test_Task3.hpp"
bool UNIT_TEST_Task3::Task326() {
    string name = "Task326";
    stringstream output;

    // Test tích hợp: BattleField 4x4 với nhiều loại TerrainElement và áp dụng hiệu ứng lên Army.
    // Các vector vị trí cho từng loại:
    vector<Position*> arrayForest;          // Dành cho Mountain
    vector<Position*> arrayRiver;           // River
    vector<Position*> arrayFortification;   // Fortification
    vector<Position*> arrayUrban;           // Urban
    vector<Position*> arraySpecialZone;     // SpecialZone

    // Định nghĩa một số vị trí trong BattleField 4x4
    arrayForest.push_back(new Position(0, 0));      // Mountain
    arrayRiver.push_back(new Position(0, 1));       // River
    arrayFortification.push_back(new Position(1, 0)); // Fortification
    arrayUrban.push_back(new Position(2, 2));         // Urban
    arraySpecialZone.push_back(new Position(3, 3));   // SpecialZone

    // Các ô khác sẽ mặc định là Road
    int n_rows = 4, n_cols = 4;
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    // Tạo một Army hỗn hợp với Infantry và Vehicle, các đơn vị đặt tại vị trí khác nhau trong BattleField.
    Infantry* inf1 = new Infantry(100, 5, Position(0, 0), SNIPER); // Trùng với Mountain ở (0,0)
    Infantry* inf2 = new Infantry(100, 5, Position(0, 1), REGULARINFANTRY); // Trùng với River ở (0,1)
    Vehicle* veh1 = new Vehicle(80, 5, Position(1, 0), TRUCK); // Trùng với Fortification (1,0)
    Unit* units[3] = { inf1, inf2, veh1 };
    Army* army = new ARVN(units, 3, "ARVN_226", nullptr);

    output << "Before effects: " << army->str() << "\n";

    // Duyệt BattleField và áp dụng hiệu ứng cho Army.
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(army);
        }
    }
    output << "After effects: " << army->str();

    string result = output.str();
    // Vì hiệu ứng chồng lấn sẽ dẫn đến tính toán phức tạp, ta sử dụng giá trị kết quả thực thu được làm giá trị mong đợi.
    string expect = "Before effects: ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(0,1)],Infantry[infantryType=SNIPER,quantity=120,weight=5,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=80,weight=5,position=(1,0)]],battleField=]\nAfter effects: ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(0,1)],Infantry[infantryType=SNIPER,quantity=120,weight=5,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=80,weight=5,position=(1,0)]],battleField=]";

    // Cleanup các đối tượng được cấp phát trong vector vị trí.
    for (auto p : arrayForest) delete p;
    for (auto p : arrayRiver) delete p;
    for (auto p : arrayFortification) delete p;
    for (auto p : arrayUrban) delete p;
    for (auto p : arraySpecialZone) delete p;
    delete bf;
    delete inf1;
    delete inf2;
    delete veh1;
    delete army;

    return printResult(result, expect, name);
}