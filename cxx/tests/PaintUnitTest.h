/**
 * tests/PaintUnitTest.h
 */

#ifndef TESTS_PAINTUNITTEST_H_
#define TESTS_PAINTUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class PaintUnitTest : public TestRunner {
 public:
  PaintUnitTest() = default;
  virtual ~PaintUnitTest() = default;

  virtual const char* getTestName() const { return "PaintUnitTest"; }
  void testRoutine() override;
};

}  // End namespace tests

#endif  // TESTS_PAINTUNITTEST_H_
