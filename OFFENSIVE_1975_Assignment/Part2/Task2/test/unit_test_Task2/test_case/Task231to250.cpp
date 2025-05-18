#include "../unit_test_Task2.hpp"

bool UNIT_TEST_Task2::Task231() {
    string name = "Task231";
    
    //! data ------------------------------------
    UnitList list(10);
    int countFalse = 0;
    Infantry soldier(5, 10, Position(0, 0), REGULARINFANTRY);
    bool result = list.insert(&soldier);
   
    for (int i = 0; i < 20; i++) countFalse += list.insert(&soldier);
    
    //! expect ----------------------------------
    string expect = "10";
    
    //! output ----------------------------------
    stringstream output;
    output << result << countFalse;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task232() {
    string name = "Task232";
    
    //! data ------------------------------------
    UnitList list(1);
    Infantry soldier(5, 10, Position(0, 0), REGULARINFANTRY);
    Vehicle tank(2, 50, Position(1, 1), TANK);
    list.insert(&soldier);
    bool result = list.insert(&tank);
    
    //! expect ----------------------------------
    string expect = "1";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task233() {
    string name = "Task233";
    
    //! data ------------------------------------
    UnitList list(10);
    Vehicle tank(2, 50, Position(1, 1), TANK);
    list.insert(&tank);
    bool result = list.isContain(TANK);
    
    //! expect ----------------------------------
    string expect = "1";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task234() {
    string name = "Task234";
    
    //! data ------------------------------------
    UnitList list(10);
    Infantry sniper(3, 8, Position(2, 2), SNIPER);
    list.insert(&sniper);
    bool result = list.isContain(SNIPER);
    
    //! expect ----------------------------------
    string expect = "1";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task235() {
    string name = "Task235";
    
    //! data ------------------------------------
    UnitList list(10);
    bool result = list.isContain(TANK);
    
    //! expect ----------------------------------
    string expect = "0";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task236() {
    string name = "Task236";
    
    //! data ------------------------------------
    UnitList list(10);
    string result = list.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=0;count_infantry=0]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task237() {
    string name = "Task237";
    
    //! data ------------------------------------
    UnitList list(10);
    list.insert(nullptr);
    string result = list.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=0;count_infantry=0]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task238() {
    string name = "Task238";
    
    //! data ------------------------------------
    UnitList list(7);
    Vehicle artillery(2, 80, Position(6, 6), ARTILLERY);
    list.insert(&artillery);
    bool result = list.insert(nullptr);
    
    //! expect ----------------------------------
    string expect = "0";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(to_string(result), expect, name);
}

bool UNIT_TEST_Task2::Task239() {
    string name = "Task239";
    
    //! data ------------------------------------
    UnitList list(6);
    for (int i = 0; i < 6; ++i) {
        list.insert(new Infantry(3, 10, Position(i, i), REGULARINFANTRY));
    }
    bool result = list.insert(new Vehicle(1, 50, Position(4, 4), TANK));
    
    //! expect ----------------------------------
    string expect = "1";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(to_string(result), expect, name);
}

bool UNIT_TEST_Task2::Task240() {
    string name = "Task240";

    //! data ------------------------------------
    UnitList ul(1);
    bool allInserted = true;
    for (int i = 0; i < 12; ++i) {
        Infantry* inf = new Infantry(1, 1, Position(), REGULARINFANTRY);
        if (!ul.insert(inf)) {
            allInserted = false;
            break;
        }
    }
    Infantry* inf13 = new Infantry(1, 1, Position(), REGULARINFANTRY);
    bool insert13 = ul.insert(inf13);
    delete inf13;
    bool result = allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task241() {
    string name = "Task241";

    //! data ------------------------------------
    UnitList ul(5);
    bool allInserted = true;
    for (int i = 0; i < 12; ++i) {
        Vehicle* veh = new Vehicle(1, 1, Position(), TRUCK);
        if (!ul.insert(veh)) {
            allInserted = false;
            break;
        }
    }
    Vehicle* veh13 = new Vehicle(1, 1, Position(), TRUCK);
    bool insert13 = ul.insert(veh13);
    delete veh13;
    bool result = allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task242() {
    string name = "Task242";

    //! data ------------------------------------
    UnitList ul(5);
    bool allInserted = true;
    for (int i = 0; i < 12; ++i) {
        Vehicle* veh = new Vehicle(1, 1, Position(), TRUCK);
        if (!ul.insert(veh)) {
            allInserted = false;
            break;
        }
    }
    Vehicle* veh13 = new Vehicle(1, 1, Position(), TRUCK);
    bool insert13 = ul.insert(veh13);
    delete veh13;
    bool result = allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task243() {
    string name = "Task243";

    //! data ------------------------------------
    UnitList ul(-10);
    bool allInserted = true;
    for (int i = 0; i < 8; ++i) {
        Infantry* inf = new Infantry(1, 1, Position(), REGULARINFANTRY);
        if (!ul.insert(inf)) {
            allInserted = false;
            break;
        }
    }
    Infantry* inf9 = new Infantry(1, 1, Position(), REGULARINFANTRY);
    bool insert9 = ul.insert(inf9);
    delete inf9;
    bool result = allInserted && !insert9;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task244() {
    string name = "Task244";

    //! data ------------------------------------
    UnitList ul(12);
    Infantry* inf = new Infantry(1, 1, Position(), ENGINEER);
    Vehicle* veh = new Vehicle(1, 1, Position(), ARTILLERY);
    ul.insert(inf);
    ul.insert(veh);
    string resultStr = ul.str();
    bool order = resultStr.find("Infantry") < resultStr.find("Vehicle");
    
    //! expect ----------------------------------
    string expect = "1";

    //! output ----------------------------------
    stringstream output;
    output << order;

    delete inf;
    delete veh;
    
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task245() {
    string name = "Task245";

    //! data ------------------------------------
    UnitList ul(1); 
    bool allInserted = true;
    for (int i = 0; i < 12; ++i) {
        Vehicle* veh = new Vehicle(1, 1, Position(), TANK);
        if (!ul.insert(veh)) allInserted = false;
    }
    Vehicle* veh13 = new Vehicle(1, 1, Position(), TANK);
    bool insert13 = ul.insert(veh13);
    delete veh13;
    bool result = allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task246() {
    string name = "Task246";
    
    //! data ------------------------------------
    UnitList ul(12);
    Vehicle* veh = new Vehicle(1, 1, Position(), APC);
    ul.insert(veh);
    bool hasAPC = ul.isContain(APC);
    bool hasTruck = ul.isContain(TRUCK);
    bool result = hasAPC && !hasTruck;

    //! expect ----------------------------------
    string expect = "1";
    stringstream output;

    //! output ----------------------------------
    output << result;
    delete veh;
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task247() {
    string name = "Task247";

    //! data ------------------------------------
    UnitList ul(12);
    Infantry* inf = new Infantry(1, 1, Position(), SNIPER);
    ul.insert(inf);
    bool hasSniper = ul.isContain(SNIPER);
    bool hasEngineer = ul.isContain(ENGINEER);
    bool result = hasSniper && !hasEngineer;

    //! expect ----------------------------------
    string expect = "1";

    //! output ----------------------------------
    stringstream output;
    output << result;

    delete inf;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task248() {
    string name = "Task248";
    
    //! data ------------------------------------
    UnitList ul(12);
    Infantry* inf = new Infantry(2, 5, Position(3,4), SPECIALFORCES);
    Vehicle* veh = new Vehicle(3, 10, Position(1,2), ARMOREDCAR);
    ul.insert(inf);
    ul.insert(veh);
    string result = ul.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=2,weight=5,position=(3,4)],Vehicle[vehicleType=ARMOREDCAR,quantity=3,weight=10,position=(1,2)]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    delete inf;
    delete veh;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task249() {
    string name = "Task249";
    
    //! data ------------------------------------
    UnitList ul(12);
    Vehicle* veh = new Vehicle(3, 10, Position(1,2), ARMOREDCAR);
    ul.insert(veh);
    string result = ul.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=1;count_infantry=0;Vehicle[vehicleType=ARMOREDCAR,quantity=3,weight=10,position=(1,2)]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    delete veh;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task250() {
    string name = "Task250";

    //! data ------------------------------------
    UnitList ul(12);
    ul.insert(new Infantry(1,1, Position(), REGULARINFANTRY));
    ul.insert(new Vehicle(1,1, Position(), MORTAR));
    ul.insert(new Infantry(1,1, Position(), ANTIAIRCRAFTSQUAD));
    string result = ul.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=1,weight=1,position=(0,0)],Infantry[infantryType=REGULARINFANTRY,quantity=1,weight=1,position=(0,0)],Vehicle[vehicleType=MORTAR,quantity=1,weight=1,position=(0,0)]]";

    //! output ----------------------------------
    stringstream output;
    output << result;
    return printResult(output.str(), expect, name);
}