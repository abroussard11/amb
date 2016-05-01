/**
 * Optional.h
 */

#ifndef BITOPS_OPTIONAL_H_
#define BITOPS_OPTIONAL_H_

#include <BitOps/Istream.h>
#include <BitOps/Ostream.h>

namespace BitOps {

template <class T>
class Optional {
 public:
  Optional()
      : _isValid(false),  //
        _value() {
    // Empty
  }

  explicit Optional(const T& t)
      : _isValid(true),  //
        _value(t) {
    // Empty
  }

  ~Optional() = default;

  Optional& operator=(const T& t) {
    set(t);
    return *this;
  }

  void set(const T& t) {
     _value = t;
     _isValid = true;
  }

  bool isValid() const { //
    return _isValid;
  }

  T get() const { //
    return _value;
  }

  friend Ostream& operator<<(Ostream& buf, Optional<T>& opt) {
    buf << opt._isValid;
    if (opt._isValid) {
      buf << opt._value;
    }
    return buf;
  }

  friend Istream& operator>>(Istream& buf, Optional<T>& opt) {
    buf >> opt._isValid;
    if (opt._isValid) {
      buf >> opt._value;
    }
    return buf;
  }

 private:
  bool _isValid;
  T _value;
};

} // End namespace BitOps

#endif // OPTIONAL_H_

