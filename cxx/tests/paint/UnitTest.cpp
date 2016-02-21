/**
 * tests/paint/UnitTest.cpp
 */

#include <tests/paint/UnitTest.h>

#include <paint/generic/PaintApp.h>
#include <paint/generic/SmallBrush.h>

namespace paint {

void UnitTest::testRoutine() {
  constructorTest<paint::PaintApp>();
  constructorTest<paint::SmallBrush>(0.F, 0.F);
}

}  // End namespace paint
