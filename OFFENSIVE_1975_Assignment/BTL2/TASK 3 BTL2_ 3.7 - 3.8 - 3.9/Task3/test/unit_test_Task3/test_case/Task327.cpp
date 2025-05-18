#include "../unit_test_Task3.hpp"
bool UNIT_TEST_Task3::Task327() {
    string name = "Task327";
    stringstream output;

    //! Data ------------------------------------
    // Tạo 2 đội quân với các đơn vị đặt ở vị trí khác nhau để thể hiện các trường hợp “gần – xa”

    // Đội ARVN: gồm 2 đơn vị Infantry
    // - inf_ARVN_close: đặt tại vị trí (1,1) → khá gần với một số yếu tố địa hình.
    // - inf_ARVN_far: đặt tại vị trí (5,5) → khá xa với các yếu tố tác động của vài yếu tố.
    Infantry* riNear1 = new Infantry(10, 5, Position(6, 6), REGULARINFANTRY); // Inside urban area
    Infantry* riNear2 = new Infantry(10, 5, Position(10, 6), REGULARINFANTRY); // ~1.4 units away
    Infantry* riFar = new Infantry(10, 5, Position(12, 6), REGULARINFANTRY); // ~2.8 units away
    Infantry* spNear = new Infantry(10, 5, Position(8, 8), SPECIALFORCES); // ~2.8 units away
    Infantry* spFar = new Infantry(10, 5, Position(11, 11), SPECIALFORCES); 
    Vehicle* vehicleInside = new Vehicle(10, 5, Position(6, 6), ARTILLERY); // Inside urban area
    Vehicle* vehicleNearby = new Vehicle(10, 5, Position(8, 6), ARTILLERY); // 2 units away
    Vehicle* vehicleFar = new Vehicle(10, 5, Position(10, 10), ARTILLERY); // ~5.7 units away

    Unit* unitsARVN[8] = { riNear1, riNear2, riFar, spNear, spFar, vehicleInside, vehicleNearby, vehicleFar };
    Army* arvn = new ARVN(unitsARVN, 8, "ARVN", nullptr);

    // Đội LiberationArmy: gồm 2 đơn vị Infantry
    // - inf_Lib_close: đặt tại vị trí (2,2) → gần với một số hiệu ứng đặc biệt.
    // - inf_Lib_far: đặt tại vị trí (6,6) → cách xa hơn so với hiệu ứng của một vài địa hình.
    Infantry* inf_Lib_close = new Infantry(90, 5, Position(2, 2), REGULARINFANTRY);
    Infantry* inf_Lib_far   = new Infantry(90, 5, Position(6, 6), REGULARINFANTRY);
    Infantry* sniper = new Infantry(10, 5, Position(0, 1), SNIPER); // Within radius 2
    Infantry* mortarsquad = new Infantry(6, 7, Position(0, 2), MORTARSQUAD); // Within radius 2
    Infantry* specialforces = new Infantry(4, 9, Position(0, 3), SPECIALFORCES);
    Infantry* regularinfantry = new Infantry(3, 10, Position(0, 3), REGULARINFANTRY);
    Vehicle* antiaircraft = new Vehicle(6, 7, Position(0, 2), ANTIAIRCRAFT); // Within radius 2
    Vehicle* artillery = new Vehicle(3, 10, Position(0, 3), ARTILLERY);
    Vehicle* tank = new Vehicle(2, 11, Position(0, 4), TANK);
    Unit* unitsLib[9] = { inf_Lib_close, inf_Lib_far, sniper, mortarsquad, specialforces, regularinfantry, antiaircraft, artillery, tank };
    Army* liber = new LiberationArmy(unitsLib, 9, "Liberation", nullptr);

    //! Process ------------------------------------
    // Tạo các đối tượng địa hình với vị trí cụ thể.
    // Những địa hình này sẽ được sử dụng để tác động lên các đội quân theo hiệu ứng riêng của từng loại.
    SpecialZone sz(Position(1, 1)); // Những đơn vị có tọa độ trong bán kính 1 tại (1,1) sẽ có attackScore được đặt về 0.
    Mountain mt(Position(2, 2));     // Hiệu ứng tăng EXP của infantry và giảm LF của phương tiện (ở khoảng cách ảnh hưởng).
    River rv(Position(3, 3));        // Hiệu ứng giảm 10% attackScore đối với infantry nếu ở trong bán kính 2.
    Urban ur(Position(4, 4));        // Hiệu ứng thay đổi attackScore tùy theo loại quân và khoảng cách.

    // Áp dụng hiệu ứng của tất cả các loại địa hình lên ARVN
    mt.getEffect(arvn);
    rv.getEffect(arvn);
    ur.getEffect(arvn);
    sz.getEffect(arvn);

    // Áp dụng hiệu ứng của tất cả các loại địa hình lên LiberationArmy
    mt.getEffect(liber);
    rv.getEffect(liber);
    ur.getEffect(liber);
    sz.getEffect(liber);

    // Ghi nhận thông tin kết quả sau khi các hiệu ứng được áp dụng
    output << "ARVN:\n";
    output << arvn->str() << "\n";
    output << "LiberationArmy:\n";
    output << liber->str() << "\n";

    string result = output.str();
    // Do các hiệu ứng chồng lấn và tính toán theo bán kính làm cho kết quả phức tạp,
    // ta sử dụng kết quả thực thu được làm giá trị mong đợi (golden value)
    string expect = "ARVN:\n"
    "ARVN[LF=159,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=24,weight=5,position=(8,8)],Infantry[infantryType=REGULARINFANTRY,quantity=27,weight=5,position=(6,6)],Vehicle[vehicleType=ARTILLERY,quantity=30,weight=5,position=(6,6)]],battleField=]\n"
    "LiberationArmy:\n"
    "LiberationArmy[LF=134,EXP=500,unitList=UnitList[count_vehicle=3;count_infantry=4;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=9,position=(0,3)],Infantry[infantryType=MORTARSQUAD,quantity=6,weight=7,position=(0,2)],Infantry[infantryType=SNIPER,quantity=12,weight=5,position=(0,1)],Infantry[infantryType=REGULARINFANTRY,quantity=221,weight=10,position=(2,2)],Vehicle[vehicleType=ANTIAIRCRAFT,quantity=6,weight=7,position=(0,2)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=10,position=(0,3)],Vehicle[vehicleType=TANK,quantity=2,weight=11,position=(0,4)]],battleField=]\n";

    //! Cleanup ------------------------------------
    for (auto p : unitsARVN) delete p;
    for (auto p : unitsLib) delete p;
    delete arvn;
    delete liber;
    
    return printResult(result, expect, name);
}