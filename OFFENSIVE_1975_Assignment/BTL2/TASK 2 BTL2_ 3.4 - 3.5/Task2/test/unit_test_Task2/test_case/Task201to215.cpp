#include "../unit_test_Task2.hpp"

bool UNIT_TEST_Task2::Task204()
{
    string name = "Task204";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), ANTIAIRCRAFT);
    Vehicle v2(5, 2, Position(1,2), MORTAR);
    Infantry i1(2, 1, Position(2,1), SNIPER);
    Infantry i2(3, 1, Position(2,2), SPECIALFORCES);
    Infantry i3(4, 1, Position(2,3), REGULARINFANTRY);
    
    Unit** unitArray = new Unit*[5];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &i1;
    unitArray[3] = &i2;
    unitArray[4] = &i3;
    LiberationArmy* army = new LiberationArmy(unitArray, 5, "TestArmy207");

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());
    //! expect ----------------------------------
    string expect = "32\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task205()
{
    string name = "Task205";
    //! data ------------------------------------
    /* Vehicle */
    Vehicle v1(2, 1, Position(1,1), TRUCK);         
    Vehicle v2(3, 1, Position(1,2), MORTAR);          
    Vehicle v3(3, 2, Position(1,3), ARMOREDCAR);      
    Vehicle v4(4, 1, Position(1,4), TANK);             
    Vehicle v5(4, 2, Position(1,4), ARTILLERY);             
    Vehicle v6(1, 1, Position(1,4), ARTILLERY);            
    Vehicle v7(1, 2, Position(1,4), APC);             
    Vehicle v8(3, 4, Position(1,4), APC);     
    /* Infantry */        
    Infantry i1(10, 1, Position(2,1), SNIPER);            
    Infantry i2(20, 1, Position(2,2), SPECIALFORCES);      
    Infantry i3(15, 1, Position(2,3), ENGINEER);           
    Infantry i4(7, 1, Position(2,4), REGULARINFANTRY);     

    Unit** unitArray = new Unit*[12];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &v3;
    unitArray[3] = &v4;
    unitArray[4] = &v5;
    unitArray[5] = &v6;
    unitArray[6] = &v7;
    unitArray[7] = &v8;
    unitArray[8] = &i1;
    unitArray[9] = &i2;
    unitArray[10] = &i3;
    unitArray[11] = &i4;

    LiberationArmy* army = new LiberationArmy(unitArray, 12, "TestArmy205");

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());

    //! expect ----------------------------------
    string expect = "288\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task206()
{
    string name = "Task206";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);
    
    Unit* unitArray[1];
    unitArray[0] = &v1;
    
    LiberationArmy army = LiberationArmy(unitArray, 1, "TestArmy206");
    Army* copy = &army;

    //! process ---------------------------------
    string result = army.str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=61,EXP=0,unitList=UnitList[count_vehicle=1;count_infantry=0;Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]]]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    // delete army;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task207()
{
    string name = "Task207";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);
    Vehicle v2(4, 2, Position(1,2), TRUCK);
    Vehicle v3(5, 2, Position(3,1), MORTAR);
    Vehicle v4(2, 3, Position(3,3), ARTILLERY);
    
    Infantry i1(2, 1, Position(2,1), SNIPER);
    Infantry i2(4, 2, Position(2,2), SPECIALFORCES);
    Infantry i3(3, 1, Position(3,2), SNIPER);
    
    Unit* unitArray[7];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &i1;
    unitArray[3] = &i2;
    unitArray[4] = &v3;
    unitArray[5] = &i3;
    unitArray[6] = &v4;
    
    LiberationArmy* army = new LiberationArmy(unitArray, 7, "TestArmy207");

    //! process ---------------------------------
    string result = army->str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=124,EXP=237,unitList=UnitList[count_vehicle=4;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=2,position=(2,2)],Infantry[infantryType=SNIPER,quantity=5,weight=1,position=(2,1)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)],Vehicle[vehicleType=TRUCK,quantity=4,weight=2,position=(1,2)],Vehicle[vehicleType=MORTAR,quantity=5,weight=2,position=(3,1)],Vehicle[vehicleType=ARTILLERY,quantity=2,weight=3,position=(3,3)]]]";
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

// 1 1 2 3 5 8 13 21 34 55 89 144 233
bool UNIT_TEST_Task2::Task208()
{
    string name = "Task208";
    //! data ------------------------------------
    // Công thức Vehicle: score = (typeValue ∗ 304 + quantity ∗ weight) / 30
    Vehicle v1(9, 1, Position(1,1), APC); // attackScore = (4*304 + 9*1)/30 = 40.8(3) -> ceil = 41

    // Công thức Infantry: score = typeValue ∗ 56 + quantity ∗ weight
    Infantry i1(4, 4, Position(1,2), ANTIAIRCRAFTSQUAD); 
    /*
        attackScore = 1*56 + 4*4 = 72
        Số cá nhân: 7 + 2 + 1 + 9 + 7 + 5 = 31, 3 + 1 = 4
        Số cá nhân không thoả điều kiện cập nhật => attackScore = 72
    */
    
    Infantry i2(10, 2, Position(1,3), MORTARSQUAD);
    /*
        attackScore = 2*56 + 10*2 = 132
        Số cá nhân: 1 + 3 + 2 + 1 + 9 + 7 + 5 = 28, 2 + 8 = 10, 1 + 0 = 1
        Số cá nhân thoả điều kiện cập nhật (1 < 3) => quantity giảm 10\% => quantity = 90\% quantity = 10 * 90\% = 9 => ceil = 9
        Cập nhật attackScore: attackScore = 2*56 + 10*2 = 130
    */

    Unit* unitArray1[3];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy208");
    /*
    Khởi tạo Liberation Army từ unitList có 3 phần tử với AttackScore lần lượt là:
    LF = 41
    EXP = 72 + 130 = 202
    */
    Vehicle v2(5, 3, Position(3,1), MORTAR);// attackScore = (1*304 + 5*3)/30 = 10.6(3) -> ceil = 11
    
    Infantry i3(3, 5, Position(3,2), SNIPER);
    /*
        attackScore = 0*56 + 3*5 = 15
        Số cá nhân: 1 + 5 + 1 + 9 + 7 + 5 = 28, 2 + 8 = 1=, 1 + 0 = 1
        Số cá nhân thoả điều kiện cập nhật (1 < 3) => quantity giảm 10\% => quantity = 90\% quantity = 3 * 90\% = 2.7 => ceil = 3
        Cập nhật attackScore = 0*56 + 3*5 = 15
    */
    
    Infantry i4(1, 1, Position(3,3), SPECIALFORCES);
    /*
        attackScore = 4 * 56 + 1 * 1 = 225
        Đơn vị SPECIALFORCES và weight = 1 là số chính phương => chỉ số xét = 225 + 75 = 300
        Số cá nhân: 3 + 0 + 0 + 1 + 9 + 7 + 5 = 25, 2 + 5 = 7
        Số cá nhân không thoả điều kiện cập nhật ( 7 không bé hơn 7) => attackScore = 225
    */

    Unit* unitArray2[3];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    unitArray2[2] = &i4;
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy208");
    /*
    Khởi tạo ARVN Army từ unitList có 3 phần tử với AttackScore lần lượt là:
    LF = 11
    EXP = 15 + 225 = 240
    */
    //! process ---------------------------------
    attacker->fight(enemy, false);
    // Liberation Army Tấn công
    // LF = LF * 1.5 = 41 * 1.5 = 61.6 -> ceil = 62
    // EXP = EXP * 1.5 = 202 * 1.5 = 303
    // Tìm được tổ hợp A của Liber > tổng attackScore của ARVN
    // Không tim thấy tổ hợp B, tuy nhiên EXP sau khi nhân 1.5 > EXP của ARVN => Giao tranh thắng
    // B1: Xoá tổ hợp trong A: Xoá tổ hợp A và toàn bộ Infantry => unitList của Liber đang rỗng
    // B2: chèn các đơn vị từ enemy vào: => UnitList của Liber bao gồm: TANK, SNIPER và SPECIALFORCE. UnitList của ARVN là rỗng
    //  B3: cập nhật 2 quân: 
    //     Liber: LF = 11, EXP = 240
    //     ARVN: LF = 0, EXP = 0
    string result = attacker->str() + "\n" + enemy->str();

    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=11,EXP=240,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(3,3)],Infantry[infantryType=SNIPER,quantity=3,weight=5,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=5,weight=3,position=(3,1)]]]\n"
                    "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0]]";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task209()
{
    string name = "Task209";
    //! data ------------------------------------
    Vehicle v1(3, 10, Position(1,1), TRUCK);    
    Infantry i1(4, 12, Position(1,2), SNIPER);   

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy209");
    
    Vehicle v2(3, 3, Position(3,1), TANK);  
    Infantry i3(3, 30, Position(3,2), SNIPER); 

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy209");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 1\nNew_EXP = 44";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task201()
{
    string name = "Task201";
    //! data ------------------------------------
    Vehicle tankOfLiber(5, 2, Position(1, 2), TANK);
    Vehicle truckOfLiber(3, 1, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(5, 2, Position(1, 1), SNIPER);

    Unit** unitArrayOfLiber = new Unit*[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;
    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "TestArmy201");

    //! process ---------------------------------
    string result = to_string(liberationArmy->getLF()) + "\n" + to_string(liberationArmy->getEXP());

    //! expect ----------------------------------
    string expect = "63\n10"; 

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete liberationArmy;
    delete[] unitArrayOfLiber;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task202()
{
    string name = "Task202";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1, 1), TANK);
    Infantry i1(2, 1, Position(1, 2), SNIPER);
    
    Unit** unitArray = new Unit*[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    LiberationArmy* army = new LiberationArmy(unitArray, 2, "TestArmy202");
    Army* copy = army;

    //! process ---------------------------------
    string result = to_string(copy->getLF()) + "\n" + to_string(copy->getEXP());

    //! expect ----------------------------------
    string expect = "61\n2"; 

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task203()
{
    string name = "Task203";
    //! data ------------------------------------
    Infantry i1(300, 1, Position(1,1), SNIPER);     
    Infantry i2(250, 1, Position(1,2), REGULARINFANTRY);  
    Infantry i3(200, 1, Position(1,3), ENGINEER);   

    Unit** unitArray = new Unit*[3];
    unitArray[0] = &i1;
    unitArray[1] = &i2;
    unitArray[2] = &i3;
    LiberationArmy army = LiberationArmy(unitArray, 3, "TestArmy206");
    Army* copy1 = &army;
    Army** copy2 = &copy1;

    //! process ---------------------------------
    string result = to_string((*copy2)->getLF()) + "\n" + to_string((*copy2)->getEXP());
    //! expect ----------------------------------
    string expect = "0\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task211()
{
    string name = "Task211";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);         
    Infantry i1(57, 4, Position(1,2), ENGINEER);    

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy211");
    
    Vehicle v2(3, 3, Position(3,1), TANK);              
    Infantry i2(62, 1, Position(3,2), REGULARINFANTRY);       

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy211");

    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, true);
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";

    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=61,EXP=396,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ENGINEER,quantity=57,weight=4,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]]]\n"
"ARVN[LF=62,EXP=342,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=62,weight=1,position=(3,2)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,1)]]]\n"
"* After fight *\n"
"LiberationArmy[LF=80,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ENGINEER,quantity=57,weight=4,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]]]\n"
"ARVN[LF=62,EXP=342,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=62,weight=1,position=(3,2)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,1)]]]\n";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task212()
{
    string name = "Task212";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);      
    Infantry i1(4, 1, Position(1,2), SNIPER);       
    Infantry i2(3, 1, Position(1,3), SPECIALFORCES);   

    Unit* unitArray1[3];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy212");
    
    Vehicle v2(3, 3, Position(3,1), TANK);             
    Infantry i3(2, 1, Position(3,2), SNIPER);            
    Infantry i4(2, 1, Position(3,3), ANTIAIRCRAFTSQUAD);    
    Infantry i5(2, 1, Position(3,4), MORTARSQUAD);      

    Unit* unitArray2[4];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    unitArray2[2] = &i4;
    unitArray2[3] = &i5;
    Army* enemy = new ARVN(unitArray2, 4, "EnemyArmy212");
    
    //! process ---------------------------------

    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 62\nNew_EXP = 181";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task213()
{
    string name = "Task213";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);          
    Infantry i1(10, 1, Position(1,2), SNIPER);     

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy213");
    
    Vehicle v2(3, 3, Position(3,1), TANK);           
    Infantry i2(3, 3, Position(3,2), SNIPER);      

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy213");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 62\nNew_EXP = 9";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task214()
{
    string name = "Task214";
    //! data ------------------------------------
    Vehicle v1(2, 1, Position(1,1), TANK);       
    Vehicle v2(1, 1, Position(1,2), APC);                   
    Infantry i1(3, 1, Position(2,1), ANTIAIRCRAFTSQUAD); 
    Infantry i2(1, 1, Position(2,2), SPECIALFORCES);   

    Unit* unitArray1[4];
    unitArray1[0] = &v1;
    unitArray1[1] = &v2;
    unitArray1[2] = &i1;
    unitArray1[3] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy214");
    
    Vehicle v3(1, 1, Position(3,1), ARTILLERY);     
    Infantry i3(1, 1, Position(3,2), SNIPER);           

    Unit* unitArray2[2];
    unitArray2[0] = &v3;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy214");
    
    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, false);
    
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    
    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=102,EXP=285,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(2,2)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=4,weight=1,position=(2,1)],Vehicle[vehicleType=TANK,quantity=2,weight=1,position=(1,1)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)]]]\n"
"ARVN[LF=51,EXP=1,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=1,weight=1,position=(3,2)],Vehicle[vehicleType=ARTILLERY,quantity=1,weight=1,position=(3,1)]]]\n"
"* After fight *\n"
"LiberationArmy[LF=92,EXP=226,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=SNIPER,quantity=1,weight=1,position=(3,2)],Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(2,2)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)],Vehicle[vehicleType=ARTILLERY,quantity=1,weight=1,position=(3,1)]]]\n"
"ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0]]\n";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task215()
{
    string name = "Task215";
    //! data ------------------------------------

    Vehicle v1(112, 4, Position(1,1), TANK);   
    Infantry i1(3, 1, Position(1,2), ENGINEER);  

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy215");
    
    Vehicle v2(3, 3, Position(3,1), TANK);          
    Infantry i2(3, 1, Position(3,2), REGULARINFANTRY);     

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy215");

    //! process ---------------------------------
    attacker->fight(enemy, true);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------

    string expect = "New_LF = 75\nNew_EXP = 171";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task210()
{
    string name = "Task210";
    //! data ------------------------------------
    Vehicle v1(3, 5, Position(1,1), TANK);           
    Vehicle v2(1, 1, Position(1,2), APC);                
    Infantry i1(4, 1, Position(2,1), ANTIAIRCRAFTSQUAD);    
    Infantry i2(3, 1, Position(2,2), SPECIALFORCES);         

    Unit* unitArray1[4];
    unitArray1[0] = &v1;
    unitArray1[1] = &v2;
    unitArray1[3] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy210");
    
    Vehicle v3(3, 1, Position(3,1), ARTILLERY);     
    Vehicle v4(3, 2, Position(3,3), TRUCK);         
    Infantry i3(3, 2, Position(3,2), SNIPER);          


    Unit* unitArray2[3];
    unitArray2[0] = &v3;
    unitArray2[1] = &v4;
    unitArray2[2] = &i3;
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy210");
    
    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, false);
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    
    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=103,EXP=288,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=4,weight=1,position=(2,1)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(2,2)],Vehicle[vehicleType=TANK,quantity=3,weight=5,position=(1,1)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)]]]\n"
"ARVN[LF=52,EXP=6,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=3,weight=2,position=(3,2)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=1,position=(3,1)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,3)]]]\n"
"* After fight *\n"
"LiberationArmy[LF=93,EXP=234,unitList=UnitList[count_vehicle=3;count_infantry=2;Infantry[infantryType=SNIPER,quantity=3,weight=2,position=(3,2)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(2,2)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=1,position=(3,1)]]]\n"
"ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0]]\n";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
