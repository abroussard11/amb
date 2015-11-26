/**
 * dsb/cli/app/Rm.cpp
 */

#include <dsb/cli/app/Rm.h>

namespace dsb {
namespace cli {

CmdHandler::Ptr Rm::make_handler()
{
   return std::make_unique<Rm>();
}

void Rm::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine)
{
   std::cout << "commanded list" << std::endl;
}


} // End namespace cli
} // End namespace dsb
