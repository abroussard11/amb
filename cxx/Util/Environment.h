/**
 * Util/Environment.h
 */

#ifndef AMB_UTIL_ENVIRONMENT_H_
#define AMB_UTIL_ENVIRONMENT_H_

#include <vector>
#include <unistd.h>

namespace Util {

class Environment {
 public:
  static std::string get(std::string varName) {
    std::string envpair = varName;
    std::string varValue(getenv(varName.c_str()));
    envpair += "=" + varValue;
    return envpair;
  }
  static std::vector<std::string> getAllVars() {
    std::vector<std::string> envVars;
    for (int i = 0; environ[i] != nullptr; i++) {
      envVars.push_back(std::string(environ[i]));
    }
    return envVars;
  }
};

} // End namespace Util

#endif // AMB_UTIL_ENVIRONMENT_H_
