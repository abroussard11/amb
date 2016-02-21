/**
 * BitOps/Ostream.h
 */

#ifndef BITOPS_OSTREAM_H_
#define BITOPS_OSTREAM_H_

#include <cassert>
#include <iostream>
#include <include/OsCompatibility.h>
#include <BitOps/Int8.h>

namespace BitOps {

class Ostream {
 public:
 enum { SIZE=128 };

 Ostream()
     :  //
       _buf(),
       _length(0),
       _bit(0),
       _byte(0) {
   // Empty
 }

virtual ~Ostream() = default;

  template <class T>
  friend Ostream& operator<<(Ostream& buf, T& t) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    throw "\nYou need to creat your own overload for :"
          "\nOStream& operator<<(Ostream& buf, T& t)";
    return buf;
  }

  template <uint N>
  Ostream& operator<<(Int8<N>& t) {
    ushort shiftedBits = t.getBits() << (8 - _bit);
    uchar hiByte = static_cast<uchar>(shiftedBits >> 8);
    _buf[_byte] |= hiByte;
    _bit += Int8<N>::NUM_BITS;
    if (_bit >= 8) {
      _bit %= 8;
      _byte++;
      uchar loByte = static_cast<uchar>(shiftedBits);
      _buf[_byte] = loByte;
    }
    return *this;
  }

  Ostream& operator<<(uint x) {
    Int8<8> byte1;
    Int8<8> byte2;
    Int8<8> byte3;
    Int8<8> byte4;
    byte1.setData(static_cast<uchar>(x >> (8 * 3)));
    byte2.setData(static_cast<uchar>(x >> (8 * 2)));
    byte3.setData(static_cast<uchar>(x >> (8 * 1)));
    byte4.setData(static_cast<uchar>(x >> (8 * 0)));
    return *this << byte1 << byte2 << byte3 << byte4;
  }

  Ostream& operator<<(ushort x) {
    Int8<8> byte1;
    Int8<8> byte2;
    byte1.setData(static_cast<uchar>(x >> (8 * 1)));
    byte2.setData(static_cast<uchar>(x >> (8 * 0)));
    return *this << byte1 << byte2;
  }

  Ostream& operator<<(uchar x) {
    Int8<8> byte;
    byte.setData(x);
    return *this << byte;
  }

  Ostream& operator<<(bool x) {
    Int8<1> byte;
    byte.setData(x);
    return *this << byte;
  }

  uchar* buf() { // 
     return _buf;
  }

  uint getBitPos() const {  //
    return _bit;
  }

  uint getBytePos() const {  //
    return _byte;
  }

  uchar at(uint index) const {
    assert(index < SIZE);
    return _buf[index];
  }

 private:
  uchar _buf[SIZE];
  ushort _length;
  uint _bit;
  uint _byte;
};

}  // End namespace BitOps

#endif  // BITOPS_BUFFER_H_

