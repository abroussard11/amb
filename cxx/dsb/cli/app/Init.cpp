/**
 * dsb/cli/app/Init.cpp
 */

#include <dsb/cli/app/Init.h>
#include <Util/Log.h>

namespace dsb {
namespace cli {

CmdHandler::Ptr Init::make_handler()
{
   return std::make_unique<Init>();
}

void Init::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine)
{
   Util::Log::debug("commanded init");

   Repository repo;
   if (repo.isValid())
   {
      Util::Log::info("Repo already initialized");
   }
   else
   {
      std::cout << "initializing" << std::endl;
      repo.initialize();
   }
}

} // End namespace cli
} // End namespace dsb
