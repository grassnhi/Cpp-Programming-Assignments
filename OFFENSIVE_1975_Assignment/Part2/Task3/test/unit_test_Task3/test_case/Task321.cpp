#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task321() {
    string name = "Task321";
    stringstream output;

    // Kiểm tra Fortification với LiberationArmy và ARVN:
    // Với LiberationArmy: hiệu ứng là giảm 20% (attackScore giảm)
    // Với ARVN: hiệu ứng là tăng 20%
    Infantry* inf_lib = new Infantry(100, 5, Position(1, 1), SNIPER);
    Unit* unitsLib[1] = { inf_lib };
    Army* libArmy = new LiberationArmy(unitsLib, 1, "LibArmy", nullptr);
    
    Fortification fort(Position(1, 0));
    fort.getEffect(libArmy);
    
    Infantry* inf_arvn = new Infantry(100, 5, Position(1, 1), REGULARINFANTRY);
    Unit* unitsArvn[1] = { inf_arvn };
    Army* arvnArmy = new ARVN(unitsArvn, 1, "ARVN", nullptr);
    
    fort.getEffect(arvnArmy);

    output << "LibArmy Fort: " << libArmy->str() 
           << ", \nARVN Fort: " << arvnArmy->str() << "\n";
    
    string result = output.str();
    string expect = "LibArmy Fort: LiberationArmy[LF=0,EXP=500,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=120,weight=5,position=(1,1)]],battleField=], \nARVN Fort: ARVN[LF=0,EXP=500,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=90,weight=5,position=(1,1)]],battleField=]\n";
    
    delete inf_lib;
    delete libArmy;
    delete inf_arvn;
    delete arvnArmy;
    
    return printResult(result, expect, name);
}
