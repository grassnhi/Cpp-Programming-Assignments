#include "../unit_test_Task2.hpp"

bool UNIT_TEST_Task2::Task216()
{
    string name = "Task216";
    //! data ------------------------------------
    Vehicle tankOfArvn(5, 2, Position(1, 2), TANK);      // getAttackScore() = safeCeil((5 * 2 + 6 * 304) / 30) = safeCeil(1834 / 30) = 62
    Vehicle truckOfArvn(3, 1, Position(2, 2), TRUCK);    // getAttackScore() = safeCeil((3 * 1 + 0 * 304) / 30) = safeCeil(3 / 30) = 1
    Infantry sniperOfArvn(5, 2, Position(1, 1), SNIPER); // getAttackScore() = 5 * 2 + 0 = 10

    Unit **unitArrayOfArvn = new Unit *[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &truckOfArvn;
    unitArrayOfArvn[2] = &sniperOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy216");

    //! process ---------------------------------
    string result = "LF=" + to_string(arvn->getLF()) + "\nEXP=" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfArvn: safeCeil((5 * 2 + 6 * 304) / 30) = safeCeil(1834 / 30) = 62
    // truckOfArvn: safeCeil((3 * 1 + 0 * 304) / 30) = safeCeil(3 / 30) = 1
    // Tổng LF = 62 + 1 = 63 (không vượt quá 1000)
    //
    // Chi tiết tính toán EXP:
    // sniperOfArvn: 5 * 2 = 10
    // EXP = min(10, 500) = 10
    string expect = "LF=63\nEXP=10";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfArvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task217()
{
    string name = "Task217";
    //! data ------------------------------------
    Vehicle tankOfArvn(8, 3, Position(3, 3), TANK);                 // getAttackScore() = safeCeil((8 * 3 + 6 * 304) / 30) = 62
    Vehicle mortarOfArvn(4, 2, Position(4, 4), MORTAR);             // getAttackScore() = safeCeil((4 * 2 + 1 * 304) / 30) = 11
    Infantry riflemanOfArvn(6, 3, Position(2, 2), REGULARINFANTRY); // getAttackScore() = (5 * 56) + (6 * 3) = 298

    Unit **unitArrayOfArvn = new Unit *[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &mortarOfArvn;
    unitArrayOfArvn[2] = &riflemanOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy217");

    //! process ---------------------------------
    string result = "LF=" + to_string(arvn->getLF()) + "\nEXP=" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfArvn: safeCeil((8 * 3 + 6 * 304) / 30) = 62
    // mortarOfArvn: safeCeil((4 * 2 + 1 * 304) / 30) = 11
    // Tổng LF = 62 + 11 = 73 (không vượt quá 1000)
    //
    // Chi tiết tính toán EXP:
    // riflemanOfArvn: (5 * 56) + (6 * 3) = 298
    // EXP = min(298, 500) = 298
    string expect = "LF=73\nEXP=298";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfArvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task218()
{
    string name = "Task218";
    //! data ------------------------------------
    Vehicle truckOfArvn(10, 5, Position(5, 5), TRUCK);                // getAttackScore() = safeCeil((10 * 5 + 0 * 304) / 30) = safeCeil(50 / 30) = 2
    Vehicle armoredCarOfArvn(5, 2, Position(6, 5), ARMOREDCAR);       // getAttackScore() = safeCeil((5 * 2 + 3 * 304) / 30) = safeCeil(922 / 30) = 31
    Infantry specialForceOfArvn(3, 1, Position(5, 4), SPECIALFORCES); // Logic đặc biệt áp dụng cho SPECIALFORCES

    Unit **unitArrayOfArvn = new Unit *[3];
    unitArrayOfArvn[0] = &truckOfArvn;
    unitArrayOfArvn[1] = &armoredCarOfArvn;
    unitArrayOfArvn[2] = &specialForceOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy218");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=33,EXP=228,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(5,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(5,5)],Vehicle[vehicleType=ARMOREDCAR,quantity=5,weight=2,position=(6,5)]]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfArvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task219()
{
    string name = "Task219";
    //! data ------------------------------------
    Vehicle artilleryOfArvn(6, 4, Position(7, 7), ARTILLERY);       // getAttackScore() = ceil((6 * 4 + 5 * 304) / 30) = ceil(1544 / 30) = 52
    Vehicle antiAircraftOfArvn(4, 3, Position(8, 8), ANTIAIRCRAFT); // getAttackScore() = ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    Infantry scoutOfArvn(3, 2, Position(7, 6), SPECIALFORCES);      // getAttackScore() = (4 * 56) + (4 * 2) = 232

    Unit **unitArrayOfArvn = new Unit *[3];
    unitArrayOfArvn[0] = &artilleryOfArvn;
    unitArrayOfArvn[1] = &antiAircraftOfArvn;
    unitArrayOfArvn[2] = &scoutOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy204");

    //! process ---------------------------------
    string result = to_string(arvn->getLF()) + "\n" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // artilleryOfArvn: ceil((6 * 4 + 5 * 304) / 30) = ceil(1544 / 30) = 52
    // antiAircraftOfArvn: ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    // Tổng LF = 52 + 21 = 73 (không vượt quá 1000)
    //
    // Chi tiết tính toán EXP:
    // scoutOfArvn: (4 * 56) + (4 * 2) = 232
    // EXP = min(232, 500) = 232
    string expect = "73\n232";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfArvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task220()
{
    string name = "Task220";
    //! data ------------------------------------
    Vehicle tankOfArvn(7, 3, Position(0, 1), TANK);            // getAttackScore() = ceil((7 * 3 + 6 * 304) / 30) = ceil(1854 / 30) = 62
    Vehicle truckOfArvn(5, 2, Position(2, 3), TRUCK);          // getAttackScore() = ceil((5 * 2 + 0 * 304) / 30) = ceil(10 / 30) = 1
    Infantry sniperOfArvn(10, 4, Position(1, 2), MORTARSQUAD); // getAttackScore() = (2 * 56) + (10 * 4) = 112 + 40 = 152

    Unit **unitArrayOfArvn = new Unit *[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &truckOfArvn;
    unitArrayOfArvn[2] = &sniperOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy205");

    //! process ---------------------------------
    string result = to_string(arvn->getLF()) + "\n" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfArvn: ceil((7 * 3 + 6 * 304) / 30) = ceil(1854 / 30) = 62
    // truckOfArvn: ceil((5 * 2 + 0 * 304) / 30) = ceil(10 / 30) = 1
    // Tổng LF = 62 + 1 = 63 (không vượt quá 1000)
    //
    // Chi tiết tính toán EXP:
    // sniperOfArvn:
    //   - Base score = (2 * 56) + (10 * 4) = 112 + 40 = 152
    //   - EXP = min(152, 500) = 152
    string expect = "63\n152";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfArvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task221()
{
    string name = "Task221";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1, 1), TANK);    // getAttackScore() = ceil((3 * 1 + 6 * 304) / 30) = ceil(1824 / 30) = 61
    Infantry i1(2, 1, Position(1, 2), SNIPER); // getAttackScore() = (0 * 56) + (2 * 1) = 2

    Unit **unitArray = new Unit *[2];
    unitArray[0] = &i1;
    unitArray[1] = &v1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy221");

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // v1 (TANK): ceil((3 * 1 + 6 * 304) / 30) = ceil(1824 / 30) = 61
    //
    // Chi tiết tính toán EXP:
    // i1 (SNIPER):
    //   - Base score = (0 * 56) + (2 * 1) = 2
    //   - EXP = min(2, 500) = 2
    //
    // Kết quả:
    // LF = 61
    // EXP = 2
    string expect = "ARVN[LF=61,EXP=2,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=2,weight=1,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task222()
{
    string name = "Task222";
    //! data ------------------------------------
    Vehicle v1(5, 3, Position(1, 1), TANK);             // getAttackScore() = ceil((6 * 304 + 5 * 3) / 30) = ceil(1833 / 30) = 62
    Infantry i1(3, 2, Position(2, 3), REGULARINFANTRY); // getAttackScore() = (5 * 56) + (3 * 2) = 280 + 6 = 286

    Unit **unitArray = new Unit *[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy222");

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // v1 (TANK): ceil((5 * 3 + 6 * 304) / 30) = ceil(1833 / 30) = 62
    //
    // Chi tiết tính toán EXP:
    // i1 (REGULARINFANTRY):
    //   - Base score = (5 * 56) + (3 * 2) = 280 + 6 = 286
    //   - EXP = min(286, 500) = 286
    //
    // Kết quả:
    // LF = 62
    // EXP = 286
    string expect = "ARVN[LF=62,EXP=286,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=3,weight=2,position=(2,3)],Vehicle[vehicleType=TANK,quantity=5,weight=3,position=(1,1)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task223()
{
    string name = "Task223";
    //! data ------------------------------------
    Vehicle v1(4, 2, Position(1, 1), ARTILLERY);          // getAttackScore() = ceil((4 * 2 + 5 * 304) / 30) = ceil(1528 / 30) = 51
    Infantry i1(3, 3, Position(3, 3), ANTIAIRCRAFTSQUAD); // getAttackScore() = (1 * 56) + (3 * 3) = 56 + 9 = 65

    Unit **unitArray = new Unit *[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy223");

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // v1 (ARTILLERY): ceil((4 * 2 + 5 * 304) / 30) = ceil(1528 / 30) = 51
    //
    // Chi tiết tính toán EXP:
    // i1 (ANTIAIRCRAFTSQUAD):
    //   - Base score = (1 * 56) + (3 * 3) = 56 + 9 = 65
    //   - EXP = min(65, 500) = 65
    //
    // Kết quả:
    // LF = 51
    // EXP = 65
    string expect = "ARVN[LF=51,EXP=65,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=3,weight=3,position=(3,3)],Vehicle[vehicleType=ARTILLERY,quantity=4,weight=2,position=(1,1)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task224()
{
    string name = "Task224";
    //! data ------------------------------------
    Vehicle v1(2, 4, Position(2, 2), TANK);           // getAttackScore() = ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    Infantry i1(6, 5, Position(3, 3), SPECIALFORCES); // getAttackScore() = (4 * 56) + (6 * 5) = 224 + 30 = 254

    Unit **unitArray = new Unit *[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy224");

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // v1 (TANK): ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    //
    // Chi tiết tính toán EXP:
    // i1 (SPECIALFORCES):
    //   - Base score = (4 * 56) + (6 * 5) = 224 + 30 = 254
    //   - EXP = min(254, 500) = 254
    //
    // Kết quả:
    // LF = 62
    // EXP = 254
    string expect = "ARVN[LF=62,EXP=254,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=6,weight=5,position=(3,3)],Vehicle[vehicleType=TANK,quantity=2,weight=4,position=(2,2)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task225()
{
    string name = "Task225";
    //! data ------------------------------------
    Vehicle v1(2, 4, Position(2, 2), TANK);           // getAttackScore() = ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    Vehicle v2(3, 2, Position(3, 1), TRUCK);          // getAttackScore() = ceil((3 * 2 + 0 * 304) / 30) = ceil(6 / 30) = 1
    Vehicle v3(4, 3, Position(1, 1), ARMOREDCAR);     // getAttackScore() = ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    Infantry i1(6, 5, Position(3, 3), SPECIALFORCES); // getAttackScore() = (4 * 56) + (6 * 5) = 224 + 30 = 254

    Unit **unitArray = new Unit *[4];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &v3;
    unitArray[3] = &i1;
    ARVN *army = new ARVN(unitArray, 4, "TestArmy225");

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // v1 (TANK): ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    // v2 (TRUCK): ceil((3 * 2 + 0 * 304) / 30) = ceil(6 / 30) = 1
    // v3 (ARMOREDCAR): ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    // Tổng LF = 62 + 1 + 21 = 94
    //
    // Chi tiết tính toán EXP:
    // i1 (SPECIALFORCES):
    //   - Base score = (4 * 56) + (6 * 5) = 224 + 30 = 254
    //   - EXP = min(254, 500) = 254
    //
    // Kết quả:
    // LF = 94
    // EXP = 254
    string expect = "ARVN[LF=94,EXP=254,unitList=UnitList[count_vehicle=3;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=6,weight=5,position=(3,3)],Vehicle[vehicleType=TANK,quantity=2,weight=4,position=(2,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,1)],Vehicle[vehicleType=ARMOREDCAR,quantity=4,weight=3,position=(1,1)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task228()
{
    string name = "Task228";
    //! data ------------------------------------
    // Không có đơn vị nào trong ARVN
    Unit **unitArrayOfAr = nullptr; // Mảng trống
    ARVN *arvn = new ARVN(unitArrayOfAr, 0, "EmptyARVN");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // LF = 0, EXP = 0, không có đơn vị nào
    string expect = "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task229()
{
    string name = "Task229";
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(4, 2, Position(3, 3), TANK);      // getAttackScore() = ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(2, 1, Position(4, 4), TRUCK);    // getAttackScore() = ceil((0 * 304 + 2 * 1) / 30) = ceil(2 / 30) = 1
    Infantry sniperOfAr(6, 2, Position(5, 5), SNIPER); // getAttackScore() = (0 * 56) + (6 * 2) = 12

    Unit **unitArrayOfAr = new Unit *[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfAr (TANK): ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    // truckOfAr (TRUCK): ceil((0 * 304 + 2 * 1) / 30) = ceil(2 / 30) = 1
    // Tổng LF = 62 + 1 = 63
    //
    // Chi tiết tính toán EXP:
    // sniperOfAr (SNIPER):
    //   - Base score = (0 * 56) + (6 * 2) = 12
    //   - EXP = min(12, 500) = 12
    //
    // Kết quả:
    // LF = 63
    // EXP = 12
    string expect = "ARVN[LF=63,EXP=12,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=6,weight=2,position=(5,5)],Vehicle[vehicleType=TANK,quantity=4,weight=2,position=(3,3)],Vehicle[vehicleType=TRUCK,quantity=2,weight=1,position=(4,4)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfAr;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task230()
{
    string name = "Task230";
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(3, 3, Position(3, 3), TANK);      // getAttackScore() = ceil((6 * 304 + 3 * 3) / 30) = ceil(1839 / 30) = 62
    Vehicle truckOfAr(2, 2, Position(4, 4), TRUCK);    // getAttackScore() = ceil((0 * 304 + 2 * 2) / 30) = ceil(4 / 30) = 1
    Infantry sniperOfAr(4, 2, Position(5, 5), SNIPER); // getAttackScore() = (0 * 56) + (4 * 2) = 8

    Unit **unitArrayOfAr = new Unit *[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfAr (TANK): ceil((6 * 304 + 3 * 3) / 30) = ceil(1839 / 30) = 62
    // truckOfAr (TRUCK): ceil((0 * 304 + 2 * 2) / 30) = ceil(4 / 30) = 1
    // Tổng LF = 62 + 1 = 63
    //
    // Chi tiết tính toán EXP:
    // sniperOfAr (SNIPER):
    //   - Base score = (0 * 56) + (4 * 2) = 8
    //   - EXP = min(8, 500) = 8
    //
    // Kết quả:
    // LF = 63
    // EXP = 8
    string expect = "ARVN[LF=63,EXP=8,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=4,weight=2,position=(5,5)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,3)],Vehicle[vehicleType=TRUCK,quantity=2,weight=2,position=(4,4)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfAr;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task226()
{
    string name = "Task226";
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(5, 2, Position(3, 2), TANK);      // getAttackScore() = ceil((6 * 304 + 5 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(3, 1, Position(3, 1), TRUCK);    // getAttackScore() = ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    Infantry sniperOfAr(5, 2, Position(3, 3), SNIPER); // getAttackScore() = (0 * 56) + (5 * 2) = 10

    Unit **unitArrayOfAr = new Unit *[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfAr (TANK): ceil((6 * 304 + 5 * 2) / 30) = ceil(1832 / 30) = 62
    // truckOfAr (TRUCK): ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    // Tổng LF = 62 + 1 = 63
    //
    // Chi tiết tính toán EXP:
    // sniperOfAr (SNIPER):
    //   - Base score = (0 * 56) + (5 * 2) = 10
    //   - EXP = min(10, 500) = 10
    //
    // Kết quả:
    // LF = 63
    // EXP = 10
    string expect = "ARVN[LF=63,EXP=10,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=5,weight=2,position=(3,3)],Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=1,position=(3,1)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfAr;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task227()
{
    string name = "Task227";
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(4, 2, Position(3, 2), TANK);      // getAttackScore() = ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(3, 1, Position(3, 1), TRUCK);    // getAttackScore() = ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    Infantry sniperOfAr(5, 2, Position(3, 3), SNIPER); // getAttackScore() = (0 * 56) + (5 * 2) = 10

    Unit **unitArrayOfAr = new Unit *[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN");

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // Chi tiết tính toán LF:
    // tankOfAr (TANK): ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    // truckOfAr (TRUCK): ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    // Tổng LF = 62 + 1 = 63
    //
    // Chi tiết tính toán EXP:
    // sniperOfAr (SNIPER):
    //   - Base score = (0 * 56) + (5 * 2) = 10
    //   - EXP = min(10, 500) = 10
    //
    // Kết quả:
    // LF = 63
    // EXP = 10
    string expect = "ARVN[LF=63,EXP=10,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=5,weight=2,position=(3,3)],Vehicle[vehicleType=TANK,quantity=4,weight=2,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=1,position=(3,1)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;
    delete[] unitArrayOfAr;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}