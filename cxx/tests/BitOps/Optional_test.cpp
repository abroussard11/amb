/**
 * tests/BitOps/Optional_test.cpp
 */

#include <tests/BitOps/Optional_test.h>
#include <tests/BitOps/MultiByteValue.h>
#include <BitOps/Optional.h>

namespace BitOps {

void Optional_test::testRoutine() {
  Optional<std::uint32_t> maybeInteger;
  maybeInteger.set(3);
  requireEqual(maybeInteger.isValid(), true);
  requireEqual(maybeInteger.get(), 3);

  Ostream buf;
  buf << maybeInteger;
  requireEqual(buf.at(0), 0b1000'0001);
  requireEqual(buf.at(1), 0b1000'0000);
  requireEqual(buf.at(2), 0);
  requireEqual(buf.at(3), 0);
  requireEqual(buf.at(4), 0);

  Optional<MultiByteValue> mbv;
  mbv.set(MultiByteValue(3));

  requireEqual(mbv.get().getValue(), 3);
  requireEqual(mbv.isValid(), true);

  buf << mbv;
  requireEqual(buf.at(4), 0b0100'0000);
  requireEqual(buf.at(5), 0b0000'0000);
  requireEqual(buf.at(6), 0b0000'0000);
  requireEqual(buf.at(7), 0b0000'0000);
  requireEqual(buf.at(8), 0b1100'0000);
}

}  // End namespace BitOps
