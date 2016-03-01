/**
 * BitOps/Istream.h
 */

#ifndef BITOPS_ISTREAM_H_
#define BITOPS_ISTREAM_H_

#include <iostream>
#include <cassert>
#include <vector>
#include <include/OsCompatibility.h>
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

  Istream(const uchar* buf, const uint size)
      : _buf(),  //
        _bit(0),
        _byte(0) {
    _buf.reserve(size);
    _buf.assign(buf, buf + size);
  }

  virtual ~Istream() = default;

  template <class T>
  friend Istream& operator>>(Istream& buf, T& t) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    throw "\nYou need to create your own overload for:"
          "\nIstream& operator>>(Istream& buf, T& t)";
    return buf;
  }

  template <uint N>
  Istream& operator>>(Int8<N>& t) {
    uchar currByte = _buf.at(_byte);
    uchar nextByte = 0;
    if (_buf.size() > _byte + 1) {
      nextByte = _buf.at(_byte + 1);
    }
    ushort widebyte = concat(currByte, nextByte);
    uchar byte = slice8(widebyte, _bit);
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

  uint getBitPos() const {  //
    return _bit;
  }

  uint getBytePos() const {  //
    return _byte;
  }

  uchar at(uint index) const {  //
    return _buf.at(index);
  }

  ushort concat(uchar left, uchar right) {  //
    return (left << 8) | right;
  }

  uchar slice8(ushort x, uint index) { // index is in [0,8]
    uchar not0 = ~0;   // 1111 1111
    ushort stamp = not0 << (8 - index); // 0000 0111 1111 1000
    ushort matches = x & stamp;         // 0000 0110 1011 1000
    uchar result = matches >> (8 - index); // 1101 0111
    return result;
  }

 private:
  std::vector<uchar> _buf;
  uint _bit;
  uint _byte;
};

}  // End namespace BitOps

#endif  // BITOPS_BUFFER_H_

