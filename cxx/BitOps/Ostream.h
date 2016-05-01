/**
 * BitOps/Ostream.h
 */

#ifndef BITOPS_OSTREAM_H_
#define BITOPS_OSTREAM_H_

#include <cassert>
#include <iostream>
#include <vector>
#include <include/OsCompatibility.h>
#include <BitOps/bitops.h>
#include <BitOps/Int8.h>

namespace BitOps {

class Ostream {
 public:
  Ostream()
      : _buf(),  //
        _bit(0),
        _byte(0) {
    _buf.push_back(0);
  }

  virtual ~Ostream() = default;

  template <class T, if_not_integral_t<T> = 0>
  friend Ostream& operator<<(Ostream& buf, T& t) {
    static_assert(std::is_integral<T>::value, "make your own overload");
    return buf;
  }

  template <std::uint32_t N>
  Ostream& operator<<(Int8<N>& t) {
    std::uint16_t shiftedBits = t.getBits() << (8 - _bit);
    std::uint8_t hiByte = static_cast<std::uint8_t>(shiftedBits >> 8);
    _buf.at(_byte) |= hiByte;
    _bit += Int8<N>::NUM_BITS;
    if (_bit >= 8) {
      _bit %= 8;
      _byte++;
      std::uint8_t loByte = static_cast<std::uint8_t>(shiftedBits);
      _buf.push_back(loByte);
    }
    return *this;
  }

  template <class stdint, if_integral_t<stdint> = 0>
  Ostream& operator<<(stdint& x) {
    std::size_t int_size = sizeof(stdint);
    for(int i = 0; i < int_size; ++i) {
      Int8<8> byte(static_cast<std::uint8_t>(x >> (8 * i)));
      operator<<(byte);
    }
    return *this;
  }

  Ostream& operator<<(bool x) {
    Int8<1> byte;
    byte.setData(x);
    return *this << byte;
  }

  const std::uint8_t* data() const {
    return _buf.data();
  }

  std::size_t size() const { //
    return _buf.size();
  }

  std::uint32_t getBitPos() const {  //
    return _bit;
  }

  std::uint32_t getBytePos() const {  //
    return _byte;
  }

  std::uint8_t at(std::uint32_t index) const {
    return _buf.at(index);
  }

 private:
  std::vector<std::uint8_t> _buf;
  std::uint32_t _bit;
  std::uint32_t _byte;
};

}  // End namespace BitOps

#endif  // BITOPS_BUFFER_H_

