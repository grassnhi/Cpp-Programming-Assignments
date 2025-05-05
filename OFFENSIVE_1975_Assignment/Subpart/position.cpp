#include "position.h"

using namespace std;

// Demo + Test
void pos_demo1(){
    cout << "----- Demo 1 -----" << endl;
    Position p1(3,2);
    p1.setRow(3);
    p1.setCol(2);
    cout << p1.str() << endl;
    cout << "Row: " << p1.getRow()  << " - Col: " << p1.getCol() << endl;
}

void pos_demo2(){
    cout << "----- Demo 2 -----" << endl;
    Position p1(3, 2); 
    p1.setCol(5);
    p1.setRow(9);
    cout << p1.str() << endl;
}

void pos_demo3(){
    cout << "----- Demo 3 -----" << endl;
    Position p1("(3, 2)"); 
    cout << p1.getCol() << endl;
    p1.setCol(9);
    cout << p1.str() << endl;
}

void pos_demo4() {
    cout << "----- Demo 4 (Pointer) -----" << endl;
    Position* p = new Position(2, 3);
    cout << "Row: " << p->getRow()  << " - Col: " << p->getCol() << endl;
    p->setCol(4);
    p->setRow(5);
    cout << p->str() << endl;
    delete p; // Don't forget to free memory
}

void pos_demo5() {
    cout << "----- Demo 5 (Pointer) -----" << endl;
    Position* p = new Position("(2, 3)");
    cout << "Row: " << p->getRow()  << " - Col: " << p->getCol() << endl;
    p->setCol(4);
    p->setRow(5);
    cout << p->str() << endl;
    delete p; // Don't forget to free memory
}

void unit_demo1(){
    cout << "----- Demo 1 -----" << endl;
    Position p1(3,2);
    Test_unit u(1, 158, p1); 
    cout << "Quantity: " << u.getQuantity()  
         << " - Weight: " << u.getWeight() 
         << " - Position: (" << u.getCurrentPosition().getRow() << "," << u.getCurrentPosition().getCol() << ")" 
         << endl;
    cout << u.str() << endl;
}

void unit_demo2(){
    cout << "----- Demo 2 -----" << endl;
    Test_unit u(1, 158, Position(3,2)); 
    u.setQuantity(50);
    u.setWeight(1202);
    cout << "Quantity: " << u.getQuantity()  
         << " - Weight: " << u.getWeight() 
         << " - Position: " << u.getCurrentPosition().str() 
         << " -> Score: " << u.getAttackScore() 
         << endl;

    u.increaseQuantity(8);
    u.getCurrentPosition().setCol(345);
    u.getCurrentPosition().setRow(2003);
    cout << u.str() << "->score=" << u.getAttackScore() << endl;
}

void unit_demo3(){
    Position* p = new Position("(2, 3)");
    Test_unit u(1, 158, *p); 
    u.increaseQuantity(8);
    u.getCurrentPosition().setCol(345);
    u.getCurrentPosition().setRow(2003);
    cout << u.str() << "->score=" << u.getAttackScore() << endl;

    delete p;
}

void unit_demo4(){
    cout << "----- Demo 4 -----" << endl;
    Test_unit *u = new Test_unit(1, 158, Position("(2, 3)"));
    u->increaseQuantity(8);
    u->getCurrentPosition().setCol(345);
    u->getCurrentPosition().setRow(2003);
    cout << u->str() << "->score=" << u->getAttackScore() << endl;

    delete u;
}

void veh_demo1(){
    cout << "----- Demo 1 -----" << endl;
    Position p1(3,2);
    Vehicle v(1, 158, p1, TANK);
    cout << v.str() << " -> (" << v.getVehicleType() << " * 304 + " 
        << v.getQuantity() << " * " << v.getWeight() << ") / 30 = " << v.getAttackScore() 
        << " = " << (v.getVehicleType() * 304 + v.getQuantity() * v.getWeight()) / 30 << endl;
    v.increaseQuantity(9);
    v.setWeight(50);
    cout << v.getCurrentPosition().str() << endl;
}

void veh_demo2(){
    cout << "----- Demo 2 -----" << endl;
    Position *p1 = new Position(3,2);
    Vehicle v(1, 158, *p1, ANTIAIRCRAFT);
    cout << v.getCurrentPosition().str() << endl;

    delete p1;
}

void inf_demo1(){
    Position p1(2,2);
    Infantry i(1, 20, p1, ANTIAIRCRAFTSQUAD);
    cout << i.str() << endl;
    cout << i.getInfantryType() << endl;
    cout << i.getCurrentPosition().str() << endl;
    cout << i.getAttackScore() << endl;
}

void inf_demo2(){
    Position p1(2,2);
    Infantry i1(1, 49, p1, SPECIALFORCES);
    cout << i1.str() << endl;
    cout << i1.getAttackScore() << endl;

    Infantry i(5, 49, p1, SPECIALFORCES);
    cout << i.getAttackScore() << endl;
}

void lst_demo1(){
    Position p(0, 0);
    UnitList l(5);
    Unit* v1 = new Vehicle(5, 100, p, TANK);
    Unit* i1 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i2 = new Infantry(3, 100, Position(5, 6), SNIPER); 
    Unit* v2 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i3 = new Infantry(20, 20, Position(3, 4), SPECIALFORCES);

    l.insert(v1);
    l.insert(v2);    
    l.insert(i1);    
    l.insert(i2);
    cout << "UnitList: " << l.str() << endl;
    
    l.insert(i3);
    cout << "UnitList: " << l.str() << endl;

    cout << "vehicleType?: " << l.isContain(ARMOREDCAR) << " - " << l.isContain(TANK) << " >==< "
        << "infantryType?: " << l.isContain(SPECIALFORCES) << " - " << l.isContain(ANTIAIRCRAFTSQUAD) << endl;

    cout << l.isSpecialNumber(10) << endl;

    delete v1;
    delete v2;
    delete i1;
    delete i2;
    delete i3;
}

void lst_demo2(){
    Position p(0, 0);
    UnitList l1(5);
    Unit* v1 = new Vehicle(5, 100, p, TANK);
    Unit* i1 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i2 = new Infantry(3, 100, Position(5, 6), SNIPER); 
    Unit* v2 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i3 = new Infantry(20, 20, Position(3, 4), SPECIALFORCES);
    Unit* v3 = new Vehicle(12, 100, p, TANK);

    l1.insert(v1);
    l1.insert(v2);    
    l1.insert(i1);    
    l1.insert(i2);    
    l1.insert(i3);
    l1.insert(v3);

    cout << "UnitList1: " << l1.str() << endl;

    UnitList l2(5);
    Unit* v4 = new Vehicle(5, 100, p, TANK);
    Unit* i4 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i5 = new Infantry(3, 3, Position(5, 6), SNIPER); 
    Unit* v5 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i6 = new Infantry(20, 1, Position(3, 4), SPECIALFORCES);
    Unit* v6 = new Vehicle(12, 100, p, TANK);
    Unit* i7 = new Infantry(10, 20, Position(0, 4), ANTIAIRCRAFTSQUAD);
    Unit* i8 = new Infantry(3, 3, Position(5, 0), MORTARSQUAD); 

    l2.insert(v4);
    l2.insert(v5);    
    l2.insert(i4);    
    l2.insert(i5);    
    l2.insert(i6);
    l2.insert(v6);
    l2.insert(i7);    
    l2.insert(i8);

    cout << "UnitList2: " << l2.str() << endl;

    UnitNode* temp = l2.getHead();
    while (temp)
    {
        UnitNode* next = temp->next;  // save next first
        l1.insert(temp->unit);
        cout << " Done insert! ";
        l2.removeUnit(temp->unit);
        temp = next;
        cout << " Done remove! " << endl;
    }

    cout << "UnitList1: " << l1.str() << endl;
    cout << "UnitList2: " << l2.str() << endl;

    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete v6;

    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    delete i6;
    delete i7;
    delete i8;
}

void lst_demo3(){
    Position p(0, 0);
    UnitList l1(5);
    Unit* v1 = new Vehicle(5, 100, p, TANK);
    Unit* i1 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i2 = new Infantry(3, 100, Position(5, 6), SNIPER); 
    Unit* v2 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i3 = new Infantry(20, 20, Position(3, 4), SPECIALFORCES);
    Unit* v3 = new Vehicle(12, 100, p, TANK);

    l1.insert(v1);
    l1.insert(v2);    
    l1.insert(i1);    
    l1.insert(i2);    
    l1.insert(i3);
    l1.insert(v3);

    cout << "UnitList1: " << l1.str() << endl;

    UnitList l2(8);
    Unit* v4 = new Vehicle(5, 100, p, TANK);
    Unit* i4 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i5 = new Infantry(3, 3, Position(5, 6), SNIPER); 
    Unit* v5 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i6 = new Infantry(20, 1, Position(3, 4), SPECIALFORCES);
    Unit* v6 = new Vehicle(12, 100, p, TANK);
    Unit* i7 = new Infantry(10, 20, Position(0, 4), ANTIAIRCRAFTSQUAD);
    Unit* i8 = new Infantry(3, 3, Position(5, 0), MORTARSQUAD); 

    l2.insert(v4);
    l2.insert(v5);    
    l2.insert(i4);    
    l2.insert(i5);    
    l2.insert(i6);
    l2.insert(v6);
    l2.insert(i7);    
    l2.insert(i8);

    cout << "UnitList2: " << l2.str() << endl;

    l2.transferTo(&l1);

    cout << "UnitList1: " << l1.str() << endl;
    cout << "UnitList2: " << l2.str() << endl;

    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete v6;

    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    delete i6;
    delete i7;
    delete i8;
}

void army_demo1(){
    UnitList l1(15);
    Unit* v1 = new Vehicle(5, 100, Position(7, 0), ANTIAIRCRAFT);
    Unit* i1 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i2 = new Infantry(3, 100, Position(5, 6), SNIPER); 
    Unit* v2 = new Vehicle(4, 50, Position(7, 8), MORTAR);
    Unit* i3 = new Infantry(20, 20, Position(3, 4), SPECIALFORCES);

    l1.insert(v1);
    l1.insert(v2);    
    l1.insert(i1);    
    l1.insert(i2);    
    l1.insert(i3);

    UnitList l2(18);
    Unit* v4 = new Vehicle(5, 100, Position(0, 4), TANK);
    Unit* i4 = new Infantry(10, 20, Position(3, 4), SPECIALFORCES);
    Unit* i5 = new Infantry(3, 3, Position(5, 6), SNIPER); 
    Unit* v5 = new Vehicle(4, 50, Position(7, 8), TRUCK);
    Unit* i6 = new Infantry(20, 1, Position(3, 4), SPECIALFORCES);
    Unit* v6 = new Vehicle(12, 100, Position(3, 0), TANK);
    Unit* i7 = new Infantry(10, 20, Position(0, 4), ANTIAIRCRAFTSQUAD);
    Unit* i8 = new Infantry(3, 3, Position(5, 0), MORTARSQUAD); 

    l2.insert(v4);
    l2.insert(v5);    
    l2.insert(i4);    
    l2.insert(i5);    
    l2.insert(i6);
    l2.insert(v6);
    l2.insert(i7);    
    l2.insert(i8);

    cout << "\nList 1: ";
    UnitNode* temp = l1.getHead();
    int size1 = l1.getSize();
    Unit** unitArray1 = new Unit*[size1];
    int i = 0;
    while (temp) {
        unitArray1[i++] = temp->unit;
        temp = temp->next;
    }
    cout << "Done list 1 " << endl;

    cout << "List 2: ";
    temp = l2.getHead();
    int size2 = l2.getSize();
    Unit** unitArray2 = new Unit*[size2];
    i = 0;
    while (temp) {
        unitArray2[i++] = temp->unit;
        temp = temp->next;
    }
    cout << "Done list 2 " << endl;

    Test_army* a1 = new Test_army(unitArray1, size1, "1", nullptr);
    cout << "pass " << endl;
    Test_army* a2 = new Test_army(unitArray2, size2, "2", nullptr);
    cout << "pass " << endl;

    cout << "UnitList1: " << a1->getUnitList()->str() << endl;
    cout << "UnitList2: " << a2->getUnitList()->str() << endl;

    // a1->fight(a2, true);
    // cout << "\nUnitList1: " << a1->getUnitList()->str() << endl;
    // cout << "UnitList2: " << a2->getUnitList()->str() << endl;

    a1->fight(a2, false);
    cout << "UnitList1: " << a1->getUnitList()->str() << endl;
    cout << "UnitList2: " << a2->getUnitList()->str() << endl;

    a1->fight(a2, true);
    cout << "UnitList1: " << a1->getUnitList()->str() << endl;
    cout << "UnitList2: " << a2->getUnitList()->str() << endl;

    delete a1;
    delete a2;

    delete[] unitArray1;
    delete[] unitArray2;

    delete v1;
    delete v2;
    delete v4;
    delete v5;
    delete v6;

    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    delete i6;
    delete i7;
    delete i8;
}

void lbta_A1() {
    cout << "\nRunning lbta_A1: Attack with both A and B sets satisfied" << endl;
    Unit* units[] = {
        new Infantry(5, 50, Position(0, 0), SPECIALFORCES),
        new Infantry(5, 60, Position(0, 0), SNIPER),
        new Vehicle(3, 200, Position(0, 0), TANK),
        new Vehicle(3, 150, Position(0, 0), MORTAR)
    };
    Unit* enemyUnits[] = {
        new Infantry(2, 30, Position(0, 0), SPECIALFORCES),
        new Vehicle(2, 100, Position(0, 0), TRUCK)
    };
    LiberationArmy la(units, 4, "Attacker", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Defender", nullptr);
    cout << la.str() << endl;
    cout << enemy.str() << endl;

    la.fight(&enemy, false);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_A2() {
    cout << "\nRunning lbta_A2: Attack with only A set, LF still > enemy" << endl;
    Unit* units[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(1, 50, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(2, 50, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TRUCK)
    };
    LiberationArmy la(units, 2, "Attacker", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Defender", nullptr);
    la.fight(&enemy, false);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_A3() {
    cout << "\nRunning lbta_A3: Attack with only A set, LF <= enemy ⇒ no battle" << endl;
    Unit* units[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(1, 5, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(2, 50, Position(0, 0), SNIPER),
        new Vehicle(3, 100, Position(0, 0), TRUCK)
    };
    LiberationArmy la(units, 2, "Attacker", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Defender", nullptr);
    la.fight(&enemy, false);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_A4() {
    cout << "\nRunning lbta_A4: Attack, no A or B sets ⇒ no battle" << endl;
    Unit* units[] = {
        new Infantry(1, 1, Position(0, 0), SNIPER),
        new Vehicle(1, 1, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(10, 200, Position(0, 0), TANK)
    };
    LiberationArmy la(units, 2, "Attacker", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Defender", nullptr);
    la.fight(&enemy, false);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_D1() {
    cout << "\nRunning lbta_D1: Defense, both stats ≥ enemy ⇒ win" << endl;
    Unit* units[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(10, 200, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 20, Position(0, 0), TRUCK)
    };
    LiberationArmy la(units, 2, "Defender", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Attacker", nullptr);
    la.fight(&enemy, true);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_D2() {
    cout << "\nRunning lbta_D2: Defense, 1 stat < enemy ⇒ -10% quantity" << endl;
    Unit* units[] = {
        new Infantry(2, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(5, 50, Position(0, 0), SNIPER),
        new Vehicle(1, 5, Position(0, 0), TRUCK)
    };
    LiberationArmy la(units, 2, "Defender", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Attacker", nullptr);
    la.fight(&enemy, true);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}

void lbta_D3() {
    cout << "\nRunning lbta_D3: Defense, both stats < enemy ⇒ reinforce, reevaluate" << endl;
    Unit* units[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(10, 200, Position(0, 0), TANK)
    };
    LiberationArmy la(units, 2, "Defender", nullptr);
    LiberationArmy enemy(enemyUnits, 2, "Attacker", nullptr);
    la.fight(&enemy, true);
    cout << la.str() << endl;
    cout << enemy.str() << endl;
}


void lbta_demo1(){
    lbta_A1();
    lbta_A2();
    lbta_A3();
    lbta_A4();
    lbta_D1();
    lbta_D2();
    lbta_D3();
}

void arvn_A1() {
    cout << "arvn A1 - ARVN attacks LiberationArmy (Always loses)\n";

    Unit* units[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER)
    };

    ARVN arvn(units, 2, "ARVN1", nullptr);
    LiberationArmy lba(enemyUnits, 1, "LBA1", nullptr);

    cout << arvn.str() << endl;
    cout << lba.str() << endl;

    arvn.fight(&lba, false); // attack

    cout << arvn.str() << endl;
    cout << lba.str() << endl;
}

void arvn_D1() {
    cout << "arvn D1 - ARVN defends, LBA attacks and wins\n";

    Unit* units[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER),
        new Vehicle(10, 200, Position(0, 0), TANK)
    };

    ARVN arvn(units, 2, "ARVN2", nullptr);
    LiberationArmy lba(enemyUnits, 2, "LBA2", nullptr);

    cout << arvn.str() << endl;
    cout << lba.str() << endl;

    lba.fight(&arvn, false); // LBA attacks
    cout << arvn.str() << endl;
}

void arvn_D2() {
    cout << "arvn D2 - ARVN defends, LBA doesn't attack\n";

    Unit* units[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER)
    };
    Unit* enemyUnits[] = {
        new Vehicle(1, 1, Position(0, 0), TANK)
    };

    ARVN arvn(units, 1, "ARVN3", nullptr);
    LiberationArmy lba(enemyUnits, 1, "LBA3", nullptr);

    cout << arvn.str() << endl;
    cout << lba.str() << endl;

    lba.fight(&arvn, false); // LBA attacks
    cout << arvn.str() << endl;
}

void arvn_D3() {
    cout << "arvn D3 - ARVN defends, LBA attacks but only wins partially (1 group)\n";

    Unit* units[] = {
        new Infantry(1, 10, Position(0, 0), SNIPER),
        new Vehicle(1, 10, Position(0, 0), TANK)
    };
    Unit* enemyUnits[] = {
        new Infantry(10, 50, Position(0, 0), SNIPER)
    };

    ARVN arvn(units, 2, "ARVN4", nullptr);
    LiberationArmy lba(enemyUnits, 1, "LBA4", nullptr);

    cout << arvn.str() << endl;
    cout << lba.str() << endl;

    lba.fight(&arvn, false); // LBA attacks
    cout << arvn.str() << endl;
}

void arvn_D4() {
    cout << "arvn D4 - ARVN defends, LBA attacks and loses (edge case)\n";

    Unit* units[] = {
        new Infantry(10, 100, Position(0, 0), SNIPER)
    };
    Unit* enemyUnits[] = {
        new Infantry(1, 1, Position(0, 0), SNIPER)
    };

    ARVN arvn(units, 1, "ARVN5", nullptr);
    LiberationArmy lba(enemyUnits, 1, "LBA5", nullptr);

    cout << arvn.str() << endl;
    cout << lba.str() << endl;

    lba.fight(&arvn, false); // LBA attacks
    cout << arvn.str() << endl;
}

void arvn_demo1() {
    arvn_A1();
    cout << "-----------------------------------\n";
    arvn_D1();
    cout << "-----------------------------------\n";
    arvn_D2();
    cout << "-----------------------------------\n";
    arvn_D3();
    cout << "-----------------------------------\n";
    arvn_D4();
}

void road_demo() {
    cout << "Running road_demo (Road):" << endl;
    Unit* u[] = { new Infantry(10, 100, Position(0, 0), REGULARINFANTRY) };
    Army* army = new LiberationArmy(u, 1, "Lib", nullptr);

    int expBefore = army->getEXP();
    int lfBefore = army->getLF();

    Road road(Position(1, 1));
    road.getEffect(army);

    assert(army->getEXP() == expBefore);
    assert(army->getLF() == lfBefore);

    delete army;
}

void mntn_demo() {
    cout << "Running mntn_demo (Mountain):" << endl;
    Unit* u[] = {
        new Infantry(10, 100, Position(1, 1), REGULARINFANTRY), // Infantry
        new Vehicle(10, 100, Position(1, 1), ARTILLERY)         // Vehicle
    };
    Army* army = new LiberationArmy(u, 2, "Lib", nullptr); // Use ARVN to test other branch

    cout << army->getEXP() << " - " << army->getLF() << endl;

    Mountain m(Position(0, 0));
    m.getEffect(army);

    cout << army->getEXP() << " - " << army->getLF() << endl;

    delete army;
}

void river_demo() {
    cout << "Running river_demo (River):" << endl;
    Unit* u[] = {
        new Infantry(100, 10, Position(1, 1), REGULARINFANTRY), // in range
        new Infantry(10, 100, Position(5, 5), SPECIALFORCES)     // out of range
    };
    Army* army = new LiberationArmy(u, 2, "Lib", nullptr);
    
    cout << army->getEXP() << " - " << army->getLF() << endl;

    River r(Position(0, 0));
    r.getEffect(army);

    cout << army->getEXP() << " - " << army->getLF() << endl;

    delete army;
}

void urban_demo() {
    cout << "Running urban_demo (Urban):" << endl;
    Unit* u[] = {
        new Infantry(10, 100, Position(1, 1), SPECIALFORCES),   // Close enough
        new Infantry(10, 100, Position(5, 5), REGULARINFANTRY), // Out of range
        new Vehicle(10, 100, Position(1, 1), ARTILLERY)         // Affected by distance
    };
    Army* army = new LiberationArmy(u, 3, "Lib", nullptr);
    cout << army->getEXP() << " - " << army->getLF() << endl;


    Urban urb(Position(0, 0));
    urb.getEffect(army);

    cout << army->getEXP() << " - " << army->getLF() << endl;

    delete army;
}

void fort_demo() {
    cout << "Running fort_demo (Fortification):" << endl;
    Unit* u[] = {
        new Infantry(10, 100, Position(1, 1), REGULARINFANTRY), // In range
        new Vehicle(10, 100, Position(1, 1), ARTILLERY)         // In range
    };
    Army* army = new ARVN(u, 2, "ARVN", nullptr);
    cout << army->getEXP() << " - " << army->getLF() << endl;

    Fortification f(Position(0, 0));
    f.getEffect(army);

    cout << army->getEXP() << " - " << army->getLF() << endl;
    delete army;
}

void specz_demo() {
    cout << "Running specz_demo (SpecialZone):" << endl;
    Unit* u[] = {
        new Infantry(10, 100, Position(1, 1), SPECIALFORCES), // Distance = sqrt(2)
        new Vehicle(10, 100, Position(0, 0), ARTILLERY)       // Distance = 0
    };
    Army* army = new LiberationArmy(u, 2, "Lib", nullptr);
    cout << army->getEXP() << " - " << army->getLF() << endl;

    SpecialZone sz(Position(0, 0));
    sz.getEffect(army);

    cout << army->getEXP() << " - " << army->getLF() << endl;

    delete army;
}


void teel_demo(){
    road_demo();
    mntn_demo();
    river_demo();
    urban_demo();
    fort_demo();
    specz_demo();
}

void field_demo() {
    vector<Position*> forests = {
        new Position(0, 1), new Position(1, 3), new Position(3, 0)
    };
    vector<Position*> rivers = {
        new Position(2, 2), new Position(4, 4)
    };
    vector<Position*> forts = {
        new Position(1, 0), new Position(3, 3)
    };
    vector<Position*> urbans = {
        new Position(0, 3), new Position(2, 0)
    };
    vector<Position*> specials = {
        new Position(4, 0), new Position(0, 4)
    };

    BattleField* bf = new BattleField(5, 5, forests, rivers, forts, urbans, specials);

    Unit* u[] = {
        new Infantry(10, 100, Position(1, 1), REGULARINFANTRY), // In range
        new Vehicle(10, 100, Position(1, 1), ARTILLERY)         // In range
    };
    Army* army = new LiberationArmy(u, 2, "Lib", bf);
    
    bf->applyTerrainEffects(army);

    cout << bf->str();  // Full terrain map

    // Clean up manually allocated positions
    for (auto p : forests) delete p;
    for (auto p : rivers) delete p;
    for (auto p : forts) delete p;
    for (auto p : urbans) delete p;
    for (auto p : specials) delete p;

    delete bf;
}

// Main
int main(int argc, const char * argv[]){
    field_demo();
    return 0;
}