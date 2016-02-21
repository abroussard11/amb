/*
 * UnitTest/ambUnitTest.cpp
 */

#include <iostream>
#include <memory>
#include <tests/MasterUnitTest.h>
#include <Util/CommandLine.h>
#include <Util/Log.h>

struct UnitTest_CmdLine {
   bool verbose;
   std::string test;

   UnitTest_CmdLine()
       : verbose(false),  //
         test() {
     // Empty
   }
};

int main(int argc, const char** argv) {
  auto options = Util::CommandLine::parse(argc, argv);

  UnitTest_CmdLine cmd_opts;
  for (auto& e : options) {
    if (e.option == "-v") {
      cmd_opts.verbose = true;
    }
    else if (e.option == "--test") {
      cmd_opts.test = e.values[0];
    }
  }

  tests::MasterUnitTest unitTest;
  unitTest.setVerbosity(cmd_opts.verbose);
  if (cmd_opts.test != "") {
    std::cout << "JUST RUNNING TEST CASE: " << cmd_opts.test << std::endl;
    unitTest.runTests(cmd_opts.test);
  }
  else {
    unitTest.runAllTests();
  }

  auto passes = unitTest.getSuccesses();
  auto fails = unitTest.getFails();

  using Util::Log;
  using namespace Util;
  std::cout << std::endl
            << "::: Testing complete :::" << std::endl
            << " Passed: " << GREEN_BG << passes << CONSOLE_DEFAULT << std::endl
            << " Failed: " << RED_BG << fails << CONSOLE_DEFAULT << std::endl;

  return fails;
};
