/**
 * bldsh/generic/CmdLineParser.h
 */

#ifndef BLDSH_CMDLINEPARSER_H_
#define BLDSH_CMDLINEPARSER_H_

#include <bldsh/generic/bldsh_vars.h>

namespace bldsh {

bldsh_vars parseCmdLine(int argc, const char** argv);

} // End namespace bldsh

#endif // BLDSH_CMDLINEPARSER_H_

