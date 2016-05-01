/**
 * tests/BitOps/MultiByteValue.h
 */

#ifndef MULTIBYTEVALUE_H_
#define MULTIBYTEVALUE_H_

#include <include/OsCompatibility.h>
#include <BitOps/Int8.h>
#include <BitOps/Istream.h>
#include <BitOps/Ostream.h>

namespace BitOps {

class MultiByteValue {
 public:
  MultiByteValue();
  explicit MultiByteValue(const std::uint32_t& val);
  virtual ~MultiByteValue() = default;

  void setValue(std::uint32_t x);
  std::uint32_t getValue() const;

  std::uint8_t getByte1() const { return _byte1.getData(); }
  std::uint8_t getByte2() const { return _byte2.getData(); }
  std::uint8_t getByte3() const { return _byte3.getData(); }
  std::uint8_t getByte4() const { return _byte4.getData(); }

  friend Ostream& operator<<(Ostream& buf, MultiByteValue& mbv);
  friend Istream& operator>>(Istream& buf, MultiByteValue& mbv);

 private:
  std::uint32_t _x;
  Int8<8> _byte1;
  Int8<8> _byte2;
  Int8<8> _byte3;
  Int8<8> _byte4;
};

}  // End namespace BitOps

#endif  // MULTIBYTEVALUE_H_

