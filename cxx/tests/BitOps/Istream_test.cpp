/**
 * tests/BitOps/Istream_test.cpp
 */

#include <tests/BitOps/Istream_test.h>
#include <BitOps/Istream.h>
#include <BitOps/Int8.h>
#include <tests/BitOps/MultiByteValue.h>

namespace BitOps {

void Istream_test::testRoutine() {
#define logTestCase(caseName) std::cout << "Case: " #caseName << std::endl

  logTestCase(read1Byte);
  read1Byte();

  logTestCase(read2Bytes);
  read2Bytes();

  logTestCase(read3Bytes);
  read3Bytes();

  logTestCase(read1_7BitByte);
  read1_7BitByte();

  logTestCase(read2_7BitBytes);
  read2_7BitBytes();

  logTestCase(read1_2BitByte);
  read1_2BitByte();

  logTestCase(read2_2BitBytes);
  read2_2BitBytes();

  logTestCase(readMultiByteValue);
  readMultiByteValue();
}

void Istream_test::read1Byte() {
  const uint arrsize = 1;
  uchar arr[arrsize] = {3};
  Istream buf(arr, arrsize);

  Int8<8> x;
  buf >> x;
  requireEqual(x.getBits(), 3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read2Bytes() {
  const uint arrsize = 2;
  uchar arr[arrsize] = {3, 5};
  Istream buf(arr, arrsize);

  Int8<8> x, y;
  buf >> x >> y;
  requireEqual(x.getBits(), 3);
  requireEqual(y.getBits(), 5);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 2);
}

void Istream_test::read3Bytes() {
  const uchar num3 = 0b1110'1011;
  const uint arrsize = 3;
  uchar arr[arrsize] = {3, 5, num3};
  Istream buf(arr, arrsize);

  Int8<8> x, y, z;
  buf >> x >> y >> z;
  requireEqual(x.getBits(), 3);
  requireEqual(y.getBits(), 5);
  requireEqual(z.getBits(), num3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 3);
}

void Istream_test::read1_7BitByte() {
  const uint arrsize = 1;
  uchar arr[arrsize] = {0b0000'0110}; // 3 << 1
  Istream buf(arr, arrsize);

  Int8<7> x;
  buf >> x;
  requireEqual(x.getData(), 3);
}

void Istream_test::read2_7BitBytes() {
  const uint arrsize = 2;
  uchar arr[arrsize] = {0b0000'0110, 0b0001'0100};
  Istream buf(arr, arrsize);

  Int8<7> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 5);
  requireEqual(buf.getBitPos(), 6);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read1_2BitByte() {
  const uint arrsize = 1;
  uchar arr[arrsize] = {0b1110'0000};
  Istream buf(arr, arrsize);

  Int8<2> x;
  buf >> x;
  requireEqual(x.getData(), 3);
  requireEqual(buf.getBitPos(), 2);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::read2_2BitBytes() {
  const uint arrsize = 1;
  uchar arr[arrsize] = {0b1110'0000}; // 3,2
  Istream buf(arr, arrsize);

  Int8<2> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 2);
  requireEqual(buf.getBitPos(), 4);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::readMultiByteValue() {
  uchar b1 = 0b0010'0001;
  uchar b2 = 0b0001'1101;
  uchar b3 = 0b0001'1010;
  uchar b4 = 0b1110'0011;

  const uint arrsize = 4;
  uchar arr[arrsize] = {b1, b2, b3, b4};
  Istream buf(arr, arrsize);

  MultiByteValue mbv;
  auto bufThrew = false;
  try {
    buf >> mbv;
    requireEqual(mbv.getByte1(), b1);
    requireEqual(mbv.getByte2(), b2);
    requireEqual(mbv.getByte3(), b3);
    requireEqual(mbv.getByte4(), b4);
    requireEqual(buf.getBitPos(), 0);
    requireEqual(buf.getBytePos(), 4);

  } catch (const char* e) {
    std::cout << "Error message:" << e << std::endl;
    bufThrew = true;
  }
  requireEqual(bufThrew, false);
}

}  // End namespace BitOps
