#include "../unit_test_Task4.hpp"

bool UNIT_TEST_Task4::Task4204()
{
    string name = "Task204";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), ANTIAIRCRAFT);
    Vehicle v2(5, 2, Position(1,2), MORTAR);
    Infantry i1(2, 1, Position(2,1), SNIPER);
    Infantry i2(3, 1, Position(2,2), SPECIALFORCES);
    Infantry i3(4, 1, Position(2,3), REGULARINFANTRY);
    
    Unit* unitArray[5];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &i1;
    unitArray[3] = &i2;
    unitArray[4] = &i3;
    LiberationArmy* army = new LiberationArmy(unitArray, 5, "TestArmy207",0);

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());
    //! expect ----------------------------------
    string expect = "32\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4205()
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

    Unit* unitArray[12];
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

    LiberationArmy* army = new LiberationArmy(unitArray, 12, "TestArmy205",0);

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());

    //! expect ----------------------------------
    string expect = "288\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4206()
{
    string name = "Task206";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);
    
    Unit* unitArray[1];
    unitArray[0] = &v1;
    
    LiberationArmy army = LiberationArmy(unitArray, 1, "TestArmy206",0);
    Army* copy = &army;

    //! process ---------------------------------
    string result = army.str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=61,EXP=0,unitList=UnitList[count_vehicle=1;count_infantry=0;Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]],battleField=]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    // delete army;
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4207()
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
    
    LiberationArmy* army = new LiberationArmy(unitArray, 7, "TestArmy207",0);

    //! process ---------------------------------
    string result = army->str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=124,EXP=237,unitList=UnitList[count_vehicle=4;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=2,position=(2,2)],Infantry[infantryType=SNIPER,quantity=6,weight=1,position=(2,1)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)],Vehicle[vehicleType=TRUCK,quantity=4,weight=2,position=(1,2)],Vehicle[vehicleType=MORTAR,quantity=5,weight=2,position=(3,1)],Vehicle[vehicleType=ARTILLERY,quantity=2,weight=3,position=(3,3)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete army;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

// 1 1 2 3 5 8 13 21 34 55 89 144 233
bool UNIT_TEST_Task4::Task4208()
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
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy208",0);
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
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy208",0);
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
    string expect = "LiberationArmy[LF=11,EXP=240,unitList=UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(3,3)],Infantry[infantryType=SNIPER,quantity=3,weight=5,position=(3,2)],Vehicle[vehicleType=MORTAR,quantity=5,weight=3,position=(3,1)]],battleField=]\n"
                    "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4209()
{
    string name = "Task209";
    
    //! data ------------------------------------
    Vehicle v1(3, 10, Position(1,1), TRUCK);    
    Infantry i1(4, 12, Position(1,2), SNIPER);   

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy209",0);
    
    Vehicle v2(3, 3, Position(3,1), TANK);  
    Infantry i3(3, 30, Position(3,2), SNIPER); 

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy209",0);
    
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

bool UNIT_TEST_Task4::Task4201()
{
    string name = "Task201";
    
    //! data ------------------------------------
    Vehicle tankOfLiber(5, 2, Position(1, 2), TANK);
    Vehicle truckOfLiber(3, 1, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(5, 2, Position(1, 1), SNIPER);

    Unit* unitArrayOfLiber[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;
    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "TestArmy201",0);

    //! process ---------------------------------
    string result = to_string(liberationArmy->getLF()) + "\n" + to_string(liberationArmy->getEXP());

    //! expect ----------------------------------
    string expect = "63\n10"; 

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete liberationArmy;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4202()
{
    string name = "Task202";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1, 1), TANK);
    Infantry i1(2, 1, Position(1, 2), SNIPER);
    
    Unit* unitArray[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    LiberationArmy* army = new LiberationArmy(unitArray, 2, "TestArmy202",0);
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

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4203()
{
    string name = "Task203";
    
    //! data ------------------------------------
    Infantry i1(300, 1, Position(1,1), SNIPER);     
    Infantry i2(250, 1, Position(1,2), REGULARINFANTRY);  
    Infantry i3(200, 1, Position(1,3), ENGINEER);   

    Unit* unitArray[3];
    unitArray[0] = &i1;
    unitArray[1] = &i2;
    unitArray[2] = &i3;
    LiberationArmy army = LiberationArmy(unitArray, 3, "TestArmy206",0);
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

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4211()
{
    string name = "Task211";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);         
    Infantry i1(57, 4, Position(1,2), ENGINEER);    

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy211",0);
    
    Vehicle v2(3, 3, Position(3,1), TANK);              
    Infantry i2(62, 1, Position(3,2), REGULARINFANTRY);       

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy211",0);

    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, true);
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";

    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=61,EXP=396,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ENGINEER,quantity=57,weight=4,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]],battleField=]\n"
"ARVN[LF=62,EXP=342,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=62,weight=1,position=(3,2)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,1)]],battleField=]\n"
"* After fight *\n"
"LiberationArmy[LF=80,EXP=500,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ENGINEER,quantity=57,weight=4,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]],battleField=]\n"
"ARVN[LF=62,EXP=342,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=62,weight=1,position=(3,2)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,1)]],battleField=]\n";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4212()
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
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy212",0);
    
    Vehicle v2(3, 3, Position(3,1), TANK);             
    Infantry i3(2, 1, Position(3,2), SNIPER);            
    Infantry i4(2, 1, Position(3,3), ANTIAIRCRAFTSQUAD);    
    Infantry i5(2, 1, Position(3,4), MORTARSQUAD);      

    Unit* unitArray2[4];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    unitArray2[2] = &i4;
    unitArray2[3] = &i5;
    Army* enemy = new ARVN(unitArray2, 4, "EnemyArmy212",0);
    
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

bool UNIT_TEST_Task4::Task4213()
{
    string name = "Task213";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);          
    Infantry i1(10, 1, Position(1,2), SNIPER);     

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy213",0);
    
    Vehicle v2(3, 3, Position(3,1), TANK);           
    Infantry i2(3, 3, Position(3,2), SNIPER);      

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy213",0);
    
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

bool UNIT_TEST_Task4::Task4214()
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
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy214",0);
    
    Vehicle v3(1, 1, Position(3,1), ARTILLERY);     
    Infantry i3(1, 1, Position(3,2), SNIPER);           

    Unit* unitArray2[2];
    unitArray2[0] = &v3;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy214",0);
    
    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, false);
    
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    
    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=102,EXP=285,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(2,2)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=4,weight=1,position=(2,1)],Vehicle[vehicleType=TANK,quantity=2,weight=1,position=(1,1)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)]],battleField=]\n"
"ARVN[LF=51,EXP=1,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=1,weight=1,position=(3,2)],Vehicle[vehicleType=ARTILLERY,quantity=1,weight=1,position=(3,1)]],battleField=]\n"
"* After fight *\n"
"LiberationArmy[LF=92,EXP=226,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=SNIPER,quantity=1,weight=1,position=(3,2)],Infantry[infantryType=SPECIALFORCES,quantity=1,weight=1,position=(2,2)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)],Vehicle[vehicleType=ARTILLERY,quantity=1,weight=1,position=(3,1)]],battleField=]\n"
"ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4215()
{
    string name = "Task215";
    
    //! data ------------------------------------

    Vehicle v1(112, 4, Position(1,1), TANK);   
    Infantry i1(3, 1, Position(1,2), ENGINEER);  

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy215",0);
    
    Vehicle v2(3, 3, Position(3,1), TANK);          
    Infantry i2(3, 1, Position(3,2), REGULARINFANTRY);     

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy215",0);

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

bool UNIT_TEST_Task4::Task4210()
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
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy210",0);
    
    Vehicle v3(3, 1, Position(3,1), ARTILLERY);     
    Vehicle v4(3, 2, Position(3,3), TRUCK);         
    Infantry i3(3, 2, Position(3,2), SNIPER);          


    Unit* unitArray2[3];
    unitArray2[0] = &v3;
    unitArray2[1] = &v4;
    unitArray2[2] = &i3;
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy210",0);
    
    //! process ---------------------------------
    string result = "* Before fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    attacker->fight(enemy, false);
    result += "* After fight *\n" + attacker->str() + "\n" + enemy->str() + "\n";
    
    //! expect ----------------------------------
    string expect = "* Before fight *\n"
"LiberationArmy[LF=103,EXP=288,unitList=UnitList[count_vehicle=2;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=4,weight=1,position=(2,1)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(2,2)],Vehicle[vehicleType=TANK,quantity=3,weight=5,position=(1,1)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)]],battleField=]\n"
"ARVN[LF=52,EXP=6,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=3,weight=2,position=(3,2)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=1,position=(3,1)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,3)]],battleField=]\n"
"* After fight *\n"
"LiberationArmy[LF=93,EXP=234,unitList=UnitList[count_vehicle=3;count_infantry=2;Infantry[infantryType=SNIPER,quantity=3,weight=2,position=(3,2)],Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(2,2)],Vehicle[vehicleType=APC,quantity=1,weight=1,position=(1,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,3)],Vehicle[vehicleType=ARTILLERY,quantity=3,weight=1,position=(3,1)]],battleField=]\n"
"ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Task4::Task4216()
{
    string name = "Task216";
    
    //! data ------------------------------------
    Vehicle tankOfArvn(5, 2, Position(1, 2), TANK);      // getAttackScore() = safeCeil((5 * 2 + 6 * 304) / 30) = safeCeil(1834 / 30) = 62
    Vehicle truckOfArvn(3, 1, Position(2, 2), TRUCK);    // getAttackScore() = safeCeil((3 * 1 + 0 * 304) / 30) = safeCeil(3 / 30) = 1
    Infantry sniperOfArvn(5, 2, Position(1, 1), SNIPER); // getAttackScore() = 5 * 2 + 0 = 10

    Unit *unitArrayOfArvn[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &truckOfArvn;
    unitArrayOfArvn[2] = &sniperOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy216",0);

    //! process ---------------------------------
    string result = "LF=" + to_string(arvn->getLF()) + "\nEXP=" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    string expect = "LF=63\nEXP=10";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4217()
{
    string name = "Task217";
    
    //! data ------------------------------------
    Vehicle tankOfArvn(8, 3, Position(3, 3), TANK);                 // getAttackScore() = safeCeil((8 * 3 + 6 * 304) / 30) = 62
    Vehicle mortarOfArvn(4, 2, Position(4, 4), MORTAR);             // getAttackScore() = safeCeil((4 * 2 + 1 * 304) / 30) = 11
    Infantry riflemanOfArvn(6, 3, Position(2, 2), REGULARINFANTRY); // getAttackScore() = (5 * 56) + (6 * 3) = 298

    Unit *unitArrayOfArvn[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &mortarOfArvn;
    unitArrayOfArvn[2] = &riflemanOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy217",0);

    //! process ---------------------------------
    string result = "LF=" + to_string(arvn->getLF()) + "\nEXP=" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    string expect = "LF=73\nEXP=298";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4218()
{
    string name = "Task218";
    
    //! data ------------------------------------
    Vehicle truckOfArvn(10, 5, Position(5, 5), TRUCK);                // getAttackScore() = safeCeil((10 * 5 + 0 * 304) / 30) = safeCeil(50 / 30) = 2
    Vehicle armoredCarOfArvn(5, 2, Position(6, 5), ARMOREDCAR);       // getAttackScore() = safeCeil((5 * 2 + 3 * 304) / 30) = safeCeil(922 / 30) = 31
    Infantry specialForceOfArvn(3, 1, Position(5, 4), SPECIALFORCES); // Logic đặc biệt áp dụng cho SPECIALFORCES

    Unit *unitArrayOfArvn[3];
    unitArrayOfArvn[0] = &truckOfArvn;
    unitArrayOfArvn[1] = &armoredCarOfArvn;
    unitArrayOfArvn[2] = &specialForceOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy218",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=33,EXP=228,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=4,weight=1,position=(5,4)],Vehicle[vehicleType=TRUCK,quantity=10,weight=5,position=(5,5)],Vehicle[vehicleType=ARMOREDCAR,quantity=5,weight=2,position=(6,5)]],battleField=]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4219()
{
    string name = "Task219";
    
    //! data ------------------------------------
    Vehicle artilleryOfArvn(6, 4, Position(7, 7), ARTILLERY);       // getAttackScore() = ceil((6 * 4 + 5 * 304) / 30) = ceil(1544 / 30) = 52
    Vehicle antiAircraftOfArvn(4, 3, Position(8, 8), ANTIAIRCRAFT); // getAttackScore() = ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    Infantry scoutOfArvn(3, 2, Position(7, 6), SPECIALFORCES);      // getAttackScore() = (4 * 56) + (4 * 2) = 232

    Unit *unitArrayOfArvn[3];
    unitArrayOfArvn[0] = &artilleryOfArvn;
    unitArrayOfArvn[1] = &antiAircraftOfArvn;
    unitArrayOfArvn[2] = &scoutOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy204",0);

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

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4220()
{
    string name = "Task220";
    
    //! data ------------------------------------
    Vehicle tankOfArvn(7, 3, Position(0, 1), TANK);            // getAttackScore() = ceil((7 * 3 + 6 * 304) / 30) = ceil(1854 / 30) = 62
    Vehicle truckOfArvn(5, 2, Position(2, 3), TRUCK);          // getAttackScore() = ceil((5 * 2 + 0 * 304) / 30) = ceil(10 / 30) = 1
    Infantry sniperOfArvn(10, 4, Position(1, 2), MORTARSQUAD); // getAttackScore() = (2 * 56) + (10 * 4) = 112 + 40 = 152

    Unit *unitArrayOfArvn[3];
    unitArrayOfArvn[0] = &tankOfArvn;
    unitArrayOfArvn[1] = &truckOfArvn;
    unitArrayOfArvn[2] = &sniperOfArvn;
    ARVN *arvn = new ARVN(unitArrayOfArvn, 3, "TestArmy205",0);

    //! process ---------------------------------
    string result = to_string(arvn->getLF()) + "\n" + to_string(arvn->getEXP());

    //! expect ----------------------------------
    string expect = "63\n152";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4221()
{
    string name = "Task221";
    
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1, 1), TANK);    // getAttackScore() = ceil((3 * 1 + 6 * 304) / 30) = ceil(1824 / 30) = 61
    Infantry i1(2, 1, Position(1, 2), SNIPER); // getAttackScore() = (0 * 56) + (2 * 1) = 2

    Unit *unitArray[2];
    unitArray[0] = &i1;
    unitArray[1] = &v1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy221",0);

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=61,EXP=2,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=2,weight=1,position=(1,2)],Vehicle[vehicleType=TANK,quantity=3,weight=1,position=(1,1)]],battleField=]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4222()
{
    string name = "Task222";
    
    //! data ------------------------------------
    Vehicle v1(5, 3, Position(1, 1), TANK);             // getAttackScore() = ceil((6 * 304 + 5 * 3) / 30) = ceil(1833 / 30) = 62
    Infantry i1(3, 2, Position(2, 3), REGULARINFANTRY); // getAttackScore() = (5 * 56) + (3 * 2) = 280 + 6 = 286

    Unit *unitArray[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy222",0);

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=62,EXP=286,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=REGULARINFANTRY,quantity=3,weight=2,position=(2,3)],Vehicle[vehicleType=TANK,quantity=5,weight=3,position=(1,1)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4223()
{
    string name = "Task223";
    
    //! data ------------------------------------
    Vehicle v1(4, 2, Position(1, 1), ARTILLERY);          // getAttackScore() = ceil((4 * 2 + 5 * 304) / 30) = ceil(1528 / 30) = 51
    Infantry i1(3, 3, Position(3, 3), ANTIAIRCRAFTSQUAD); // getAttackScore() = (1 * 56) + (3 * 3) = 56 + 9 = 65

    Unit *unitArray[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy223",0);

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=51,EXP=65,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=3,weight=3,position=(3,3)],Vehicle[vehicleType=ARTILLERY,quantity=4,weight=2,position=(1,1)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4224()
{
    string name = "Task224";
    
    //! data ------------------------------------
    Vehicle v1(2, 4, Position(2, 2), TANK);           // getAttackScore() = ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    Infantry i1(6, 5, Position(3, 3), SPECIALFORCES); // getAttackScore() = (4 * 56) + (6 * 5) = 224 + 30 = 254

    Unit *unitArray[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    ARVN *army = new ARVN(unitArray, 2, "TestArmy224",0);

    //! process ---------------------------------
    string result = army->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=62,EXP=254,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=6,weight=5,position=(3,3)],Vehicle[vehicleType=TANK,quantity=2,weight=4,position=(2,2)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4225()
{
    string name = "Task225";
    
    //! data ------------------------------------
    Vehicle v1(2, 4, Position(2, 2), TANK);           // getAttackScore() = ceil((6 * 304 + 2 * 4) / 30) = ceil(1832 / 30) = 62
    Vehicle v2(3, 2, Position(3, 1), TRUCK);          // getAttackScore() = ceil((3 * 2 + 0 * 304) / 30) = ceil(6 / 30) = 1
    Vehicle v3(4, 3, Position(1, 1), ARMOREDCAR);     // getAttackScore() = ceil((4 * 3 + 2 * 304) / 30) = ceil(620 / 30) = 21
    Infantry i1(6, 5, Position(3, 3), SPECIALFORCES); // getAttackScore() = (4 * 56) + (6 * 5) = 224 + 30 = 254

    Unit *unitArray[4];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &v3;
    unitArray[3] = &i1;
    ARVN *army = new ARVN(unitArray, 4, "TestArmy225",0);

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
    string expect = "ARVN[LF=94,EXP=254,unitList=UnitList[count_vehicle=3;count_infantry=1;Infantry[infantryType=SPECIALFORCES,quantity=6,weight=5,position=(3,3)],Vehicle[vehicleType=TANK,quantity=2,weight=4,position=(2,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=2,position=(3,1)],Vehicle[vehicleType=ARMOREDCAR,quantity=4,weight=3,position=(1,1)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4228()
{
    string name = "Task228";
    
    //! data ------------------------------------
    // Không có đơn vị nào trong ARVN
    Unit **unitArrayOfAr = nullptr; // Mảng trống
    ARVN *arvn = new ARVN(unitArrayOfAr, 0, "EmptyARVN",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    // LF = 0, EXP = 0, không có đơn vị nào
    string expect = "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4229()
{
    string name = "Task229";
    
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(4, 2, Position(3, 3), TANK);      // getAttackScore() = ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(2, 1, Position(4, 4), TRUCK);    // getAttackScore() = ceil((0 * 304 + 2 * 1) / 30) = ceil(2 / 30) = 1
    Infantry sniperOfAr(6, 2, Position(5, 5), SNIPER); // getAttackScore() = (0 * 56) + (6 * 2) = 12

    Unit *unitArrayOfAr[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=63,EXP=12,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=6,weight=2,position=(5,5)],Vehicle[vehicleType=TANK,quantity=4,weight=2,position=(3,3)],Vehicle[vehicleType=TRUCK,quantity=2,weight=1,position=(4,4)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4230()
{
    string name = "Task230";
    
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(3, 3, Position(3, 3), TANK);      // getAttackScore() = ceil((6 * 304 + 3 * 3) / 30) = ceil(1839 / 30) = 62
    Vehicle truckOfAr(2, 2, Position(4, 4), TRUCK);    // getAttackScore() = ceil((0 * 304 + 2 * 2) / 30) = ceil(4 / 30) = 1
    Infantry sniperOfAr(4, 2, Position(5, 5), SNIPER); // getAttackScore() = (0 * 56) + (4 * 2) = 8

    Unit *unitArrayOfAr[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=63,EXP=8,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=4,weight=2,position=(5,5)],Vehicle[vehicleType=TANK,quantity=3,weight=3,position=(3,3)],Vehicle[vehicleType=TRUCK,quantity=2,weight=2,position=(4,4)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4226()
{
    string name = "Task226";
    
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(5, 2, Position(3, 2), TANK);      // getAttackScore() = ceil((6 * 304 + 5 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(3, 1, Position(3, 1), TRUCK);    // getAttackScore() = ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    Infantry sniperOfAr(5, 2, Position(3, 3), SNIPER); // getAttackScore() = (0 * 56) + (5 * 2) = 10

    Unit *unitArrayOfAr[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=63,EXP=10,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=5,weight=2,position=(3,3)],Vehicle[vehicleType=TANK,quantity=5,weight=2,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=1,position=(3,1)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4227()
{
    string name = "Task227";
    
    //! data ------------------------------------
    // Các đơn vị cho ARVN
    Vehicle tankOfAr(4, 2, Position(3, 2), TANK);      // getAttackScore() = ceil((6 * 304 + 4 * 2) / 30) = ceil(1832 / 30) = 62
    Vehicle truckOfAr(3, 1, Position(3, 1), TRUCK);    // getAttackScore() = ceil((0 * 304 + 3 * 1) / 30) = ceil(3 / 30) = 1
    Infantry sniperOfAr(5, 2, Position(3, 3), SNIPER); // getAttackScore() = (0 * 56) + (5 * 2) = 10

    Unit *unitArrayOfAr[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN",0);

    //! process ---------------------------------
    string result = arvn->str();

    //! expect ----------------------------------
    string expect = "ARVN[LF=63,EXP=10,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=5,weight=2,position=(3,3)],Vehicle[vehicleType=TANK,quantity=4,weight=2,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=3,weight=1,position=(3,1)]],battleField=]";
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete arvn;

    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Task4::Task4231() {
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

bool UNIT_TEST_Task4::Task4232() {
    string name = "Task232";
    
    
    //! data ------------------------------------
    UnitList list(1);
    Infantry soldier(5, 10, Position(0, 0), REGULARINFANTRY);
    Vehicle tank(2, 50, Position(1, 1), TANK);
    list.insert(&soldier);
    bool result = list.insert(&tank);
    
    //! expect ----------------------------------
    string expect = "0";
    
    //! output ----------------------------------
    stringstream output;
    output << result;


    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4233() {
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

bool UNIT_TEST_Task4::Task4234() {
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

bool UNIT_TEST_Task4::Task4235() {
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

bool UNIT_TEST_Task4::Task4236() {
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

bool UNIT_TEST_Task4::Task4237() {
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

bool UNIT_TEST_Task4::Task4238() {
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

bool UNIT_TEST_Task4::Task4239() {
    string name = "Task239";
    
    
    //! data ------------------------------------
    UnitList list(6);
    Unit* unit[6];
    for (int i = 0; i < 6; ++i) {
        unit[i] = new Infantry(3, 10, Position(i, i), REGULARINFANTRY);
        list.insert(unit[i]);
    }
    Vehicle ist = Vehicle(1, 50, Position(4, 4), TANK);
    bool result = list.insert(&ist);
    
    //! expect ----------------------------------
    string expect = "1";
    
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! delete ----------------------------------
    for (int i = 0; i < 6; ++i) {
        delete unit[i];
    }

    
       return printResult(to_string(result), expect, name);
}

bool UNIT_TEST_Task4::Task4240() {
    string name = "Task240";
    

    //! data ------------------------------------
    UnitList ul(1);
    bool allInserted = true;
    for (int i = 0; i < 12; ++i) {
        Infantry inf = Infantry(1, 1, Position(0,0), REGULARINFANTRY);
        if (!ul.insert(&inf)) {
            allInserted = false;
            break;
        }
    }
    Infantry inf13 = Infantry(1, 1, Position(0,0), REGULARINFANTRY);
    bool insert13 = ul.insert(&inf13);
    bool result = allInserted && insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;


    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4241() {
    string name = "Task241";
    

    //! data ------------------------------------
    UnitList ul(5);
    bool allInserted = true;
    Vehicle* listveh[12];
    for (int i = 0; i < 12; ++i) {
        listveh[i] = new Vehicle(1, 1, Position(), TRUCK);
        if (!ul.insert(listveh[i])) {
            allInserted = false;
            break;
        }
    }
    Vehicle* veh13 = new Vehicle(1, 1, Position(), TRUCK);
    bool insert13 = ul.insert(veh13);
    delete veh13;
    bool result = allInserted && insert13;

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! delete ----------------------------------


    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4242() {
    string name = "Task242";
    

    //! data ------------------------------------
    UnitList ul(5);
    bool allInserted = true;
    Vehicle* listveh[8];
    for (int i = 0; i < 8; ++i) {
        listveh[i] = new Vehicle(1, 1, Position(), (VehicleType)i);
        if (!ul.insert(listveh[i])) {
            allInserted = false;
            break;
        }
    }
    Vehicle* veh9 = new Vehicle(1, 1, Position(), APC);
    bool insert13 = ul.insert(veh9);
    delete veh9;
    bool result = !allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "1";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! delete ----------------------------------
    for (int i = 0; i < 5; ++i) {
        delete listveh[i];
    }


    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4243() {
    string name = "Task243";
    

    //! data ------------------------------------
    UnitList ul(-10);
    bool allInserted = true;
    for (int i = 0; i < 8; ++i) {
        Infantry *inf = new Infantry(1, 1, Position(), REGULARINFANTRY);
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

bool UNIT_TEST_Task4::Task4244() {
    string name = "Task244";
    

    //! data ------------------------------------
    UnitList ul(12);
    Infantry* inf = new Infantry(1, 1, Position(), ENGINEER);
    Vehicle* veh = new Vehicle(1, 1, Position(), ARTILLERY);
    ul.insert(inf);
    ul.insert(veh);
    string resultStr = ul.str();
    bool order = resultStr.find("Infantry") < resultStr.find("Vehicle",0);
    
    //! expect ----------------------------------
    string expect = "1";

    //! output ----------------------------------
    stringstream output;
    output << order;

    delete inf;
    delete veh;
    

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4245() {
    string name = "Task245";
    

    //! data ------------------------------------
    UnitList ul(1); 
    bool allInserted = true;
    Unit* unitlist[12];
    for (int i = 0; i < 7; ++i) {
        unitlist[i] = new Vehicle(1, 1, Position(), (VehicleType)i);
        if (!ul.insert(unitlist[i])) allInserted = false;
    }
    for (int i = 7; i < 12; ++i) {
        unitlist[i] = new Infantry(1, 1, Position(), (InfantryType)i);
        if (!ul.insert(unitlist[i])) allInserted = false;
    }
    Vehicle* veh13 = new Vehicle(1, 1, Position(), TANK);
    bool insert13 = ul.insert(veh13);
    delete veh13;
    bool result = !allInserted && !insert13;

    //! expect ----------------------------------
    string expect = "1";
    
    for (int i = 0; i < 12; ++i) {
        delete unitlist[i];
    }

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4246() {
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

bool UNIT_TEST_Task4::Task4247() {
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

bool UNIT_TEST_Task4::Task4248() {
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

bool UNIT_TEST_Task4::Task4249() {
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

bool UNIT_TEST_Task4::Task4250() {
    string name = "Task250";
    

    //! data ------------------------------------
    UnitList ul(12);
    Infantry inf1 = Infantry(1,1, Position(), REGULARINFANTRY);
    Infantry inf2 = Infantry(1,1, Position(), ANTIAIRCRAFTSQUAD);
    Vehicle vhc(1,1, Position(), MORTAR);

    ul.insert(&inf1);
    ul.insert(&vhc);
    ul.insert(&inf2);
    string result = ul.str();
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=1;count_infantry=2;Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=1,weight=1,position=(0,0)],Infantry[infantryType=REGULARINFANTRY,quantity=1,weight=1,position=(0,0)],Vehicle[vehicleType=MORTAR,quantity=1,weight=1,position=(0,0)]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Task4::Task4251()
{
    string name = "Task251";
    
    //! data ------------------------------------
    Vehicle tankOfLiber(20, 20, Position(1, 2), MORTAR);
    Vehicle truckOfLiber(15, 10, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(10, 20, Position(1, 1), SNIPER);

    Vehicle tankOfAr(5, 20, Position(3, 2), MORTAR);
    Vehicle truckOfAr(1, 10, Position(3, 1), TRUCK);
    Infantry sniperOfAr(7, 20, Position(3, 3), SNIPER);

    Unit* unitArrayOfLiber[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;

    Unit* unitArrayOfAr[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "LiberationArmy",0);
    ARVN* arvn = new ARVN(unitArrayOfAr, 3, "ARVN",0); 
    stringstream output;
    output << liberationArmy->str() << endl;
    output << arvn->str() << endl;   
    
    //! process ---------------------------------
    Army* enemyLiber = arvn;
    liberationArmy->fight(enemyLiber, false);
    Army* enemyAr = liberationArmy;
    arvn->fight(enemyAr, false);
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=29,EXP=200,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=10,weight=20,position=(1,1)],Vehicle[vehicleType=MORTAR,quantity=20,weight=20,position=(1,2)],Vehicle[vehicleType=TRUCK,quantity=15,weight=10,position=(2,2)]],battleField=]\n"
                    "ARVN[LF=15,EXP=180,unitList=UnitList[count_vehicle=2;count_infantry=1;Infantry[infantryType=SNIPER,quantity=9,weight=20,position=(3,3)],Vehicle[vehicleType=MORTAR,quantity=5,weight=20,position=(3,2)],Vehicle[vehicleType=TRUCK,quantity=1,weight=10,position=(3,1)]],battleField=]\n"
                    "* After the fight\n"
                    "LiberationArmy[LF=20,EXP=180,unitList=UnitList[count_vehicle=2;count_infantry=1;"
                    "Infantry[infantryType=SNIPER,quantity=9,weight=20,position=(3,3)],"
                    "Vehicle[vehicleType=TRUCK,quantity=16,weight=10,position=(2,2)],"
                    "Vehicle[vehicleType=MORTAR,quantity=5,weight=20,position=(3,2)]],battleField=]\n"
                    "ARVN[LF=0,EXP=0,unitList=UnitList[count_vehicle=0;count_infantry=0],battleField=]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    output << "* After the fight" << endl;
    output << liberationArmy->str() << endl;
    output << arvn->str() << endl;
    
    //! remove data -----------------------------
    delete liberationArmy;
    delete arvn;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4252()
{
    string name = "Task252";
    
    //! data ------------------------------------
    Vehicle tank(20, 20, Position(1, 2), TANK);
    Vehicle truck(15, 10, Position(1, 2), TRUCK);
    Vehicle mortar(10, 20, Position(1, 2), MORTAR);
    Vehicle antiaircraft(10, 20, Position(1, 2), ANTIAIRCRAFT);
    Vehicle armoredCar(10, 20, Position(1, 2), ARMOREDCAR);
    Vehicle apc(10, 20, Position(1, 2), APC);
    Vehicle artillery(10, 20, Position(1, 2), ARTILLERY);
    Infantry sniper(10, 20, Position(1, 2), SNIPER);
    Infantry antiaircraftSquad(10, 20, Position(1, 2), ANTIAIRCRAFTSQUAD);
    Infantry mortarSquad(10, 20, Position(1, 2), MORTARSQUAD);
    Infantry engineer(10, 20, Position(1, 2), ENGINEER);
    Infantry specialForces(10, 20, Position(1, 2), SPECIALFORCES);
    Infantry regularInfantry(10, 20, Position(1, 2), REGULARINFANTRY);

    Vehicle tank1(15, 10, Position(2, 2), TANK);
    Vehicle truck1(75, 100, Position(2, 2), TRUCK);
    Vehicle mortar1(10, 20, Position(2, 2), MORTAR);
    Infantry mortarSquad2(15, 15, Position(2, 2), MORTARSQUAD);
    Infantry engineer2(4, 30, Position(2, 2), ENGINEER);
    
    //! process ---------------------------------
    UnitList unitList(100);
    unitList.insert(&tank);
    unitList.insert(&truck);
    unitList.insert(&mortar);
    unitList.insert(&antiaircraft);
    unitList.insert(&engineer);
    unitList.insert(&specialForces);
    unitList.insert(&regularInfantry);
    unitList.insert(&armoredCar);
    unitList.insert(&apc);
    unitList.insert(&artillery);
    unitList.insert(&sniper);
    unitList.insert(&antiaircraftSquad);
    unitList.insert(&mortarSquad);
    unitList.insert(&tank1);
    unitList.insert(&truck1);
    unitList.insert(&mortar1);
    unitList.insert(&mortarSquad2);
    unitList.insert(&engineer2);
    
    //! expect ----------------------------------
    string expect = "UnitList[count_vehicle=7;count_infantry=6;Infantry[infantryType=MORTARSQUAD,quantity=25,weight=20,position=(1,2)],Infantry[infantryType=ANTIAIRCRAFTSQUAD,quantity=10,weight=20,position=(1,2)],Infantry[infantryType=SNIPER,quantity=10,weight=20,position=(1,2)],Infantry[infantryType=REGULARINFANTRY,quantity=10,weight=20,position=(1,2)],Infantry[infantryType=SPECIALFORCES,quantity=10,weight=20,position=(1,2)],Infantry[infantryType=ENGINEER,quantity=14,weight=30,position=(1,2)],Vehicle[vehicleType=TANK,quantity=35,weight=20,position=(1,2)],Vehicle[vehicleType=TRUCK,quantity=90,weight=100,position=(1,2)],Vehicle[vehicleType=MORTAR,quantity=20,weight=20,position=(1,2)],Vehicle[vehicleType=ANTIAIRCRAFT,quantity=10,weight=20,position=(1,2)],Vehicle[vehicleType=ARMOREDCAR,quantity=10,weight=20,position=(1,2)],Vehicle[vehicleType=APC,quantity=10,weight=20,position=(1,2)],Vehicle[vehicleType=ARTILLERY,quantity=10,weight=20,position=(1,2)]]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    stringstream output;
    output << unitList.str() << endl;
    
    //! remove data -----------------------------
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task4::Task4253()
{
    string name = "Task253";
    
    //! data ------------------------------------
    Vehicle tankOfLiber1(20, 20, Position(1, 2), MORTAR);
    Vehicle tankOfLiber2(5, 20, Position(3, 2), MORTAR);
    Infantry sniperOfLiber1(10, 20, Position(1, 0), SNIPER);
    Infantry sniperOfLiber2(10, 20, Position(1, 1), SNIPER);
    Unit* unitArrayOfLiber8[4];
    unitArrayOfLiber8[0] = &tankOfLiber1;
    unitArrayOfLiber8[1] = &tankOfLiber2;
    unitArrayOfLiber8[2] = &sniperOfLiber1;
    unitArrayOfLiber8[3] = &sniperOfLiber2;
    LiberationArmy* liberationArmy8 = new LiberationArmy(unitArrayOfLiber8, 4, "LiberationArmy",0);
    
    //! process ---------------------------------
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[LF=38,EXP=400,unitList=UnitList[count_vehicle=1;count_infantry=1;Infantry[infantryType=SNIPER,quantity=24,weight=20,position=(1,0)],Vehicle[vehicleType=MORTAR,quantity=25,weight=20,position=(1,2)]],battleField=]\n"; // True (1) if all 12 insertions succeeded and 13th failed\n"
    
    //! output ----------------------------------
    stringstream output;
    output << liberationArmy8->str() << endl;
    
    //! remove data -----------------------------
    delete liberationArmy8;
    
    //! result ----------------------------------

    return printResult(output.str(), expect, name);
}