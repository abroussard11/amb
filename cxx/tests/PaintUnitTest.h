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

  const char* getTestName() const override { //
    return "PaintUnitTest";
  }
  void testRoutine() override;
};

}  // End namespace tests

#endif  // TESTS_PAINTUNITTEST_H_
