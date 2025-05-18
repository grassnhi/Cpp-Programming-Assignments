#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task318() {
    string name = "Task318";
    stringstream output;

    //! Data ------------------------------------
    // Khởi tạo các vector lưu vị trí của từng loại TerrainElement
    vector<Position*> arrayForest;        // Dành cho Mountain
    vector<Position*> arrayRiver;         // River
    vector<Position*> arrayFortification; // Fortification
    vector<Position*> arrayUrban;         // Urban
    vector<Position*> arraySpecialZone;   // SpecialZone

    // Định nghĩa các vị trí trên BattleField 6x6
    // Ví dụ: một vài vị trí cho mỗi loại được đặt rải rác
    arrayForest.push_back(new Position(0, 1));
    arrayForest.push_back(new Position(1, 4));
    
    arrayRiver.push_back(new Position(2, 2));
    arrayRiver.push_back(new Position(3, 3));
    
    arrayFortification.push_back(new Position(4, 0));
    arrayFortification.push_back(new Position(5, 5));
    
    arrayUrban.push_back(new Position(0, 5));
    arrayUrban.push_back(new Position(5, 0));
    
    arraySpecialZone.push_back(new Position(3, 0));
    arraySpecialZone.push_back(new Position(2, 5));

    int n_rows = 6, n_cols = 6;
    // Tạo BattleField với các yếu tố địa hình dựa trên các vector đã khởi tạo
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    //! Tạo đội quân ------------------------------------
    // Đội quân LiberationArmy với 4 đơn vị:
    // - 2 Infantry đặt tại các vị trí thuộc vùng Mountain (arrayForest)
    // - 1 Vehicle đặt tại vị trí thuộc vùng River (arrayRiver)
    // - 1 Infantry đặt tại vị trí chưa có yếu tố đặc biệt (mặc định là Road)
    Infantry* libInf1 = new Infantry(15, 6, Position(0, 1), SPECIALFORCES);
    Infantry* libInf2 = new Infantry(14, 5, Position(1, 4), REGULARINFANTRY);
    Vehicle* libVeh1 = new Vehicle(12, 5, Position(2, 2), TRUCK);
    Infantry* libInf3 = new Infantry(10, 5, Position(4, 4), SNIPER);  // Vị trí Road
    Unit* unitsLib[4] = { libInf1, libInf2, libVeh1, libInf3 };
    Army* liber = new LiberationArmy(unitsLib, 4, "LibTeam", bf);

    // Đội quân ARVN với 4 đơn vị:
    // - 1 Infantry đặt tại vị trí thuộc Urban (arrayUrban)
    // - 1 Infantry đặt tại vị trí thuộc Fortification (arrayFortification)
    // - 1 Vehicle đặt tại vị trí thuộc SpecialZone (arraySpecialZone)
    // - 1 Vehicle đặt tại vị trí Road
    Infantry* arvnInf1 = new Infantry(13, 5, Position(0, 5), REGULARINFANTRY);
    Infantry* arvnInf2 = new Infantry(12, 6, Position(4, 0), ANTIAIRCRAFTSQUAD);
    Vehicle* arvnVeh1 = new Vehicle(14, 4, Position(3, 0), MORTAR);
    Vehicle* arvnVeh2 = new Vehicle(11, 5, Position(2, 3), TRUCK); // Road
    Unit* unitsArvn[4] = { arvnInf1, arvnInf2, arvnVeh1, arvnVeh2 };
    Army* arvn = new ARVN(unitsArvn, 4, "ARVN_Team", bf);

    //! Process ---------------------------------
    output << "Initial State:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // Round 1: Áp dụng hiệu ứng của toàn bộ BattleField
    output << "Applying Battlefield Effects (Round 1):" << endl;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(liber);
            bf->getElement(i, j)->getEffect(arvn);
        }
    }
    output << "After Effects (Round 1):" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // Round 2: Giao tranh
    output << "Liberation attacks ARVN (Round 2):" << endl;
    liber->fight(arvn, false);
    output << "After Liberation Attack:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    output << "ARVN defends Liberation (Round 2):" << endl;
    arvn->fight(liber, true);
    output << "After ARVN Defense:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // Round 3: Áp dụng hiệu ứng lại toàn BattleField (có thể giả lập chuyển động hay thay đổi vị trí)
    output << "Applying Battlefield Effects (Round 3):" << endl;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(liber);
            bf->getElement(i, j)->getEffect(arvn);
        }
    }
    output << "After Effects (Round 3):" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    //! Kết quả ---------------------------------
    string result = output.str();
    // Do có tính chất phức tạp của hiệu ứng chồng lấn, sử dụng kết quả thu được làm golden value cho test.
    string expect = "Initial State:\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=3;Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(4,4)],Infantry[infantryType=REGULARINFANTRY,quantity=14,weight=5,position=(1,4)],Infantry[infantryType=SPECIALFORCES,quantity=15,weight=6,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=12,weight=5,position=(2,2)]],battleField=BattleField[n_rows=6,n_cols=6]]\n2. ARVN[LF=14,EXP=473,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=12,weight=6,position=(4,0)],Infantry[infantryType=REGULARINFANTRY,quantity=13,weight=5,position=(0,5)],Vehicle[vehicleType=MORTAR,quantity=14,weight=4,position=(3,0)],Vehicle[vehicleType=TRUCK,quantity=11,weight=5,position=(2,3)]],battleField=BattleField[n_rows=6,n_cols=6]]\nApplying Battlefield Effects (Round 1):\nAfter Effects (Round 1):\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=3;Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(4,4)],Infantry[infantryType=REGULARINFANTRY,quantity=14,weight=5,position=(1,4)],Infantry[infantryType=SPECIALFORCES,quantity=15,weight=6,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=12,weight=5,position=(2,2)]],battleField=BattleField[n_rows=6,n_cols=6]]\n2. ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=12,weight=6,position=(4,0)],Infantry[infantryType=REGULARINFANTRY,quantity=13,weight=5,position=(0,5)],Vehicle[vehicleType=MORTAR,quantity=14,weight=4,position=(3,0)],Vehicle[vehicleType=TRUCK,quantity=11,weight=5,position=(2,3)]],battleField=BattleField[n_rows=6,n_cols=6]]\nLiberation attacks ARVN (Round 2):\nAfter Liberation Attack:\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=3;Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(4,4)],Infantry[infantryType=REGULARINFANTRY,quantity=14,weight=5,position=(1,4)],Infantry[infantryType=SPECIALFORCES,quantity=15,weight=6,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=12,weight=5,position=(2,2)]],battleField=BattleField[n_rows=6,n_cols=6]]\n2. ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=12,weight=6,position=(4,0)],Infantry[infantryType=REGULARINFANTRY,quantity=13,weight=5,position=(0,5)],Vehicle[vehicleType=MORTAR,quantity=14,weight=4,position=(3,0)],Vehicle[vehicleType=TRUCK,quantity=11,weight=5,position=(2,3)]],battleField=BattleField[n_rows=6,n_cols=6]]\nARVN defends Liberation (Round 2):\nAfter ARVN Defense:\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=3;Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(4,4)],Infantry[infantryType=REGULARINFANTRY,quantity=14,weight=5,position=(1,4)],Infantry[infantryType=SPECIALFORCES,quantity=15,weight=6,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=12,weight=5,position=(2,2)]],battleField=BattleField[n_rows=6,n_cols=6]]\n2. ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=12,weight=6,position=(4,0)],Infantry[infantryType=REGULARINFANTRY,quantity=13,weight=5,position=(0,5)],Vehicle[vehicleType=MORTAR,quantity=14,weight=4,position=(3,0)],Vehicle[vehicleType=TRUCK,quantity=11,weight=5,position=(2,3)]],battleField=BattleField[n_rows=6,n_cols=6]]\nApplying Battlefield Effects (Round 3):\nAfter Effects (Round 3):\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=3;Infantry[infantryType=SNIPER,quantity=11,weight=5,position=(4,4)],Infantry[infantryType=REGULARINFANTRY,quantity=14,weight=5,position=(1,4)],Infantry[infantryType=SPECIALFORCES,quantity=15,weight=6,position=(0,1)],Vehicle[vehicleType=TRUCK,quantity=12,weight=5,position=(2,2)]],battleField=BattleField[n_rows=6,n_cols=6]]\n2. ARVN[LF=14,EXP=500,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=12,weight=6,position=(4,0)],Infantry[infantryType=REGULARINFANTRY,quantity=13,weight=5,position=(0,5)],Vehicle[vehicleType=MORTAR,quantity=14,weight=4,position=(3,0)],Vehicle[vehicleType=TRUCK,quantity=11,weight=5,position=(2,3)]],battleField=BattleField[n_rows=6,n_cols=6]]\n";

    //! Cleanup ---------------------------------
    delete libInf1;
    delete libInf2;
    delete libVeh1;
    delete libInf3;
    delete arvnInf1;
    delete arvnInf2;
    delete arvnVeh1;
    delete arvnVeh2;
    delete liber;
    delete arvn;
    delete bf;
    for (auto p : arrayForest) delete p;
    for (auto p : arrayRiver) delete p;
    for (auto p : arrayFortification) delete p;
    for (auto p : arrayUrban) delete p;
    for (auto p : arraySpecialZone) delete p;

    return printResult(result, expect, name);
}
