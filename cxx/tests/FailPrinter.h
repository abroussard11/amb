/**
 * tests/FailPrinter.h
 */

#ifndef TESTS_FAILPRINTER_H_
#define TESTS_FAILPRINTER_H_

#include <iostream>
#include <include/OsCompatibility.h>

template <class T, class U>
class FailPrinter {
 public:
  FailPrinter(T t, U u) : _t(t), _u(u) {
    // Empty
  }
  virtual ~FailPrinter() = default;

  friend std::ostream& operator<<(std::ostream& os,
                                  FailPrinter<T, U>& printer) {
    return os << "  Reason [" << printer._t << " != " << printer._u << " ]";
  }

 private:
  T _t;
  U _u;
};

template <>
class FailPrinter<bool, bool> {
 public:
  FailPrinter(bool t, bool u) : _t(t), _u(u) {
    // Empty
  }
  virtual ~FailPrinter() = default;
  friend std::ostream& operator<<(std::ostream& os,
                                  FailPrinter<bool, bool>& printer) {
    return os << "  Reason [" << std::boolalpha << printer._t
              << " != " << printer._u << " ]";
  }

private:
  bool _t;
  bool _u;
};

template <>
class FailPrinter<char, int> {
 public:
  FailPrinter(char t, int u) : _t(t), _u(u) {
    // Empty
  }
  virtual ~FailPrinter() = default;
  friend std::ostream& operator<<(std::ostream& os,
                                  FailPrinter<char, int>& printer) {
    return os << "  Reason [" << (int)printer._t << " != " << printer._u
              << " ]";
  }

 private:
  char _t;
  int _u;
};

template <>
class FailPrinter<uchar, int> {
 public:
  FailPrinter(uchar t, int u) : _t(t), _u(u) {
    // Empty
  }
  virtual ~FailPrinter() = default;
  friend std::ostream& operator<<(std::ostream& os,
                                  FailPrinter<uchar, int>& printer) {
    return os << "  Reason [" << (int)printer._t << " != " << printer._u
              << " ]";
  }

 private:
  uchar _t;
  int _u;
};
#endif  // TESTS_FAILPRINTER_H_

