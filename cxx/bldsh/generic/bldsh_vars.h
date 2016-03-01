/**
 * bldsh/bldsh_vars.h
 */

#ifndef BLDSH_BLDSH_VARS_H_
#define BLDSH_BLDSH_VARS_H_

#include <string>
#include <vector>

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

#endif // BLDSH_BLDSH_VARS_H_
