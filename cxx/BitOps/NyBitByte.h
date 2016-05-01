/**
 * BitOps/NyBitByte.h
 */

#ifndef BITOPS_NYBITBYTE_H_
#define BITOPS_NYBITBYTE_H_

#include <include/OsCompatibility.h>
#include <BitOps/Int8.h>
#include <BitOps/Istream.h>
#include <BitOps/Ostream.h>

namespace BitOps {

template <std::uint32_t N>
struct NyBitByte
{
  enum {
    NUM_WHOLE_BYTES = N / 8,
    NUM_LEFTOVER_BITS = N % 8
  };

  std::uint8_t wholeBytes[NUM_WHOLE_BYTES];
  Int8<NUM_LEFTOVER_BITS> leftovers;

  NyBitByte<N>() = default;

  template <class stdint>
  NyBitByte<N>(stdint val) {
    std::size_t size = sizeof(stdint);
    stdint shiftedVal = (val << (N - size));
    for (std::uint32_t i = 0; i < NUM_WHOLE_BYTES; ++i) {
      wholeBytes[i] = (shiftedVal >> 8 * (NUM_WHOLE_BYTES - i));
    }
  }

  friend Istream& operator>>(Istream& buf, NyBitByte<N>& bits) {
    for (std::uint32_t i = 0; i < NUM_WHOLE_BYTES; i++) {
      buf >> bits.wholeBytes[i];
    }
    buf >> bits.leftovers;
    return buf;
  }

  friend Ostream& operator<<(Ostream& buf, NyBitByte<N>& bits) {
    for (std::uint32_t i = 0; i < NUM_WHOLE_BYTES; i++) {
      buf << bits.wholeBytes[i];
    }
    buf << bits.leftovers;
    return buf;
  }

  std::uint64_t toLLong() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(std::uint64_t),
                  "This data is larger than std::uint32_t."
                  " Conversion results in loss of data.");
    std::uint64_t val = 0;
    for (std::uint32_t i = 0; i < NUM_WHOLE_BYTES; ++i) {
      val |= (wholeBytes[i] << 8 * (NUM_WHOLE_BYTES - i));
    }
    val |= leftovers.getBits();
    return val >> (8 - NUM_LEFTOVER_BITS);
  }

  std::uint32_t toLong() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(std::uint32_t),
                  "This data is larger than std::uint32_t."
                  " Conversion results in loss of data.");
    return static_cast<std::uint32_t>(toLLong());
  }
  std::uint32_t toInt() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(std::uint32_t),
                  "This data is larger than std::uint32_t."
                  " Conversion results in loss of data.");
    return static_cast<std::uint32_t>(toLong());
  }

  std::uint16_t toShort() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(std::uint16_t),
                  "This data is larger than std::uint16_t."
                  " Conversion results in loss of data.");
    return static_cast<std::uint16_t>(toInt());
  }

  std::uint8_t toChar() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(std::uint8_t),
                  "This data is larger than std::uint8_t."
                  " Conversion results in loss of data.");
    return static_cast<std::uint8_t>(toShort());
  }

  bool toBool() const {
    static_assert(NUM_WHOLE_BYTES + (NUM_LEFTOVER_BITS > 0 ? 1 : 0) <= sizeof(bool),
                  "This data is larger than bool."
                  " Conversion results in loss of data.");
    return static_cast<bool>(leftovers.getData());
  }

};

} // End namespace BitOps

#endif // NYBITBYTE_H_

