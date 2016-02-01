/*
 * UnitTest/ambUnitTest.cpp
 */

#include <iostream>
#include <memory>
#include <tests/MasterUnitTest.h>
#include <Util/Log.h>

int main(int argc, char** argv) {
  Util::Log::info("Loading the MasterUnitTest suite");

  //   int x[3] = {1,2,3};
  //
  //   for (int i = 0; i < 4; ++i)
  //   {
  //      std::cout << "x[" << i << "] = " << x[i] << std::endl;
  //   }

  tests::MasterUnitTest unitTest;
  unitTest.runTests();

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
