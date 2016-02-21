/**
 * tests/BitOps/NyBitByte_test.h
 */

#ifndef TESTS_BITOPS_NYBITBYTE_TEST_H_
#define TESTS_BITOPS_NYBITBYTE_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class NyBitByte_test : public tests::TestRunner {
 public:
  NyBitByte_test() = default;
  virtual ~NyBitByte_test() = default;

  void testRoutine() override;
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_NYBITBYTE_TEST_H_
