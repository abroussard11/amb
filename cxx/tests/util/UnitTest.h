/**
 * Util/util/UnitTest.h
 */

#ifndef TESTS_UTIL_UNITTEST_H_
#define TESTS_UTIL_UNITTEST_H_

#include <tests/TestRunner.h>

namespace util {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void testRoutine() override;
  bool constructWithDllUtil();
};

}  // End namespace util

#endif  // TESTS_UTIL_UNITTEST_H_
