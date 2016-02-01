/**
 * dsb/cli/app/List.h
 */

#ifndef DSB_CLI_LIST_H_
#define DSB_CLI_LIST_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class List : public CmdHandler {
 public:
  List() = default;
  virtual ~List() = default;

  static CmdHandler::Ptr make_handler();
  virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

}  // End namespace cli
}  // End namespace dsb

#endif  // DSB_CLI_LIST_H_
