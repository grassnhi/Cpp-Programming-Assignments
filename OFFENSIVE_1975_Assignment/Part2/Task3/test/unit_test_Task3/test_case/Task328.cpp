#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task328() {
    string name = "Task328";
    stringstream output;

    // Test: BattleField với nhiều SpecialZone chồng lấn.
    // Nếu các đơn vị nằm trong bán kính của SpecialZone thì attackScore đặt về 0.
    vector<Position*> emptyForest, emptyRiver, emptyFortification, emptyUrban;
    vector<Position*> arraySpecialZone;
    // Đặt SpecialZone ở 2 vị trí chồng lấn về hiệu ứng trên một khu vực:
    arraySpecialZone.push_back(new Position(1, 1));
    arraySpecialZone.push_back(new Position(1, 2));

    int n_rows = 3, n_cols = 3;
    BattleField* bf = new BattleField(n_rows, n_cols, emptyForest, emptyRiver, emptyFortification, emptyUrban, arraySpecialZone);

    // Tạo Army với 2 Infantry, một nằm trong khu vực của SpecialZone và một nằm ngoài.
    Infantry* inf_close = new Infantry(100, 5, Position(1, 1), SNIPER); // Nằm chính trong SpecialZone
    Infantry* inf_far   = new Infantry(100, 5, Position(0, 0), SNIPER);  // Cách xa, không bị ảnh hưởng nếu > 1 đơn vị
    Unit* units[2] = { inf_close, inf_far };
    Army* army = new ARVN(units, 2, "ARVN_228", nullptr);

    // Áp dụng hiệu ứng của toàn bộ BattleField
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(army);
        }
    }

    output << army->str() << "\n";

    string result = output.str();
    // Với các SpecialZone, đơn vị gần (nằm trong bán kính 1) sẽ bị đặt Attack = 0.
    string expect = "ARVN[LF=0,EXP=500,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=240,weight=5,position=(1,1)]],battleField=]\n";

    delete inf_close;
    delete inf_far;
    delete army;
    delete bf;
    for(auto p : arraySpecialZone) delete p;
    
    return printResult(result, expect, name);
}