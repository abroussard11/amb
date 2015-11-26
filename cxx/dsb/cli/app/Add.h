/**
 * dsb/cli/app/Add.h
 */

#ifndef DSB_CLI_ADD_H_
#define DSB_CLI_ADD_H_

#include <dsb/cli/app/CmdHandler.h>

namespace dsb {
namespace cli {

class Add : public CmdHandler
{
public:
   Add() = default;
   virtual ~Add() = default;

   virtual void processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine);
};

} // End namespace cli
} // End namespace dsb

#endif // DSB_CLI_ADD_H_
