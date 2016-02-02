/**
 * tests/DsbUnitTest.h
 */

#ifndef TESTS_DSBUNITTEST_H_
#define TESTS_DSBUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class DsbUnitTest : public TestRunner {
 public:
  DsbUnitTest() = default;
  virtual ~DsbUnitTest() = default;

  const char* getTestName() const override { //
    return "DsbUnitTest";
  }
  void testRoutine() override;

 private:
  void testProjectFile();
};

}  // End namespace tests

#endif  // TESTS_DSBUNITTEST_H_
