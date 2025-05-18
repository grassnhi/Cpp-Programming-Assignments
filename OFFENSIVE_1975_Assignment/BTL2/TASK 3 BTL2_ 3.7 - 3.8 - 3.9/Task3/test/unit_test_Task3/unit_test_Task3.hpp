#ifndef UNIT_TEST_Task3_HPP
#define UNIT_TEST_Task3_HPP

#include "Unit.h"
#include "Infantry.h"
#include "Vehicle.h"
#include "Position.h"
#include "Army.h"
#include "LiberationArmy.h"
#include "UnitList.h"
#include "ARVN.h"
#include "unit_test.hpp"
#include "Configuration.h"
#include "TerrainElement.h"
#include "BattleField.h"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_Task3 : public UNIT_TEST
{
public:
  UNIT_TEST_Task3()
  {
    REGISTER_TEST(Task301);
    REGISTER_TEST(Task302);
    REGISTER_TEST(Task303);
    REGISTER_TEST(Task304);
    REGISTER_TEST(Task305);
    REGISTER_TEST(Task306);
    REGISTER_TEST(Task307);
    REGISTER_TEST(Task308);
    REGISTER_TEST(Task309);
    REGISTER_TEST(Task310);
    REGISTER_TEST(Task311);
    REGISTER_TEST(Task312);
    REGISTER_TEST(Task313);
    REGISTER_TEST(Task314);
    REGISTER_TEST(Task315);
    REGISTER_TEST(Task316);
    REGISTER_TEST(Task317);
    REGISTER_TEST(Task318);
    REGISTER_TEST(Task319);
    REGISTER_TEST(Task320);
    REGISTER_TEST(Task321);
    REGISTER_TEST(Task322);
    REGISTER_TEST(Task323);
    REGISTER_TEST(Task324);
    REGISTER_TEST(Task325);
    REGISTER_TEST(Task326);
    REGISTER_TEST(Task327);
    REGISTER_TEST(Task328);
    REGISTER_TEST(Task329);
    REGISTER_TEST(Task330);
    REGISTER_TEST(Task331);
    REGISTER_TEST(Task332);
    REGISTER_TEST(Task333);
    REGISTER_TEST(Task334);
    REGISTER_TEST(Task335);
    REGISTER_TEST(Task201);
    REGISTER_TEST(Task202);
    REGISTER_TEST(Task203);
    REGISTER_TEST(Task204);
    REGISTER_TEST(Task205);
    REGISTER_TEST(Task206);
    REGISTER_TEST(Task207);
    REGISTER_TEST(Task208);
    REGISTER_TEST(Task209);
    REGISTER_TEST(Task210);
    REGISTER_TEST(Task211);
    REGISTER_TEST(Task212);
    REGISTER_TEST(Task213);
    REGISTER_TEST(Task214);
    REGISTER_TEST(Task215);
    REGISTER_TEST(Task216);
    REGISTER_TEST(Task217);
    REGISTER_TEST(Task218);
    REGISTER_TEST(Task219);
    REGISTER_TEST(Task220);
    REGISTER_TEST(Task221);
    REGISTER_TEST(Task222);
    REGISTER_TEST(Task223);
    REGISTER_TEST(Task224);
    REGISTER_TEST(Task225);
    REGISTER_TEST(Task226);
    REGISTER_TEST(Task227);
    REGISTER_TEST(Task228);
    REGISTER_TEST(Task229);
    REGISTER_TEST(Task230);
    REGISTER_TEST(Task231);
    REGISTER_TEST(Task232);
    REGISTER_TEST(Task233);
    REGISTER_TEST(Task234);
    REGISTER_TEST(Task235);
    REGISTER_TEST(Task236);
    REGISTER_TEST(Task237);
    REGISTER_TEST(Task238);
    REGISTER_TEST(Task239);
    REGISTER_TEST(Task240);
    REGISTER_TEST(Task241);
    REGISTER_TEST(Task242);
    REGISTER_TEST(Task243);
    REGISTER_TEST(Task244);
    REGISTER_TEST(Task245);
    REGISTER_TEST(Task246);
    REGISTER_TEST(Task247);
    REGISTER_TEST(Task248);
    REGISTER_TEST(Task249);
    REGISTER_TEST(Task250);
    REGISTER_TEST(Task251);
    REGISTER_TEST(Task252);
    
  }

private:
bool Task201();
bool Task202();
bool Task203();
bool Task204();
bool Task205();
bool Task206();
bool Task207();
bool Task208();
bool Task209();
bool Task210();
bool Task211();
bool Task212();
bool Task213();
bool Task214();
bool Task215();
bool Task216();
bool Task217();
bool Task218();
bool Task219();
bool Task220();
bool Task221();
bool Task222();
bool Task223();
bool Task224();
bool Task225();
bool Task226();
bool Task227();
bool Task228();
bool Task229();
bool Task230();
bool Task231();
bool Task232();
bool Task233();
bool Task234();
bool Task235();
bool Task236();
bool Task237();
bool Task238();
bool Task239();
bool Task240();
bool Task241();
bool Task242();
bool Task243();
bool Task244();
bool Task245();
bool Task246();
bool Task247();
bool Task248();
bool Task249();
bool Task250();
bool Task251();
bool Task252();
  bool Task301();
  bool Task302();
  bool Task303();
  bool Task304();
  bool Task305();
  bool Task306();
  bool Task307();
  bool Task308();
  bool Task309();
  bool Task310();
  bool Task311();
  bool Task312();
  bool Task313();
  bool Task314();
  bool Task315();
  bool Task316();
  bool Task317();
  bool Task318();
  bool Task319();
  bool Task320();
  bool Task321();
  bool Task322();
  bool Task323();
  bool Task324();
  bool Task325();
  bool Task326();
  bool Task327();
  bool Task328();
  bool Task329();
  bool Task330();
  bool Task331();
  bool Task332();
  bool Task333();
  bool Task334();
  bool Task335();
};

#endif // UNIT_TEST_Task3_HPP