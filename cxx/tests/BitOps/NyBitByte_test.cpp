/**
 * tests/BitOps/NyBitByte_test.cpp
 */

#include <tests/BitOps/NyBitByte_test.h>
#include <BitOps/NyBitByte.h>

namespace BitOps {

void NyBitByte_test::testRoutine() {
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {0b1000'0000};
  Istream bufTemplate(arr, arrsize);

  {
    Istream buf = bufTemplate;
    NyBitByte<1> myBits;
    buf >> myBits;
    requireEqual(myBits.toInt(), 1);
    requireEqual(myBits.toShort(), 1);
    requireEqual(myBits.toChar(), 1);
    requireEqual(myBits.toBool(), true);
  }

  {
    Istream buf = bufTemplate;
    NyBitByte<2> myBits;
    NyBitByte<2> myBits2;
    buf >> myBits >> myBits2;
    requireEqual(myBits.toInt(), 2);
    requireEqual(myBits2.toShort(), 0);
  }
}

}  // End namespace BitOps
