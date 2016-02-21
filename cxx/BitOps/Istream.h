/**
 * BitOps/Istream.h
 */

#ifndef BITOPS_ISTREAM_H_
#define BITOPS_ISTREAM_H_

#include <iostream>
#include <cassert>
#include <include/OsCompatibility.h>
#include <BitOps/Int8.h>

namespace BitOps {

class Istream {
 public:
  enum { SIZE = 128 };

  Istream()
      : _buf(),      //
        _length(0),  //
        _bit(0),     //
        _byte(0) {
    // Empty
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
    ushort widebyte = concat(_buf[_byte], _buf[_byte+1]);
    uchar byte = slice8(widebyte, _bit);
    t.setBits(byte);
    _bit += Int8<N>::NUM_BITS;
    if (_bit >= 8) {
      _bit %= 8;
      _byte++;
    }
    return *this;
  }

  uchar* buf() {  //
    return _buf;
  }

  uint getBitPos() const {  //
    return _bit;
  }

  uint getBytePos() const {  //
    return _byte;
  }

  uchar at(uint index) const {  //
    assert(index < SIZE);
    return _buf[index];
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
  uchar _buf[SIZE];
  ushort _length;
  uint _bit;
  uint _byte;
};

}  // End namespace BitOps

#endif  // BITOPS_BUFFER_H_

