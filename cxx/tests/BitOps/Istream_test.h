/**
 * tests/BitOps/Istream_test.h
 */

#ifndef TESTS_BITOPS_ISTREAM_TEST_H_
#define TESTS_BITOPS_ISTREAM_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class Istream_test : public tests::TestRunner {
 public:
  Istream_test() = default;
  virtual ~Istream_test() = default;

  void testRoutine() override;

 private:
  void bufferIsConstructedZero();
  void write1Byte();
  void write2Bytes();
  void write3Bytes();

  void write1_7BitByte();
  void write2_7BitBytes();

  void write1_2BitByte();
  void write2_2BitBytes();
  void writeMultiByteValue();

  void read1Byte();
  void read2Bytes();
  void read3Bytes();

  void read1_7BitByte();
  void read2_7BitBytes();

  void read1_2BitByte();
  void read2_2BitBytes();
  void readMultiByteValue();
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_ISTREAM_TEST_H_
