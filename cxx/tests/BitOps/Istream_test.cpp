/**
 * tests/BitOps/Istream_test.cpp
 */

#include <tests/BitOps/Istream_test.h>
#include <BitOps/Istream.h>
#include <BitOps/Int8.h>
#include <tests/BitOps/MultiByteValue.h>

namespace BitOps {

void setIstreamBuffer(Istream& is, uint index, uchar x) {
  is.buf()[index] = x;
}

void Istream_test::testRoutine() {
#define logTestCase(caseName) std::cout << "Case: " #caseName << std::endl

  logTestCase(bufferIsConstructedZero);
  bufferIsConstructedZero();

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

void Istream_test::bufferIsConstructedZero() {
  Istream buf;
  uchar x = 0;
  for (uint i = 0; i < Istream::SIZE; ++i) {
    x |= buf.at(i);
  }
  requireEqual(x, 0);
}

void Istream_test::read1Byte() {
  Istream buf;
  setIstreamBuffer(buf, 0, 3);

  Int8<8> x;
  buf >> x;
  requireEqual(x.getBits(), 3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read2Bytes() {
  Istream buf;
  setIstreamBuffer(buf, 0, 3);
  setIstreamBuffer(buf, 1, 5);
  //setup done.

  Int8<8> x, y;
  buf >> x >> y;
  requireEqual(x.getBits(), 3);
  requireEqual(y.getBits(), 5);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 2);
}

void Istream_test::read3Bytes() {
  Istream buf;
  const uchar num3 = 0b1110'1011;

  setIstreamBuffer(buf, 0, 3);
  setIstreamBuffer(buf, 1, 5);
  setIstreamBuffer(buf, 2, num3);
  //setup done.

  Int8<8> x, y, z;
  buf >> x >> y >> z;
  requireEqual(x.getBits(), 3);
  requireEqual(y.getBits(), 5);
  requireEqual(z.getBits(), num3);
  requireEqual(buf.getBitPos(), 0);
  requireEqual(buf.getBytePos(), 3);
}

void Istream_test::read1_7BitByte() {
  Istream buf;
  setIstreamBuffer(buf, 0, 0b0000'0110); // 3 << 1

  Int8<7> x;
  buf >> x;
  requireEqual(x.getData(), 3);
}

void Istream_test::read2_7BitBytes() {
  Istream buf;
  setIstreamBuffer(buf, 0, 0b0000'0110); // 3
  setIstreamBuffer(buf, 1, 0b0001'0100); // 5

  Int8<7> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 5);
  requireEqual(buf.getBitPos(), 6);
  requireEqual(buf.getBytePos(), 1);
}

void Istream_test::read1_2BitByte() {
  Istream buf;
  setIstreamBuffer(buf, 0, 0b1110'0000); // 3

  Int8<2> x;
  buf >> x;
  requireEqual(x.getData(), 3);
  requireEqual(buf.getBitPos(), 2);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::read2_2BitBytes() {
  Istream buf;
  setIstreamBuffer(buf, 0, 0b1110'0000); // 3,2

  Int8<2> x, y;
  buf >> x >> y;
  requireEqual(x.getData(), 3);
  requireEqual(y.getData(), 2);
  requireEqual(buf.getBitPos(), 4);
  requireEqual(buf.getBytePos(), 0);
}

void Istream_test::readMultiByteValue() {
#define BINLIT_STR(zerosAndOnes) 0b##zerosAndOnes
#define BINLIT(zerosAndOnes) BINLIT_STR(zerosAndOnes)
#define CONCAT_STR(a,b,c,d) a##b##c##d
#define CONCAT(a, b, c, d) CONCAT_STR(a,b,c,d)

#define MBV_BYTE1 0010'0001
#define MBV_BYTE2 0001'1101
#define MBV_BYTE3 0001'1010
#define MBV_BYTE4 1110'0011


  Istream buf;
  MultiByteValue mbv;
  setIstreamBuffer(buf, 0, BINLIT(MBV_BYTE1));
  setIstreamBuffer(buf, 1, BINLIT(MBV_BYTE2));
  setIstreamBuffer(buf, 2, BINLIT(MBV_BYTE3));
  setIstreamBuffer(buf, 3, BINLIT(MBV_BYTE4));

  auto bufThrew = false;
  try {
    buf >> mbv;
    requireEqual(mbv.getByte1(), BINLIT(MBV_BYTE1));
    requireEqual(mbv.getByte2(), BINLIT(MBV_BYTE2));
    requireEqual(mbv.getByte3(), BINLIT(MBV_BYTE3));
    requireEqual(mbv.getByte4(), BINLIT(MBV_BYTE4));
    requireEqual(buf.getBitPos(), 0);
    requireEqual(buf.getBytePos(), 4);

  } catch (const char* e) {
    std::cout << "Error message:" << e << std::endl;
    bufThrew = true;
  }
  requireEqual(bufThrew, false);
}

}  // End namespace BitOps
