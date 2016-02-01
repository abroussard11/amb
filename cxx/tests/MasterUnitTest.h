/**
 * tests/MasterUnitTest.h
 */

#ifndef TESTS_MASTERUNITTEST_H_
#define TESTS_MASTERUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class MasterUnitTest : public TestRunner {
 public:
  MasterUnitTest() = default;
  virtual ~MasterUnitTest() = default;

  const char* getTestName() const override { return "MasterUnitTest"; }
  void testRoutine() override;
};

}  // End namespace tests

#endif  // TESTS_MASTERUNITTEST_H_
