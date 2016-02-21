/**
 * tests/std/UnitTest.cpp
 */

#include <tests/std/UnitTest.h>
#include <tests/std/typeinfo_test.h>

namespace std {

void UnitTest::setupSubTests() {
  addTest<typeinfo_test>();
}

void UnitTest::testRoutine() {
  // Empty
}

}  // End namespace std

