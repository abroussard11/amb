/**
 * MultiByteValue.cpp
 */

#include <tests/BitOps/MultiByteValue.h>

namespace BitOps {

MultiByteValue::MultiByteValue()
    : _x(0), _byte1(), _byte2(), _byte3(), _byte4() {
  // Empty
}

void MultiByteValue::setValue(uint x) {
  _x = x;
  _byte1.setData(static_cast<uchar>(x >> (8 * 3)));
  _byte2.setData(static_cast<uchar>(x >> (8 * 2)));
  _byte3.setData(static_cast<uchar>(x >> (8 * 1)));
  _byte4.setData(static_cast<uchar>(x >> (8 * 0)));
}

Ostream& operator<<(Ostream& buf, MultiByteValue& mbv) { //
  buf << mbv._byte1
      << mbv._byte2
      << mbv._byte3
      << mbv._byte4;
  return buf;
}

Istream& operator>>(Istream& buf, MultiByteValue& mbv) {
  buf >> mbv._byte1
      >> mbv._byte2
      >> mbv._byte3
      >> mbv._byte4;
  return buf;
}

} // End namespace BitOps

