/**
 * tests/BitOps/Int_test.h
 */

#ifndef BITOPS_INT_H
#define BITOPS_INT_H

#include <tests/TestRunner.h>

namespace BitOps {

class Int_test : public tests::TestRunner
{
public:
   Int_test() = default;
   virtual ~Int_test() = default;

   virtual const char* getTestName() const
   {
      return "Int_test";
   }
   void testRoutine() override;

};

} // End namespace BitOps

#endif // BITOPS_INT_H
