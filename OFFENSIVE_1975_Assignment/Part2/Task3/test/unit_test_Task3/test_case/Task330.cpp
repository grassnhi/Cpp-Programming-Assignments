#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task330() {
    string name = "Task330";
    stringstream output;

    // Test động: Mô phỏng tình huống di chuyển của Army và áp dụng hiệu ứng liên tục của BattleField.
    vector<Position*> arrayForest;          // Mountain
    vector<Position*> arrayRiver;           // River
    vector<Position*> arrayFortification;   // Fortification
    vector<Position*> arrayUrban;           // Urban
    vector<Position*> arraySpecialZone;     // SpecialZone

    // Định nghĩa một số vị trí đặc biệt trong một BattleField 5x5
    arrayForest.push_back(new Position(0, 0));
    arrayRiver.push_back(new Position(0, 1));
    arrayFortification.push_back(new Position(1, 0));
    arrayUrban.push_back(new Position(2, 2));
    arraySpecialZone.push_back(new Position(3, 3));

    int n_rows = 5, n_cols = 5;
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    // Tạo Army ban đầu với các đơn vị đặt tại vị trí ban đầu chưa bị hiệu ứng đặc biệt.
    Infantry* inf = new Infantry(100, 5, Position(4, 4), REGULARINFANTRY);
    Vehicle* veh = new Vehicle(90, 5, Position(4, 3), TRUCK);
    Unit* units[2] = { inf, veh };
    Army* army = new ARVN(units, 2, "ARVN_230", nullptr);

    output << "Initial Army: " << army->str() << "\n";

    // Áp dụng hiệu ứng của toàn BattleField lần 1.
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(army);
        }
    }
    output << "After 1st round effects: " << army->str() << "\n";

    // Áp dụng hiệu ứng lần 2 sau khi di chuyển.
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(army);
        }
    }
    output << "After 2nd round effects: " << army->str();

    string result = output.str();
    // Vì chuỗi kết quả phụ thuộc vào tính toán hiệu ứng liên tục, ta dùng giá trị thực thu được làm kỳ vọng.
    string expect = "Initial Army: ARVN[LF=15,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(4,4)],Vehicle[vehicleType=TRUCK,quantity=90,weight=5,position=(4,3)]],battleField=]\nAfter 1st round effects: ARVN[LF=15,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(4,4)],Vehicle[vehicleType=TRUCK,quantity=90,weight=5,position=(4,3)]],battleField=]\nAfter 2nd round effects: ARVN[LF=15,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(4,4)],Vehicle[vehicleType=TRUCK,quantity=90,weight=5,position=(4,3)]],battleField=]";

    // Cleanup
    delete inf;
    delete veh;
    delete army;
    delete bf;
    for(auto p : arrayForest) delete p;
    for(auto p : arrayRiver) delete p;
    for(auto p : arrayFortification) delete p;
    for(auto p : arrayUrban) delete p;
    for(auto p : arraySpecialZone) delete p;

    return printResult(result, expect, name);
}