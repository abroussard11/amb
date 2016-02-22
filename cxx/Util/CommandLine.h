/**
 * Util/CommandLine.h
 */

#ifndef UTIL_COMMANDLINE_H_
#define UTIL_COMMANDLINE_H_

#include <Util/CommandLineOption.h>

namespace Util {

class CommandLine {
 public:
  using Data = std::vector<CommandLineOption>;

  virtual ~CommandLine() {}

  static Data parse(int argc, const char** argv);
  static bool isSingleCharacterFlag(const std::string& arg);
  static bool isMultiCharacterFlag(const std::string& arg);
};

}  // End namespace Util

std::ostream& operator<<(std::ostream& os, const Util::CommandLine::Data& data);

#endif  // UTIL_COMMANDLINE_H_
