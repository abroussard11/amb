/**
 * tests/BitOps/Repeatable_test.h
 */

#ifndef TESTS_BITOPS_REPEATABLE_TEST_H_
#define TESTS_BITOPS_REPEATABLE_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class Repeatable_test : public tests::TestRunner {
 public:
  Repeatable_test() = default;
  virtual ~Repeatable_test() = default;

  void testRoutine() override;

 private:
  void test1Int0();
  void test1Int1();
  void test2Int();
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_REPEATABLE_TEST_H_
