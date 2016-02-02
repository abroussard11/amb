/**
 * tests/BitOps/Int_test.cpp
 */

#include <tests/BitOps/Int_test.h>

using uchar = unsigned char;
using ushort = unsigned short;

namespace BitOps {

#define logInt(var) \
  std::cout << #var" = " << (int)var << std::endl;
#define logBin(var) \
  std::cout << #var" = " << std::bin << var << std::dec << std::endl;

void Int_test::testRoutine() {
  testBitwiseAND();
  testBitwiseOR();
  testBitwiseNOT();
  testBitwiseXOR();
  testLeftshift();
  testRightShift();
}

void Int_test::testBitwiseAND() {
  uchar one = 1;               // 0000 0001
  uchar two = 2;               // 0000 0010
  requireEqual(one & two, 0);  // 0000 0000

  uchar n16 = 16;               // 0001 0000
  uchar n31 = 31;               // 0001 1111
  requireEqual(n16 & n31, 16);  // 0001 0000

  //  slice8(short x, int index) // index is in [0,8]
  //  {
  //    uchar not0 = ~0; // 1111 1111
  //    ushort stamp = not0 << (8 - index); // 0000 0111 1111 1000
  //    ushort matches = x & stamp; // 0000 0110 1011 1000
  //    uchar result = matches << index; // 1101 0111
  //    return result;
  //  }

  ushort n2040 = 2040;                 // 0000 0111 1111 1000
  ushort n52922 = 52922;               // 1100 1110 1011 1010
  requireEqual(n2040 & n52922, 1720);  // 0000 0110 1011 1000
}

void Int_test::testBitwiseOR() {
  uchar one = 1;               // 0000 0001
  uchar two = 2;               // 0000 0010
  requireEqual(one | two, 3);  // 0000 0011

  uchar n16 = 16;               // 0001 0000
  uchar n31 = 31;               // 0001 1111
  requireEqual(n16 | n31, 31);  // 0001 1111

  ushort n2040 = 2040;                  // 0000 0111 1111 1000
  ushort n52922 = 52922;                // 1100 1110 1011 1010
  requireEqual(n2040 | n52922, 53242);  // 1100 1111 1111 1010
}

void Int_test::testBitwiseNOT() {
  uchar ucNot0 = ~0;
  requireEqual(ucNot0, 255);  // 1111 1111

  ushort usNot0 = ~0;
  requireEqual(usNot0, 65535); // 1111 1111 1111 1111

  uint uiNot0 = ~0;
  requireEqual(uiNot0, 4294967295);  // 1111 1111 1111 1111 1111 1111 1111 1111

  ushort not62162 = ~62162;  // 1111 0010 1101 0010
}

void Int_test::testBitwiseXOR() {
  // TODO
}

void Int_test::testLeftshift() {
  // TODO
}

void Int_test::testRightShift() {
  // TODO
}

}  // End namespace BitOps
