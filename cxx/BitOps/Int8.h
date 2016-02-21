/**
 * BitOps/Int.h
 */

#ifndef BITOPS_INT_H_
#define BITOPS_INT_H_

#include <iostream>
#include <include/OsCompatibility.h>

namespace BitOps {

template <uint N>
class Int8 {
  static_assert(N <= 8, "N must be in range [0,8]");

 public:
  enum {  //
    MAX_BITS = 8
  };

  enum {
    NUM_BITS = N,
    NUM_BYTES = (N / MAX_BITS) + ((N % MAX_BITS) > 0 ? 1 : 0)
  };

  Int8() = default;
  virtual ~Int8() = default;

  Int8(const Int8& rhs) = default;

  void setData(uchar data) {  //
    _data = data;
  }

  auto getData() const {  //
    return _data;
  }

  void setBits(uchar byte) {
    setData(static_cast<uchar>(byte >> (8 - NUM_BITS)));
  }

  uchar getBits() const {
    return static_cast<uchar>(_data << (8 - NUM_BITS));
  }

  friend std::ostream& operator<<(std::ostream& os, Int8<NUM_BITS>& int_n) {
    return os << int_n.getBits();
  }

 private:
  uchar _data;
};

}  // End namespace BitOps

#endif  // INT_H_
