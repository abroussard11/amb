/**
 * dsb/cli/app/Help.h
 */

#ifndef DSB_CLI_HELP_H_
#define DSB_CLI_HELP_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class Help : public CmdHandler
{
public:
   Help() = default;
   virtual ~Help() = default;

   static CmdHandler::Ptr make_handler();
   virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

} // End namespace cli
} // End namespace dsb

#endif // DSB_CLI_HELP_H_
