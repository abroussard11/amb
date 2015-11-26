/**
 * tests/InfraUnitTest.h
 */

#ifndef TESTS_INFRAUNITTEST_H_
#define TESTS_INFRAUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class InfraUnitTest : public TestRunner
{
public:
   InfraUnitTest() = default;
   virtual ~InfraUnitTest() = default;

   virtual const char* getTestName() const
   {
      return "InfraUnitTest";
   }
   void testRoutine() override;

};

} // End namespace tests

#endif // TESTS_INFRAUNITTEST_H_
