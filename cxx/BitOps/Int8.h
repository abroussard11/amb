/**
 * BitOps/Int.h
 */

#ifndef BITOPS_INT_H_
#define BITOPS_INT_H_

#include <iostream>
#include <include/OsCompatibility.h>

namespace BitOps {

template <std::uint32_t N>
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
  Int8(const Int8& rhs) = default;
  explicit Int8(const std::uint8_t& data)
      : _data(data)  //
  {
    // Empty
  }
  ~Int8() = default;

  void setData(std::uint8_t data) {  //
    _data = data;
  }

  auto getData() const {  //
    return _data;
  }

  void setBits(std::uint8_t byte) {
    setData(static_cast<std::uint8_t>(byte >> (8 - NUM_BITS)));
  }

  std::uint8_t getBits() const {
    return static_cast<std::uint8_t>(_data << (8 - NUM_BITS));
  }

  bool operator==(const Int8<N>& other) {
    return _data == other._data;
  }

  bool operator!=(const Int8<N>& other) {
    return !(operator==(other));
  }

  friend std::ostream& operator<<(std::ostream& os, Int8<NUM_BITS>& int_n) {
    return os << int_n.getBits();
  }

 private:
  std::uint8_t _data;
};

}  // End namespace BitOps

#endif  // INT_H_
