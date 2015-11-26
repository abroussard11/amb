/**
 * Util/UtilUnitTest.h
 */

#ifndef TESTS_UTILUNITTEST_H_
#define TESTS_UTILUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class UtilUnitTest : public TestRunner
{
public:
   UtilUnitTest() = default;
   virtual ~UtilUnitTest() = default;

   virtual const char* getTestName() const
   {
      return "UtilUnitTest";
   }
   void testRoutine() override;
   bool constructWithDllUtil();
};

} // End namespace tests

#endif // TESTS_UTILUNITTEST_H_
