/**
 * tests/MasterUnitTest.cpp
 */

#include <tests/MasterUnitTest.h>

#include <tests/amb/UnitTest.h>
#include <tests/dsb/UnitTest.h>
#include <tests/infra/UnitTest.h>
#include <tests/paint/UnitTest.h>
#include <tests/util/UnitTest.h>
#include <tests/BitOps/BitOpsUnitTest.h>
#include <tests/std/UnitTest.h>

namespace tests {

void MasterUnitTest::setupSubTests() {
  addTest<amb::UnitTest>();
  addTest<BitOps::BitOpsUnitTest>();
  addTest<dsb::UnitTest>();
  addTest<infra::UnitTest>();
  addTest<paint::UnitTest>();
  addTest<util::UnitTest>();
  addTest<std::UnitTest>();
}

void MasterUnitTest::testRoutine() {
  // Empty
}

}  // End namespace tests
