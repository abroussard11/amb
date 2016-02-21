/**
 * tests/std/typeinfo_test.h
 */

#ifndef TESTS_TYPEINFO_TEST_H_
#define TESTS_TYPEINFO_TEST_H_

#include <tests/TestRunner.h>

namespace std {

class typeinfo_test : public tests::TestRunner {
 public:
  typeinfo_test() = default;
  virtual ~typeinfo_test() = default;

  void testRoutine() override;
};

} // End namespace std

#endif  // TESTS_TYPEINFO_TEST_H_
