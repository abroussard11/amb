/**
 * dsb/cli/app/Add.cpp
 */

#include <dsb/cli/app/Add.h>

namespace dsb {
namespace cli {

void Add::processCmd(ProjectFile& proj, Util::CommandLine::Data& cmdLine) {
  Repository repo;
  if (repo.isValid()) {
    std::cout << "commanded add" << std::endl;
  } else {
    std::cout << "Repo not valid" << std::endl;
  }
}

}  // End namespace cli
}  // End namespace dsb
