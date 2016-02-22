/**
 * Util/CommandLine.cpp
 */

#include <iostream>
#include <Util/CommandLine.h>

namespace Util {

CommandLine::Data CommandLine::parse(int argc, const char** argv) {
  CommandLine::Data options;
  std::vector<std::string> commandLineArgs(argv, argv + argc);

  // We start at i = 1 because argv[0] is the program name
  for (int i = 1; i < argc; ++i) {
    CommandLineOption clo;
    std::string arg = commandLineArgs.at(i);

    if (isSingleCharacterFlag(arg)) {
      // -f val1 val2 val3...
      clo.option = arg;
      int j = i + 1;
      while ((j < argc) && (commandLineArgs.at(j).at(0) != '-')) {
        clo.values.push_back(commandLineArgs.at(j));
        ++j;
      }
      i = j - 1;
    } else if (isMultiCharacterFlag(arg)) {
      // --flag=value
      std::size_t loc = arg.find('=');
      clo.option = arg.substr(0, loc);
      if (loc != std::string::npos) {
        clo.values.push_back(arg.substr(loc + 1, std::string::npos));
      }
    } else {
      // cmd val1 val2 val3...
      clo.option = arg;
      int j = i + 1;
      while ((j < argc) && (commandLineArgs.at(j).at(0) != '-')) {
        clo.values.push_back(commandLineArgs.at(j));
        ++j;
      }
      i = j - 1;
    }
    options.push_back(clo);
  }

  return options;
}

bool CommandLine::isSingleCharacterFlag(const std::string& arg) {
  return (arg.at(0) == '-' && arg.at(1) != '-');
}

bool CommandLine::isMultiCharacterFlag(const std::string& arg) {
  return (arg.substr(0, 2) == "--");
}

}  // End namespace Util

std::ostream& operator<<(std::ostream& os, const Util::CommandLine::Data& data) {
  os << "{";
  for(auto d : data)
    os << d;
  os << "}";
  return os;
}
