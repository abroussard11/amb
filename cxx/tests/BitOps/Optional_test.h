/**
 * tests/BitOps/Optional_test.h
 */

#ifndef TESTS_BITOPS_OPTIONAL_TEST_H_
#define TESTS_BITOPS_OPTIONAL_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class Optional_test : public tests::TestRunner {
 public:
  Optional_test() = default;
  virtual ~Optional_test() = default;

  void testRoutine() override;
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_OPTIONAL_TEST_H_
