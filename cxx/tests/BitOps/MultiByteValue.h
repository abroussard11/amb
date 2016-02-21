/**
 * MultiByteValue.h
 */

#ifndef MULTIBYTEVALUE_H_
#define MULTIBYTEVALUE_H_

#include <BitOps/Int8.h>
#include <BitOps/Istream.h>
#include <BitOps/Ostream.h>

namespace BitOps {

class MultiByteValue {
 public:
  MultiByteValue();
  virtual ~MultiByteValue() = default;

  void setValue(uint x);
  uint getValue() const { //
    return _x;
  }
  uchar getByte1() const { return _byte1.getData(); }
  uchar getByte2() const { return _byte2.getData(); }
  uchar getByte3() const { return _byte3.getData(); }
  uchar getByte4() const { return _byte4.getData(); }

  friend Ostream& operator<<(Ostream& buf, MultiByteValue& mbv);
  friend Istream& operator>>(Istream& buf, MultiByteValue& mbv);

 private:
  uint _x;
  Int8<8> _byte1;
  Int8<8> _byte2;
  Int8<8> _byte3;
  Int8<8> _byte4;
};

}  // End namespace BitOps

#endif  // MULTIBYTEVALUE_H_

