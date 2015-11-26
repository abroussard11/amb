/**
 * tests/AmbUnitTest.h
 */

#ifndef TESTS_AMBUNITTEST_H_
#define TESTS_AMBUNITTEST_H_

#include <tests/TestRunner.h>

namespace tests {

class AmbUnitTest : public TestRunner
{
public:
   AmbUnitTest() = default;
   virtual ~AmbUnitTest() = default;

   virtual const char* getTestName() const
   {
      return "AmbUnitTest";
   }
   void testRoutine() override;

private:
   void testFastMap();
   bool testGuiComponent();
   void testXml();
};

} // End namespace tests

#endif // TESTS_AMBUNITTEST_H_
