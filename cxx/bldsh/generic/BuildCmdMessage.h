/**
 * bldsh/generic/BuildCmdMessage.h
 */

#ifndef BUILD_SHELL_BUILDCMDMESSAGE_H_
#define BUILD_SHELL_BUILDCMDMESSAGE_H_

#include <string>
#include <vector>

namespace bldsh {

class BuildCmdMessage {
 public:
  BuildCmdMessage();
  virtual ~BuildCmdMessage() = default;

 private:
  std::vector<std::string> env;
  std::string buildCommand;
};

} // End namespace bldsh

#endif // BUILD_SHELL_BUILDCMDMESSAGE_H_

