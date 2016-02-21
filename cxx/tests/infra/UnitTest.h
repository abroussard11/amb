/**
 * tests/infra/UnitTest.h
 */

#ifndef TESTS_INFRA_UNITTEST_H_
#define TESTS_INFRA_UNITTEST_H_

#include <tests/TestRunner.h>

namespace infra {

class UnitTest : public tests::TestRunner {
 public:
  UnitTest() = default;
  virtual ~UnitTest() = default;

  void testRoutine() override;
};

}  // End namespace tests

#endif  // TESTS_INFRA_UNITTEST_H_
