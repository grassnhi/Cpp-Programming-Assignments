#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task320() {
    string name = "Task320";
    stringstream output;

    // --- Phần 1: Quân Giải phóng ---
    // Với LiberationArmy: 
    // - Bộ binh (SPECIALFORCES): nếu trong bán kính 5 thì bonus = ceil(2 * attackScore / D)
    // - Phương tiện (ARTILLERY): nếu trong bán kính 2 thì penalty = ceil(attackScore/2)
    Infantry* inf_lib = new Infantry(100, 5, Position(1, 1), SPECIALFORCES);
    Vehicle* veh_lib = new Vehicle(80, 5, Position(1, 1), ARTILLERY);
    Unit* unitsLib[2] = { inf_lib, veh_lib };
    Army* libArmy = new LiberationArmy(unitsLib, 2, "LibArmy", nullptr);
    
    Urban urban(Position(1, 0));
    urban.getEffect(libArmy);
    
    // --- Phần 2: Quân ARVN ---
    // Với ARVN: chỉ bộ binh loại REGULARINFANTRY được tăng bonus nếu trong bán kính 3,
    // bonus = ceil(3*attackScore / (2*D))
    Infantry* inf_arvn = new Infantry(100, 5, Position(1, 1), REGULARINFANTRY);
    Vehicle* veh_arvn = new Vehicle(90, 5, Position(1, 1), TRUCK); // Không bị ảnh hưởng
    Unit* unitsArvn[2] = { inf_arvn, veh_arvn };
    Army* arvnArmy = new ARVN(unitsArvn, 2, "ARVN", nullptr);
    
    urban.getEffect(arvnArmy);
    
    // Với distance = 1: bonus = ceil(3*100/(2*1)) = ceil(150) = 150
    output << "LibArmy Fort: " << libArmy->str() 
           << ", \nARVN Fort: " << arvnArmy->str() << "\n";
    
    string result = output.str();
    string expect = "LibArmy Fort: LiberationArmy[LF=64,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=120,weight=5,position=(1,1)],Vehicle[vehicleType=ARTILLERY,quantity=80,weight=5,position=(1,1)]],battleField=], \nARVN Fort: ARVN[LF=15,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(1,1)],Vehicle[vehicleType=TRUCK,quantity=90,weight=5,position=(1,1)]],battleField=]\n";
    
    delete inf_lib;
    delete veh_lib;
    delete libArmy;
    delete inf_arvn;
    delete veh_arvn;
    delete arvnArmy;
    
    return printResult(result, expect, name);
}