#ifndef UNIT_TEST_Configuration_HPP
#define UNIT_TEST_Configuration_HPP

#include "Configuration.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_Configuration : public UNIT_TEST
{
public:
  UNIT_TEST_Configuration()
  {
    REGISTER_TEST(Configuration01);
    REGISTER_TEST(Configuration02);
    REGISTER_TEST(Configuration03);
    REGISTER_TEST(Configuration04);
    REGISTER_TEST(Configuration05);
    REGISTER_TEST(Configuration06);
    REGISTER_TEST(Configuration07);
    REGISTER_TEST(Configuration08);
    REGISTER_TEST(Configuration09);
    REGISTER_TEST(Configuration10);
  }

private:
  bool Configuration01();
  bool Configuration02();
  bool Configuration03();
  bool Configuration04();
  bool Configuration05();
  bool Configuration06();
  bool Configuration07();
  bool Configuration08();
  bool Configuration09();
  bool Configuration10();
};

#endif // UNIT_TEST_Configuration_HPP