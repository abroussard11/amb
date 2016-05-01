/**
 * netbld/bldsh/main.cpp
 */

#include <iostream>
#include <unistd.h>
#include <netbld/bldsh/generic/CmdLineParser.h>
#include <Util/ClientSocket.h>

int main(int argc, const char** argv) {
  netbld::bldsh_vars vars = netbld::parseCmdLine(argc, argv);

  std::cout << "START buildCommand: " << vars.buildCommand << "\n";

  Util::ClientSocket client("localhost", 50000);
  std::string reply;
  try {
    client << vars.toStr();
    client >> reply;
  } catch (...) {
    // Empty
    std::cout << "caught an error" << std::endl;
  }

  std::cout << "reply: " << reply << std::endl;
  std::cout << "END buildCommand: " << vars.buildCommand << "\n\n";
  return 0;
}
