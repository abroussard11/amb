/**
 * tests/MasterUnitTest.cpp
 */

#include <tests/MasterUnitTest.h>

#include <tests/AmbUnitTest.h>
#include <tests/DsbUnitTest.h>
#include <tests/InfraUnitTest.h>
#include <tests/PaintUnitTest.h>
#include <tests/UtilUnitTest.h>

namespace tests {

void MasterUnitTest::testRoutine()
{
   addTest<DsbUnitTest>();
   addTest<InfraUnitTest>();
   addTest<PaintUnitTest>();
   addTest<UtilUnitTest>();

   addTest<AmbUnitTest>();

   // TODO TEST: TestRunner
}

} // End namespace tests
