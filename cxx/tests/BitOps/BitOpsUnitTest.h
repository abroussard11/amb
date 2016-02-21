/**
 * tests/BitOps/BitOpsUnitTest.h
 */

#ifndef TESTS_BITOPS_BITOPSUNITTEST_H_
#define TESTS_BITOPS_BITOPSUNITTEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class BitOpsUnitTest : public tests::TestRunner {
 public:
  BitOpsUnitTest() = default;
  virtual ~BitOpsUnitTest() = default;

  void setupSubTests() override;
  void testRoutine() override;
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_BITOPSUNITTEST_H_
