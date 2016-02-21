/**
 * tests/std/UnitTest.h
 */
#ifndef TESTS_STD_UNITTEST_H_
#define TESTS_STD_UNITTEST_H_

#include <tests/TestRunner.h>

namespace std {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void setupSubTests() override;
  void testRoutine() override;
};

}  // End namespace std

#endif // TESTS_STD_UNITTEST_H_
