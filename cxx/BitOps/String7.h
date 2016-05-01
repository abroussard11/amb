/**
 * BitOps/String7.h
 */

#ifndef BITOPS_STRING7_H_
#define BITOPS_STRING7_H_

#include <string>
#include <vector>
#include <BitOps/Int8.h>
#include <BitOps/Ostream.h>

namespace BitOps {

class String7 {
 public:
  enum Special {  //
    EOS = 127
  };

  String7()
      : _eos(EOS),  //
        _str(),
        _bin() {
    // Empty
  }

  explicit String7(std::string str)
      : _eos(EOS),  //
        _str(str),
        _bin() {
    convertStr();
  }

  virtual ~String7() = default;

  String7& operator=(const String7& other) {
    _str = other._str;
    _bin = other._bin;
    return *this;
  }

  bool operator==(const String7& other) { //
    return _str == other._str;
  }

  void convertStr() {
    _bin.reserve(_str.size());
    for (const auto& c : _str) {
      Int8<7> bin;
      bin.setData(c);
      _bin.push_back(bin);
    }
    _bin.push_back(_eos);
  }

  std::string toStr() const { //
    return _str;
  }

  friend Ostream& operator<<(Ostream& buf, String7& str) {
    for (auto& c : str._bin) {
      buf << c;
    }
    return buf;
  }

  friend Istream& operator>>(Istream& buf, String7& str) {
    Int8<7> c;
    buf >> c;
    while (c != str._eos) {
      str._str.push_back(c.getData());
      buf >> c;
    }
    str.convertStr();
    return buf;
  }

  friend std::ostream& operator<<(std::ostream& os, String7& str) {
    return os << str._str;
  }

 private:
  const Int8<7> _eos;
  std::string _str;
  std::vector<Int8<7>> _bin;
};

}  // End namespace

#endif  // BITOPS_STRING7_H_
