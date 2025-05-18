#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task317() {
    string name = "Task317";
    stringstream output;

    //! Data ------------------------------------
    // Tạo các vector chứa vị trí cho từng loại TerrainElement
    vector<Position*> arrayForest;        // Dành cho Mountain (rừng núi)
    vector<Position*> arrayRiver;         // River
    vector<Position*> arrayFortification; // Fortification
    vector<Position*> arrayUrban;         // Urban
    vector<Position*> arraySpecialZone;   // SpecialZone

    // Khởi tạo một số vị trí đặc trưng trong BattleField 5x5:
    // Ví dụ: (0,0) và (0,2) sẽ là Mountain, (1,1) là River, (2,3) là Fortification,
    // (3,2) là Urban, (4,4) là SpecialZone. Các vị trí còn lại mặc định sẽ là Road.
    arrayForest.push_back(new Position(0, 0));
    arrayForest.push_back(new Position(0, 2));
    arrayRiver.push_back(new Position(1, 1));
    arrayFortification.push_back(new Position(2, 3));
    arrayUrban.push_back(new Position(3, 2));
    arraySpecialZone.push_back(new Position(4, 4));

    int n_rows = 5, n_cols = 5;
    // Tạo BattleField với các yếu tố địa hình được khởi tạo thông qua các vector trên
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    //! Tạo hai đội quân ------------------------------------
    // Đội quân LiberationArmy với 3 đơn vị:
    // - 2 infantry đặt tại (0,0) và (0,2) (nằm trên vùng Mountain)
    // - 1 vehicle đặt tại (1,1) (nằm trên vùng River)
    Infantry* libInf1 = new Infantry(12, 6, Position(0, 0), SNIPER);
    Infantry* libInf2 = new Infantry(11, 5, Position(0, 2), REGULARINFANTRY);
    Vehicle* libVeh1 = new Vehicle(10, 5, Position(1, 1), TRUCK);
    Unit* unitsLib[3] = { libInf1, libInf2, libVeh1 };
    // Gán con trỏ BattleField vào Army nếu cần (để sử dụng trong việc cập nhật vị trí hoặc hiệu ứng riêng)
    Army* liber = new LiberationArmy(unitsLib, 3, "LibArmy", bf);

    // Đội quân ARVN với 3 đơn vị:
    // - 1 infantry đặt tại (3,2) (nằm trên vùng Urban)
    // - 1 infantry đặt tại (2,3) (nằm trên vùng Fortification)
    // - 1 vehicle đặt tại (4,4) (nằm trên vùng SpecialZone)
    Infantry* arvnInf1 = new Infantry(9, 6, Position(3, 2), SPECIALFORCES);
    Infantry* arvnInf2 = new Infantry(8, 7, Position(2, 3), ANTIAIRCRAFTSQUAD);
    Vehicle* arvnVeh1 = new Vehicle(11, 4, Position(4, 4), MORTAR);
    Unit* unitsArvn[3] = { arvnInf1, arvnInf2, arvnVeh1 };
    Army* arvn = new ARVN(unitsArvn, 3, "ARVN", bf);

    //! Process ---------------------------------
    output << "Initial State:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // Áp dụng hiệu ứng của toàn bộ BattleField (Round 1)
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

    // Giả lập trận chiến: LiberationArmy tấn công ARVN
    output << "Liberation attacks ARVN:" << endl;
    liber->fight(arvn, false);
    output << "After Attack:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // ARVN phản công (phòng thủ)
    output << "ARVN defends Liberation:" << endl;
    arvn->fight(liber, true);
    output << "After Defense:" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    // Áp dụng hiệu ứng của BattleField lần 2 (Round 2)
    output << "Applying Battlefield Effects (Round 2):" << endl;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            bf->getElement(i, j)->getEffect(liber);
            bf->getElement(i, j)->getEffect(arvn);
        }
    }
    output << "After Effects (Round 2):" << endl;
    output << "1. " << liber->str() << endl;
    output << "2. " << arvn->str() << endl;

    //! Kết quả ---------------------------------
    string result = output.str();
    // Vì các hiệu ứng chồng lấn và tính toán theo bán kính làm cho chuỗi kết quả rất phức tạp, ta sử dụng giá trị thực thu được làm kỳ vọng.
    string expect = "Initial State:\n1. LiberationArmy[LF=2,EXP=407,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=11,weight=5,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=6,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,1)]],battleField=BattleField[n_rows=5,n_cols=5]]\n2. ARVN[LF=12,EXP=404,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=7,position=(2,3)],Infantry[infantryType=SPECIALFORCES,quantity=9,weight=6,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=11,weight=4,position=(4,4)]],battleField=BattleField[n_rows=5,n_cols=5]]\nApplying Battlefield Effects (Round 1):\nAfter Effects (Round 1):\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=11,weight=5,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=6,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,1)]],battleField=BattleField[n_rows=5,n_cols=5]]\n2. ARVN[LF=12,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=7,position=(2,3)],Infantry[infantryType=SPECIALFORCES,quantity=9,weight=6,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=11,weight=4,position=(4,4)]],battleField=BattleField[n_rows=5,n_cols=5]]\nLiberation attacks ARVN:\nAfter Attack:\n1. LiberationArmy[LF=2,EXP=407,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=11,weight=5,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=6,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,1)]],battleField=BattleField[n_rows=5,n_cols=5]]\n2. ARVN[LF=12,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=7,position=(2,3)],Infantry[infantryType=SPECIALFORCES,quantity=9,weight=6,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=11,weight=4,position=(4,4)]],battleField=BattleField[n_rows=5,n_cols=5]]\nARVN defends Liberation:\nAfter Defense:\n1. LiberationArmy[LF=2,EXP=407,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=11,weight=5,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=6,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,1)]],battleField=BattleField[n_rows=5,n_cols=5]]\n2. ARVN[LF=12,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=7,position=(2,3)],Infantry[infantryType=SPECIALFORCES,quantity=9,weight=6,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=11,weight=4,position=(4,4)]],battleField=BattleField[n_rows=5,n_cols=5]]\nApplying Battlefield Effects (Round 2):\nAfter Effects (Round 2):\n1. LiberationArmy[LF=2,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=REGULARINFANTRY,quantity=11,weight=5,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=6,position=(0,0)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(1,1)]],battleField=BattleField[n_rows=5,n_cols=5]]\n2. ARVN[LF=12,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=7,position=(2,3)],Infantry[infantryType=SPECIALFORCES,quantity=9,weight=6,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=11,weight=4,position=(4,4)]],battleField=BattleField[n_rows=5,n_cols=5]]\n";

    //! Cleanup ---------------------------------
    delete libInf1;
    delete libInf2;
    delete libVeh1;
    delete arvnInf1;
    delete arvnInf2;
    delete arvnVeh1;
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
