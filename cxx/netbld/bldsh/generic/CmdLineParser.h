/**
 * bldsh/generic/CmdLineParser.h
 */

#ifndef BLDSH_CMDLINEPARSER_H_
#define BLDSH_CMDLINEPARSER_H_

#include <netbld/bldsh/generic/bldsh_vars.h>

namespace netbld {

bldsh_vars parseCmdLine(int argc, const char** argv);

} // End namespace netbld

#endif // BLDSH_CMDLINEPARSER_H_

