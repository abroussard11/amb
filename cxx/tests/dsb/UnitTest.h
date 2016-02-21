/**
 * tests/dsb/UnitTest.h
 */

#ifndef TESTS_DSB_UNITTEST_H_
#define TESTS_DSB_UNITTEST_H_

#include <tests/TestRunner.h>

namespace dsb {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void testRoutine() override;

 private:
  void testProjectFile();
};

}  // End namespace dsb

#endif  // TESTS_DSB_UNITTEST_H_
