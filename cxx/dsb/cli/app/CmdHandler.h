/**
 * dsb/cli/app/CmdHandler.h
 */

#ifndef DSB_CLI_CMDHANDLER_H_
#define DSB_CLI_CMDHANDLER_H_

#include <iostream> // TODO remove after testing

#include <memory>
#include <Util/CommandLine.h>
#include <dsb/generic/ProjectFile.h>

namespace dsb {
namespace cli {

class CmdHandler
{
public:
   using Ptr = std::unique_ptr<CmdHandler>;

   virtual ~CmdHandler() = default;

   virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine) = 0;
};

} // End namespace cli
} // End namespace dsb

#endif // DSB_CLI_CMDHANDLER_H_
