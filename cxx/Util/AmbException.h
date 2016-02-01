/**
 * Util/AmbException.h
 */

#ifndef UTIL_AMBEXCEPTION_H_
#define UTIL_AMBEXCEPTION_H_

class AmbException : public std::exception {
 public:
  AmbException() = default;
  AmbException(const std::string msg) : _msg(msg) {
    // Empty
  }

  virtual ~AmbException() = default;

  const char* what() const throw() { return _msg.c_str(); }

 private:
  const std::string _msg;
};

#endif  // UTIL_AMBEXCEPTION_H_
