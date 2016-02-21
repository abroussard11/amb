/**
 * tests/BitOps/Ostream_test.h
 */

#ifndef TESTS_BITOPS_OSTREAM_TEST_H_
#define TESTS_BITOPS_OSTREAM_TEST_H_

#include <tests/TestRunner.h>

namespace BitOps {

class Ostream_test : public tests::TestRunner {
 public:
  Ostream_test() = default;
  virtual ~Ostream_test() = default;

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
};

}  // End namespace BitOps

#endif  // TESTS_BITOPS_OSTREAM_TEST_H_
