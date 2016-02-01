/**
 * Util/Log.h
 */

#ifndef UTIL_LOG_H_
#define UTIL_LOG_H_

#include <iostream>
#include <string>

namespace Util {

#ifdef WIN32
static const auto CONSOLE_DEFAULT = "";
static const auto BOLD = "";
static const auto GREEN_FG = "";
static const auto GREEN_BG = "";
static const auto RED_FG = "";
static const auto RED_BG = "";
static const auto B_RED_BG = "";
static const auto BLUE_BG = "";
static const auto CYAN_BG = "";
static const auto YELLOW_BG = "";

static const auto DEBUG_PREFIX = "DEBUG ";
static const auto INFO_PREFIX = "INFO ";
static const auto WARN_PREFIX = "WARN ";
static const auto ERROR_PREFIX = "ERROR ";
#else
static const auto CONSOLE_DEFAULT = "\033[0;39m";
static const auto BOLD = "\033[1;39m";
static const auto GREEN_FG = "\033[0;32m";
static const auto GREEN_BG = "\033[42m";
static const auto RED_FG = "\033[0;31m";
static const auto RED_BG = "\033[41m";
static const auto B_RED_BG = "\033[1;41m";
static const auto BLUE_BG = "\033[1;44m";
static const auto CYAN_BG = "\033[1;46m";
static const auto YELLOW_BG = "\033[1;43m";

static const auto DEBUG_PREFIX = "\033[1;44mDEBUG\033[0;39m ";
static const auto INFO_PREFIX = "\033[1;42mINFO\033[0;39m ";
static const auto WARN_PREFIX = "\033[1;43mWARNING\033[0;39m ";
static const auto ERROR_PREFIX = "\033[1;41mERROR\033[0;39m ";
#endif

class Log {
 public:
  Log() = default;
  virtual ~Log() = default;

  // expansion template
  template <typename T, typename... ARGS>
  static void expandLog(std::ostream& os, T t, ARGS... args) {
    os << t;
    expandLog(os, args...);
  }

  // template specialization
  static void expandLog(std::ostream& os) { os << std::endl; }

  template <typename T, typename... ARGS>
  static void info(T t, ARGS... args) {
    std::cout << INFO_PREFIX << CONSOLE_DEFAULT << t;
    expandLog(std::cout, args...);
  }

  static void debugWrapper(std::string function, int line, std::string msg);
  static void warnWrapper(std::string function, int line, std::string msg);
  static void errorWrapper(std::string function, int line, std::string msg);
};

}  // End namespace Util

#ifdef WIN32
#define __PRETTY_FUNCTION__ ""
#endif

// If you ever want to use the File name in the log output, here's how we did it
// once
// debugWrapper(__FILE__, __PRETTY_FUNCTION__, __LINE__, msg)

#define debug(msg) debugWrapper(__PRETTY_FUNCTION__, __LINE__, msg)
#define warn(msg) warnWrapper(__PRETTY_FUNCTION__, __LINE__, msg)
#define error(msg) errorWrapper(__PRETTY_FUNCTION__, __LINE__, msg)

using namespace Util;

#endif  // UTIL_LOG_H_
