/**
 * BuildShell/BuildShell.cpp
 */

#include <algorithm>
#include <iostream>
#include <Util/Environment.h>
#include <Util/CommandLine.h>

struct main_vars {
  std::vector<std::string> env;
  std::string buildCommand;
};

void printActualCommandLine(int argc, const char** argv) {
  std::cout << "Actual commad line reads as:" << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << " ";
  }
  std::cout << std::endl;
}

main_vars parseCommandLine(int argc, const char** argv) {
  main_vars mainvars;
  auto clargs = Util::CommandLine::parse(argc, argv);
  for (auto& arg : clargs) {
    if (arg.option == "-e") {
      auto valBegin = begin(arg.values);
      auto valEnd = end(arg.values);
      auto envInserter = back_inserter(mainvars.env);
      std::transform(valBegin, valEnd, envInserter, &Util::Environment::get);
    }
    else if (arg.option == "-c") {
      mainvars.buildCommand = arg.values.at(0);
    }
  }
  return mainvars;
}

int main(int argc, const char** argv) {

  printActualCommandLine(argc, argv);

  auto clargs = Util::CommandLine::parse(argc, argv);
  std::cout << "BuildShell:" << clargs;
  std::cout << std::endl;

  main_vars mainvars = parseCommandLine(argc, argv);

  std::cout << "mainvars:" << std::endl;
  std::cout << "  env:" << std::endl;
  for (auto& e : mainvars.env) {
    std::cout << e << std::endl;
  }
  std::cout << "  buildCommand:" << std::endl;
  std::cout << mainvars.buildCommand << std::endl;

  return 0;
}
