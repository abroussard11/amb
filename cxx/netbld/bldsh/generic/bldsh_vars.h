/**
 * bldsh/bldsh_vars.h
 */

#ifndef NETBLD_BLDSH_BLDSH_VARS_H_
#define NETBLD_BLDSH_BLDSH_VARS_H_

#include <string>
#include <vector>

namespace netbld {

struct bldsh_vars {
  std::vector<std::string> env;
  std::string buildCommand;
  std::string master_hostname;
  std::string toStr() const {
    std::string ret;
    for (const auto& str : env) {
      ret += str;
    }
    ret += ", ";
    ret += buildCommand;
    return ret;
  }
};

} // End namespace netbld

#endif // BLDSH_BLDSH_VARS_H_
