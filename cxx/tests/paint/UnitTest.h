/**
 * tests/paint/UnitTest.h
 */

#ifndef TESTS_PAINT_UNITTEST_H_
#define TESTS_PAINT_UNITTEST_H_

#include <tests/TestRunner.h>

namespace paint {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void testRoutine() override;
};

}  // End namespace paint

#endif  // TESTS_PAINT_UNITTEST_H_
