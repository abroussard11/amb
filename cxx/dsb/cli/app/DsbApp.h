/**
 * dsb/cli/app/DsbApp.h
 */

#ifndef DSB_CLI_DSBAPP_H_
#define DSB_CLI_DSBAPP_H_

#include <map>
#include <string>
#include <amb/CliApp.h>
#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class DsbApp : public amb::CliApp {
 public:
  DsbApp();
  virtual ~DsbApp() = default;

  virtual void runApplication(Util::CommandLine::Data cmdLine);

 private:
  ProjectFile _proj;
  std::map<std::string, CmdHandler::Ptr> _cmdHandlers;

  template <typename T>
  void addHandler(std::string cmd) {
    _cmdHandlers[cmd] = std::make_unique<T>();
  }
};

}  // End namespace cli
}  // End namespace dsb

#endif  // DSB_CLI_DSBAPP_H_
