/**
 * dsb/cli/app/DsbApp.cpp
 */

#include <dsb/cli/app/DsbApp.h>

//#include <dirent.h> // at /usr/include/dirent.h'
#include <fstream>
#include <dsb/cli/app/Help.h>
#include <dsb/cli/app/Add.h>
#include <dsb/cli/app/Init.h>
#include <dsb/cli/app/List.h>
#include <dsb/cli/app/Open.h>

namespace dsb {
namespace cli {

DsbApp::DsbApp()
    : _proj(),  //
      _cmdHandlers() {
  addHandler<Help>("help");
  addHandler<Help>("-help");
  addHandler<Help>("--help");
  addHandler<Help>("-h");

  addHandler<Add>("add");
  addHandler<Init>("init");
  addHandler<List>("list");
  addHandler<Open>("open");
}

void DsbApp::runApplication(Util::CommandLine::Data cmdLine) {
  auto itr = _cmdHandlers.find(cmdLine.at(0).option);
  if (itr != _cmdHandlers.end()) {
    itr->second->processCmd(_proj, cmdLine);
  } else {
    // Unhandled cmd line option
    std::cout << "cmd not found" << std::endl;
  }
}

}  // End namespace cli
}  // End namespace dsb
