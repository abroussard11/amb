/**
 * tests/BitOps/Ostream_test.cpp
 */

#include <tests/BitOps/Ostream_test.h>
#include <BitOps/Ostream.h>
#include <BitOps/Int8.h>
#include <tests/BitOps/MultiByteValue.h>

namespace BitOps {

void Ostream_test::testRoutine() {
  logTestCase(write1Byte);
  write1Byte();

  logTestCase(write2Bytes);
  write2Bytes();

  logTestCase(write3Bytes);
  write3Bytes();

  logTestCase(write1_7BitByte);
  write1_7BitByte();

  logTestCase(write2_7BitBytes);
  write2_7BitBytes();

  logTestCase(write1_2BitByte);
  write1_2BitByte();

  logTestCase(write2_2BitBytes);
  write2_2BitBytes();

  logTestCase(writeMultiByteValue);
  writeMultiByteValue();

  logTestCase(write_uint8_t);
  write_uint8_t();

  logTestCase(write_uint16_t);
  write_uint16_t();

  logTestCase(write_uint32_t);
  write_uint32_t();

  logTestCase(write_uint32_t);
  write_uint32_t();

  logTestCase(write_uint64_t);
  write_uint64_t();
}

void Ostream_test::write1Byte() {
  Ostream buf;
  Int8<8> x;
  x.setData(3);
  buf << x;
  requireEqual(buf.at(0), 3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 1);
}

void Ostream_test::write2Bytes() {
  Ostream buf;
  Int8<8> x;
  x.setData(3);
  buf << x;

  x.setData(5);
  buf << x;

  requireEqual(buf.at(0), 3);
  requireEqual(buf.at(1), 5);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 2);
}

void Ostream_test::write3Bytes() {
  std::uint8_t num1 = 3;
  std::uint8_t num2 = 5;
  std::uint8_t num3 = 0b1110'1011;

  Ostream buf;
  Int8<8> x;
  x.setData(num1);
  buf << x;

  x.setData(num2);
  buf << x;

  x.setData(num3);
  buf << x;

  requireEqual(buf.at(0), num1);
  requireEqual(buf.at(1), num2);
  requireEqual(buf.at(2), num3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 3);
}

void Ostream_test::write1_7BitByte() {
  Ostream buf;
  Int8<7> x;
  x.setData(3);
  buf << x;
  requireEqual(buf.at(0), 0b0000'0110);
  requireEqual(buf.getBitPos(), 7);
  requireEqual(buf.getBytePos(), 0);
}

void Ostream_test::write2_7BitBytes() {
  Ostream buf;
  Int8<7> x;
  x.setData(3);
  buf << x;

  x.setData(5);
  buf << x;

  requireEqual(buf.at(0), 0b0000'0110);
  requireEqual(buf.at(1), 0b0001'0100);
  requireEqual(buf.getBitPos(), 6);
  requireEqual(buf.getBytePos(), 1);
}

void Ostream_test::write1_2BitByte() {
  std::uint8_t num1 = 0b0000'0011;

  Ostream buf;
  Int8<2> x;
  x.setData(num1);
  buf << x;
  requireEqual(buf.at(0), 0b1100'0000);
  requireEqual(buf.getBitPos(), 2);
  requireEqual(buf.getBytePos(), 0);
}

void Ostream_test::write2_2BitBytes() {
  std::uint8_t num1 = 0b0000'0011;
  std::uint8_t num2 = 0b0000'0001;

  Ostream buf;
  Int8<2> x;
  x.setData(num1);
  buf << x;
  x.setData(num2);
  buf << x;

  requireEqual(buf.at(0), 0b1101'0000);
  requireEqual(buf.getBitPos(), 4);
  requireEqual(buf.getBytePos(), 0);
}

void Ostream_test::writeMultiByteValue() {
#define BINLIT_STR(zerosAndOnes) 0b##zerosAndOnes
#define BINLIT(zerosAndOnes) BINLIT_STR(zerosAndOnes)
#define CONCAT_STR(a,b,c,d) a##b##c##d
#define CONCAT(a, b, c, d) CONCAT_STR(a,b,c,d)

#define MBV_BYTE1 0010'0001
#define MBV_BYTE2 0001'1101
#define MBV_BYTE3 0001'1010
#define MBV_BYTE4 1110'0011

  Ostream buf;
  MultiByteValue mbv;
  mbv.setValue(BINLIT(CONCAT(MBV_BYTE1, MBV_BYTE2, MBV_BYTE3, MBV_BYTE4)));

  buf << mbv;
  requireEqual(buf.at(0), BINLIT(MBV_BYTE1));
  requireEqual(buf.at(1), BINLIT(MBV_BYTE2));
  requireEqual(buf.at(2), BINLIT(MBV_BYTE3));
  requireEqual(buf.at(3), BINLIT(MBV_BYTE4));
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 4);
}

void Ostream_test::write_uint8_t() {
  write_stdint<std::uint8_t>(3);
  write_stdint<std::uint8_t>(128);
}

void Ostream_test::write_uint16_t() {
  write_stdint<std::uint16_t>(3);
  write_stdint<std::uint16_t>(128);
}

void Ostream_test::write_uint32_t() {
  write_stdint<std::uint32_t>(3);
  write_stdint<std::uint32_t>(128);
}

void Ostream_test::write_uint64_t() {
  write_stdint<std::uint64_t>(3);
  write_stdint<std::uint64_t>(128);
}

template <class T>
void Ostream_test::write_stdint(T val) {
  std::size_t size = sizeof(T);
  T x = val;
  Ostream buf;
  buf << x;

  requireEqual(buf.at(0), val);
  for (int i = 1; i < size; ++i) {
    requireEqual(buf.at(i), 0);
  }
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), size);
}
}  // End namespace BitOps
