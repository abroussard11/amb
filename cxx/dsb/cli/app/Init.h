/**
 * dsb/cli/app/Init.h
 */

#ifndef DSB_CLI_INIT_H_
#define DSB_CLI_INIT_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class Init : public CmdHandler {
 public:
  Init() = default;
  virtual ~Init() = default;

  static CmdHandler::Ptr make_handler();
  virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

}  // End namespace cli
}  // End namespace dsb

#endif  // DSB_CLI_INIT_H_
