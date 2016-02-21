/**
 * tests/BitOps/Int_test.cpp
 */

#include <tests/BitOps/Int_test.h>
#include <BitOps/Int8.h>

using uchar = unsigned char;
using ushort = unsigned short;

namespace BitOps {

void Int_test::testRoutine() {
  // Test the language intrinsics
  testBitwiseAND();
  testBitwiseOR();
  testBitwiseNOT();
  testBitwiseXOR();
  testLeftshift();
  testRightShift();

  // Test Int library code
  testInt();
}

void Int_test::testBitwiseAND() {
  uchar one = 1;               // 0000 0001
  uchar two = 2;               // 0000 0010
  requireEqual(one & two, 0);  // 0000 0000

  uchar n16 = 16;               // 0001 0000
  uchar n31 = 31;               // 0001 1111
  requireEqual(n16 & n31, 16);  // 0001 0000

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
  requireEqual(ucNot0, 0b1111'1111);  // 255

  ushort usNot0 = ~0;
  requireEqual(usNot0, 0b1111'1111'1111'1111);  // 65535

  uint uiNot0 = ~0;
  requireEqual(uiNot0, 0b1111'1111'1111'1111'1111'1111'1111'1111);  // 4294967295

  ushort is62162 = 0b1111'0010'1101'0010;
  requireEqual(is62162, 62162);

  ushort not62162 = ~(is62162);
  ushort is3373 = 3373; // 0b0000'1101'0010'1101
  requireEqual(not62162, is3373);
}

void Int_test::testBitwiseXOR() {
   uchar x = 0b1111'0000;
   uchar y = 0b0000'1111;
   uchar xXORy = x ^ y;
   requireEqual(xXORy, 0b1111'1111);

   uchar yXORy = y ^ y;
   requireEqual(yXORy, 0b0000'0000);
}

void Int_test::testLeftshift() {
  uchar x = 0 << 1;
  requireEqual(x, 0);
  x = 1 << 0;
  requireEqual(x, 1);
  x = 1 << 1;
  requireEqual(x, 2);
  x = 1 << 2;
  requireEqual(x, 4);

  x = 0b0100'0000 << 1;
  requireEqual(x, 0b1000'0000);

  x = static_cast<uchar>(0b1111'0000 << 1);
  requireEqual(x, (uchar)0b1110'0000);
}

void Int_test::testRightShift() {
  uchar x = 0 >> 0;
  requireEqual(x, 0);

  x = 0 >> 1;
  requireEqual(x, 0);

  x = 1 >> 0;
  requireEqual(x, 1);

  x = 1 >> 1;
  requireEqual(x, 0);

  x = 2 >> 1;
  requireEqual(x, 1);

  x = 3 >> 1;         // 0000'0011
  requireEqual(x, 1); // 0000'0001

  ushort data = 0b0000'1010'0000'0101;
  uchar hiByte = static_cast<uchar>(data >> 8);
  uchar loByte = static_cast<uchar>(data);
  requireEqual(hiByte, 0b0000'1010);
  requireEqual(loByte, 0b0000'0101);
}

void Int_test::testInt()
{
  {
    Int8<7> x;
    x.setData(3);  // 0000'0011
    std::stringstream xss;
    xss << x;
    auto xdata = xss.str();
    requireEqual(xdata.size(), 1);
    requireEqual(xdata.at(0), 6);  // 0000'0110
  }
  {
    Int8<6> y;
    y.setData(3);  // 0000'0011
    std::stringstream yss;
    yss << y;
    auto ydata = yss.str();
    requireEqual(ydata.size(), 1);
    requireEqual(ydata.at(0), 12);  // 0000'1100
  }
  {
    Int8<2> z;
    z.setData(0b0000'0001);  // 0000'0001
    std::stringstream zss;
    zss << z;
    auto zdata = zss.str();
    requireEqual(zdata.size(), 1);
    requireEqual((uchar)zdata.at(0), (int)0b0100'0000);  // 0100'0000
  }
   // 0000 0001
   // 0100 0000
}

}  // End namespace BitOps
