/**
 * Util/Log.cpp
 */

#include <iostream>
#include <Util/Log.h>

namespace Util {

void Log::debugWrapper(std::string function, int line, std::string msg) {
  // Get the substring of the pretty function that does not contain
  // return type information or input parameter information
  auto parenPos = function.find('(');
  auto pos = function.rfind(' ', parenPos) + 1;
  auto funcSubstr = function.substr(pos, parenPos - pos);

  std::clog << DEBUG_PREFIX << BOLD << funcSubstr << "():" << line << ": "
            << CONSOLE_DEFAULT << msg << std::endl;
}

void Log::warnWrapper(std::string function, int line, std::string msg) {
  // Get the substring of the pretty function that does not contain
  // return type information or input parameter information
  auto parenPos = function.find('(');
  auto pos = function.rfind(' ', parenPos) + 1;
  auto funcSubstr = function.substr(pos, parenPos - pos);

  std::cerr << WARN_PREFIX << BOLD << funcSubstr << "():" << line << ": "
            << CONSOLE_DEFAULT << msg << std::endl;
}

void Log::errorWrapper(std::string function, int line, std::string msg) {
  // Get the substring of the pretty function that does not contain
  // return type information or input parameter information
  auto parenPos = function.find('(');
  auto pos = function.rfind(' ', parenPos) + 1;
  auto funcSubstr = function.substr(pos, parenPos - pos);

  std::cerr << ERROR_PREFIX << BOLD << funcSubstr << "():" << line << ": "
            << CONSOLE_DEFAULT << msg << std::endl;
}

}  // End namespace Util
