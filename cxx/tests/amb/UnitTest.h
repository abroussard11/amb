/**
 * tests/amb/UnitTest.h
 */

#ifndef TESTS_AMB_UNITTEST_H_
#define TESTS_AMB_UNITTEST_H_

#include <tests/TestRunner.h>

namespace amb {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void testRoutine() override;

 private:
  void testFastMap();
  bool testGuiComponent();
  void testXml();
  void testAttribute();
};

}  // End namespace amb

#endif  // TESTS_AMB_UNITTEST_H_
