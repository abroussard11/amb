/**
 * bldsh/generic/CmdLineParser.cpp
 */

#include <algorithm>
#include <bldsh/generic/CmdLineParser.h>
#include <Util/CommandLine.h>
#include <Util/Environment.h>

namespace bldsh {

bldsh_vars parseCmdLine(int argc, const char** argv) {
  bldsh_vars vars;
  auto clargs = Util::CommandLine::parse(argc, argv);
  for (auto& arg : clargs) {
    if (arg.option == "--env") {
      std::transform(begin(arg.values), end(arg.values),
                     back_inserter(vars.env), &Util::Environment::get);
    }
    else if (arg.option == "-c") {
      vars.buildCommand = arg.values.at(0);
    }
    else if (arg.option == "--master") {
      vars.master_hostname = arg.values.at(0);
    }
  }
  return vars;
}

} // End namespace bldsh
