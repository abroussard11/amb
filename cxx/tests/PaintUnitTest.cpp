/**
 * tests/PaintUnitTest.cpp
 */

#include <tests/PaintUnitTest.h>

#include <paint/generic/PaintApp.h>
#include <paint/generic/SmallBrush.h>

namespace tests {

void PaintUnitTest::testRoutine() {
  requireEqual(construct<paint::PaintApp>(), true);
  requireEqual(construct<paint::SmallBrush>(0.F, 0.F), true);
}

}  // End namespace tests
