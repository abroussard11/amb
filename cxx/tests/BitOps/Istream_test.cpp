/**
 * tests/BitOps/Istream_test.cpp
 */

#include <tests/BitOps/Istream_test.h>
#include <BitOps/Istream.h>
#include <BitOps/Int8.h>
#include <tests/BitOps/MultiByteValue.h>

namespace BitOps {

void Istream_test::testRoutine() {

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

  logTestCase(read_uint8_t);
  read_uint8_t();

  logTestCase(read_uint16_t);
  read_uint16_t();

  logTestCase(read_uint32_t);
  read_uint32_t();

  logTestCase(read_uint32_t);
  read_uint32_t();

  logTestCase(read_uint64_t);
  read_uint64_t();
}

void Istream_test::read1Byte() {
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {3};
  Istream buf(arr, arrsize);

  Int8<8> x;
  buf >> x;
  requireEqual(x.getBits(), 3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read2Bytes() {
  const std::uint32_t arrsize = 2;
  std::uint8_t arr[arrsize] = {3, 5};
  Istream buf(arr, arrsize);

  Int8<8> x, y;
  buf >> x >> y;
  requireEqual(x.getBits(), 3);
  requireEqual(y.getBits(), 5);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 2);
}

void Istream_test::read3Bytes() {
  const std::uint8_t num3 = 0b1110'1011;
  const std::uint32_t arrsize = 3;
  std::uint8_t arr[arrsize] = {3, 5, num3};
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
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {0b0000'0110}; // 3 << 1
  Istream buf(arr, arrsize);

  Int8<7> x;
  buf >> x;
  requireEqual(x.getData(), 3);
}

void Istream_test::read2_7BitBytes() {
  const std::uint32_t arrsize = 2;
  std::uint8_t arr[arrsize] = {0b0000'0110, 0b0001'0100};
  Istream buf(arr, arrsize);

  Int8<7> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 5);
  requireEqual(buf.getBitPos(), 6);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read1_2BitByte() {
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {0b1110'0000};
  Istream buf(arr, arrsize);

  Int8<2> x;
  buf >> x;
  requireEqual(x.getData(), 3);
  requireEqual(buf.getBitPos(), 2);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::read2_2BitBytes() {
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {0b1110'0000}; // 3,2
  Istream buf(arr, arrsize);

  Int8<2> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 2);
  requireEqual(buf.getBitPos(), 4);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::readMultiByteValue() {
  std::uint8_t b1 = 0b0010'0001;
  std::uint8_t b2 = 0b0001'1101;
  std::uint8_t b3 = 0b0001'1010;
  std::uint8_t b4 = 0b1110'0011;

  const std::uint32_t arrsize = 4;
  std::uint8_t arr[arrsize] = {b1, b2, b3, b4};
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

void Istream_test::read_uint8_t() {
  const std::uint32_t arrsize = 1;
  std::uint8_t arr[arrsize] = {5};
  Istream buf(arr, arrsize);

  std::uint8_t x;
  buf >> x;

  requireEqual(x, 5);
}

void Istream_test::read_uint16_t() {
  const std::uint32_t arrsize = 2;
  std::uint8_t arr[arrsize] = {5, 0};
  Istream buf(arr, arrsize);

  std::uint16_t x;
  buf >> x;

  requireEqual(x, 5);
}

void Istream_test::read_uint32_t() {
  const std::uint32_t arrsize = 4;
  std::uint8_t arr[arrsize] = {5, 0, 0, 0};
  Istream buf(arr, arrsize);

  std::uint32_t x;
  buf >> x;

  requireEqual(x, 5);
}

void Istream_test::read_uint64_t() {
  const std::uint32_t arrsize = sizeof(std::uint64_t);
  std::uint8_t arr[arrsize] = {17, 16, 15, 14, 13, 12, 11, 10};
  Istream buf(arr, arrsize);

  std::uint64_t x;
  buf >> x;

  requireEqual(x, 723685415333072913ull);
}

  }  // End namespace BitOps
