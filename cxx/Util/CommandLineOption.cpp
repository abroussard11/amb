/**
 * Util/CommandLineOption.cpp
 */

#include <Util/CommandLineOption.h>

std::ostream& operator<<(std::ostream& os, Util::CommandLineOption& clo) {
  os << "[" << clo.option;
  for (auto& s : clo.values) {
    os << ", " << s;
  }
  return os << "]";
}
