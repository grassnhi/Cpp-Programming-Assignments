#ifndef UNIT_TEST_Task1_HPP
#define UNIT_TEST_Task1_HPP

#include "Unit.h"
#include "Infantry.h"
#include "Vehicle.h"
#include "Position.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_Task1 : public UNIT_TEST
{
public:
  UNIT_TEST_Task1()
  {
    REGISTER_TEST(Task101);
    REGISTER_TEST(Task102);
    REGISTER_TEST(Task103);
    REGISTER_TEST(Task104);
    REGISTER_TEST(Task105);
    REGISTER_TEST(Task106);
    REGISTER_TEST(Task107);
    REGISTER_TEST(Task108);
    REGISTER_TEST(Task109);
    REGISTER_TEST(Task110);
    REGISTER_TEST(Task111);
    REGISTER_TEST(Task112);
    REGISTER_TEST(Task113);
    REGISTER_TEST(Task114);
    REGISTER_TEST(Task115);
    REGISTER_TEST(Task116);
    REGISTER_TEST(Task117);
    REGISTER_TEST(Task118);
    REGISTER_TEST(Task119);
    REGISTER_TEST(Task120);
  }

private:
  bool Task101();
  bool Task102();
  bool Task103();
  bool Task104();
  bool Task105();
  bool Task106();
  bool Task107();
  bool Task108();
  bool Task109();
  bool Task110();
  bool Task111();
  bool Task112();
  bool Task113();
  bool Task114();
  bool Task115();
  bool Task116();
  bool Task117();
  bool Task118();
  bool Task119();
  bool Task120();
};

#endif // UNIT_TEST_Task1_HPP