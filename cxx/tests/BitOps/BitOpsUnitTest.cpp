/**
 * tests/BitOps/BitOpsUnitTest.cpp
 */

#include <tests/BitOps/BitOpsUnitTest.h>
#include <tests/BitOps/Int_test.h>
#include <tests/BitOps/Istream_test.h>
#include <tests/BitOps/Ostream_test.h>
#include <tests/BitOps/NyBitByte_test.h>

namespace BitOps {

void BitOpsUnitTest::setupSubTests() {
  addTest<Int_test>();
  addTest<Istream_test>();
  addTest<Ostream_test>();
  addTest<NyBitByte_test>();

}

void BitOpsUnitTest::testRoutine() {
  // Empty
}

}  // End namespace BitOps
