/**
 * dsb/cli/app/Open.h
 */

#ifndef DSB_CLI_OPEN_H_
#define DSB_CLI_OPEN_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class Open : public CmdHandler {
 public:
  Open() = default;
  virtual ~Open() = default;

  virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

}  // End namespace cli
}  // End namespace dsb

#endif  // DSB_CLI_OPEN_H_
