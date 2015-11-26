/**
 * dsb/cli/app/List.cpp
 */

#include <dsb/cli/app/List.h>

namespace dsb {
namespace cli {

CmdHandler::Ptr List::make_handler()
{
   return std::make_unique<List>();
}

void List::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine)
{
   std::cout << "commanded list" << std::endl;
}

} // End namespace cli
} // End namespace dsb
