/**
 * tests/BitOps/String7_test.h
 */

#ifndef TESTS_BITOPS_STRING7_TEST_H_
#define TESTS_BITOPS_STRING7_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class String7_test : public tests::TestRunner {
 public:
  String7_test() = default;
  virtual ~String7_test() = default;

  void testRoutine() override;
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_STRING7_TEST_H_
