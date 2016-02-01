/**
 * dsb/cli/app/Help.cpp
 */

#include <dsb/cli/app/Help.h>

namespace dsb {
namespace cli {

CmdHandler::Ptr Help::make_handler() { return std::make_unique<Help>(); }

void Help::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine) {
  std::cout << "Help commanded" << std::endl;
}

}  // End namespace cli
}  // End namespace dsb
