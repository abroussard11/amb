/**
 * tests/BitOps/Int_test.h
 */

#ifndef BITOPS_INT_H
#define BITOPS_INT_H

#include <tests/TestRunner.h>

namespace BitOps {

class Int_test : public tests::TestRunner {
 public:
  Int_test() = default;
  virtual ~Int_test() = default;

  void testRoutine() override;

  void testBitwiseAND();
  void testBitwiseOR();
  void testBitwiseNOT();
  void testBitwiseXOR();
  void testLeftshift();
  void testRightShift();
  void testInt();
};

}  // End namespace BitOps

#endif  // BITOPS_INT_H
