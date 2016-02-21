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

template <uint N>
struct NyBitByte
{
  enum {
    NUM_WHOLE_BYTES = N / 8,
    NUM_LEFTOVER_BITS = N % 8
  };

  uchar wholeBytes[NUM_WHOLE_BYTES];
  Int8<NUM_LEFTOVER_BITS> leftovers;

  friend Istream& operator>>(Istream& buf, NyBitByte<N>& bits) {
    for (uint i = 0; i < NUM_WHOLE_BYTES; i++) {
      buf >> bits.wholeBytes[i];
    }
    buf >> bits.leftovers;
    return buf;
  }

  friend Ostream& operator<<(Ostream& buf, const NyBitByte<N>& bits) {
    for (uint i = 0; i < NUM_WHOLE_BYTES; i++) {
      buf << bits.wholeBytes[i];
    }
    buf << bits.leftovers;
    return buf;
  }

  ulong toLong() const {
    static_assert(N <= sizeof(uint),
                  "This data is larger than ulong."
                  " Conversion results in loss of data.");
    ulong val = 0;
    for (uint i = 0; i < NUM_WHOLE_BYTES; ++i) {
      val |= (wholeBytes[i] << 8 * (NUM_WHOLE_BYTES - i));
    }
    val |= leftovers.getBits();
    return val >> (8 - NUM_LEFTOVER_BITS);
  }

  uint toInt() const {
    static_assert(N <= sizeof(uint),
                  "This data is larger than uint."
                  " Conversion results in loss of data.");
    return static_cast<uint>(toLong());
  }

  ushort toShort() const {
    static_assert(N <= sizeof(ushort),
                  "This data is larger than ushort."
                  " Conversion results in loss of data.");
    return static_cast<ushort>(toInt());
  }

  uchar toChar() const {
    static_assert(N <= sizeof(uchar),
                  "This data is larger than uchar."
                  " Conversion results in loss of data.");
    return static_cast<uchar>(toShort());
  }

  bool toBool() const {
    static_assert(N <= sizeof(bool),
                  "This data is larger than bool."
                  " Conversion results in loss of data.");
    return static_cast<bool>(leftovers.getData());
  }

};

} // End namespace BitOps

#endif // NYBITBYTE_H_

