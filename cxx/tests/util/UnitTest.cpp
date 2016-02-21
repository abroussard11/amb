/**
 * tests/util/UnitTest.cpp
 */

#include <tests/util/UnitTest.h>

#include <Util/CommandLineOption.h>
#include <Util/CommandLine.h>
#include <Util/Dll.h>

namespace util {

void UnitTest::testRoutine() {
  constructorTest<AmbException>("test exception");
  constructorTest<Util::CommandLineOption>();

  // Create fake command line arguments
  // argc needs to be equal to the number of strings in argv
  int argc = 8;
  const char* argv[] = {"exec",          "--gui", "-s",      "1.2.3.4",
                        "ignored_value", "-l",    "libA.so", "--lib=libB.so"};

  // Parse the fake command line and dispatch the tokens
  auto cmdLine = Util::CommandLine::parse(argc, argv);
  requireEqual(cmdLine.at(0).option, "--gui");
  requireEqual(cmdLine.at(1).option, "-s");
  requireEqual(cmdLine.at(1).values.at(0), "1.2.3.4");
  requireEqual(cmdLine.at(1).values.at(1), "ignored_value");
  requireEqual(cmdLine.at(2).option, "-l");
  requireEqual(cmdLine.at(2).values.at(0), "libA.so");
  requireEqual(cmdLine.at(3).option, "--lib");
  requireEqual(cmdLine.at(3).values.at(0), "libB.so");

  int argc2 = 3;
  const char* argv2[] = {"dsb", "add", "something"};
  auto cmdLine2 = Util::CommandLine::parse(argc2, argv2);
  requireEqual(cmdLine2.at(0).option, "add");
  requireEqual(cmdLine2.at(0).values.at(0), "something");

  // TODO TEST: Dll
  // requireEqual(constructWithDllUtil(), true); // TODO

  // TODO TEST: Log
}

bool UnitTest::constructWithDllUtil() {
  bool success = true;
  try {
    // TODO Dll test
    // const std::string libName("libamb-plugins-Fun.so");
    // const std::string fnName("create");
  } catch (...) {
    success = false;
  }

  return success;
}

}  // End namespace util
