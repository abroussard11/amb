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
  void read1Byte();
  void read2Bytes();
  void read3Bytes();

  void read1_7BitByte();
  void read2_7BitBytes();

  void read1_2BitByte();
  void read2_2BitBytes();
  void readMultiByteValue();

  void read_uint8_t();
  void read_uint16_t();
  void read_uint32_t();
  void read_uint64_t();
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_ISTREAM_TEST_H_
