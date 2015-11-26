/**
 * dsb/cli/app/Rm.h
 */

#ifndef DSB_CLI_RM_H_
#define DSB_CLI_RM_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class Rm : public CmdHandler
{
public:
   Rm();
   virtual ~Rm() = default;

   static CmdHandler::Ptr make_handler();
   virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

} // End namespace cli
} // End namespace dsb

#endif // DSB_CLI_RM_H_
