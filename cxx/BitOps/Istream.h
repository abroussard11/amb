/**
 * BitOps/Istream.h
 */

#ifndef BITOPS_ISTREAM_H_
#define BITOPS_ISTREAM_H_

#include <iostream>
#include <cassert>
#include <vector>
#include <include/OsCompatibility.h>
#include <BitOps/bitops.h>
#include <BitOps/Int8.h>

namespace BitOps {

class Istream {
 public:
  Istream()
      : _buf(),  //
        _bit(0),
        _byte(0) {
    // Empty
  }

  Istream(const std::uint8_t* buf, const std::uint32_t size)
      : _buf(),  //
        _bit(0),
        _byte(0) {
    _buf.reserve(size);
    _buf.assign(buf, buf + size);
  }

  virtual ~Istream() = default;

  template <class T, if_not_integral_t<T> = 0>
  friend Istream& operator>>(Istream& buf, T& t) {
    static_assert(std::is_integral<T>::value, "make your own overload");
    return buf;
  }

  template <std::uint32_t N>
  Istream& operator>>(Int8<N>& t) {
    std::uint8_t currByte = _buf.at(_byte);
    std::uint8_t nextByte = 0;
    if (_buf.size() > _byte + 1) {
      nextByte = _buf.at(_byte + 1);
    }
    std::uint16_t widebyte = concat(currByte, nextByte);
    std::uint8_t byte = slice8(widebyte, _bit);
    t.setBits(byte);
    _bit += Int8<N>::NUM_BITS;
    if (_bit >= 8) {
      _bit %= 8;
      _byte++;
    }
    return *this;
  }

  std::size_t size() { //
    return _buf.size();
  }

  std::uint32_t getBitPos() const {  //
    return _bit;
  }

  std::uint32_t getBytePos() const {  //
    return _byte;
  }

  std::uint8_t at(std::uint32_t index) const {  //
    return _buf.at(index);
  }

  std::uint16_t concat(std::uint8_t left, std::uint8_t right) {  //
    return (left << 8) | right;
  }

  std::uint8_t slice8(std::uint16_t x, std::uint32_t index) { // index is in [0,8]
    std::uint8_t not0 = ~0;   // 1111 1111
    std::uint16_t stamp = not0 << (8 - index); // 0000 0111 1111 1000
    std::uint16_t matches = x & stamp;         // 0000 0110 1011 1000
    std::uint8_t result = matches >> (8 - index); // 1101 0111
    return result;
  }

  Istream& operator>>(bool& x) {
    Int8<1> byte;
    operator>>(byte);
    x = byte.getData();
    return *this;
  }

  template <std::uint32_t> struct int2type {}; // idn ... found it on stackoverflow

  // recursive template
  template <class stdint, std::uint32_t N>
  stdint foreach_read(int2type<N>) {
    stdint x = 0;
    Int8<8> byte;
    operator>>(byte);
    x |= (static_cast<stdint>(byte.getData()) << (8 * (sizeof(stdint) - N)));
    return x |= foreach_read<stdint>(int2type<N - 1>());
  }

  // function overload for recursion terminator
  template <class stdint>
  stdint foreach_read(int2type<0>) {
    return static_cast<stdint>(0);
  }

  template <class stdint, typename std::enable_if<
                              std::is_integral<stdint>::value, int>::type = 0>
  Istream& operator>>(stdint& x) {
    x = 0;
    x |= foreach_read<stdint>(int2type<sizeof(stdint)>());
    return *this;
  }

 private:
  std::vector<std::uint8_t> _buf;
  std::uint32_t _bit;
  std::uint32_t _byte;
};

}  // End namespace BitOps

#endif  // BITOPS_BUFFER_H_

