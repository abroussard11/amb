/**
 * tests/DsbUnitTest.cpp
 */

#include <tests/DsbUnitTest.h>

#include <cstdio>
#include <fstream>

#include <dsb/gui/app/DsbApp.h>
#include <dsb/cli/app/DsbApp.h>
#include <dsb/generic/ProjectFile.h>
#include <dsb/gui/center/PanelCenter.h>
#include <dsb/gui/left/Button.h>
#include <dsb/gui/left/PanelLeft.h>
#include <dsb/gui/right/PanelRight.h>
#include <dsb/gui/right/ActivityList.h>

namespace tests {

void DsbUnitTest::testRoutine() {
  constructorTest<dsb::gui::DsbApp>();
  constructorTest<dsb::cli::DsbApp>();
  constructorTest<dsb::ProjectFile>();
  constructorTest<dsb::gui::left::Button>();

  auto videoMode = sf::VideoMode::getDesktopMode();
  constructorTest<dsb::gui::left::PanelLeft>(videoMode);
  constructorTest<dsb::gui::center::PanelCenter>(videoMode);
  constructorTest<dsb::gui::right::PanelRight>(videoMode);
  constructorTest<dsb::gui::right::ActivityList>();

  // private test methods
  testProjectFile();
}

void DsbUnitTest::testProjectFile() {
  auto act1 = dsb::ActivityMsg();
  act1.name = "one";
  act1.desc = "two";
  act1.LU = "three";
  act1.UC = "four";
  act1.QU = "five";
  act1.total = "six";

  auto act2 = dsb::ActivityMsg();
  act2.name = "1";
  act2.desc = "2";
  act2.LU = "3";
  act2.UC = "4";
  act2.QU = "5";
  act2.total = "6";

  auto filename = std::string("test.dsb");
  auto proj1 = dsb::ProjectFile();
  proj1.name = "proj1";
  proj1.activities.push_back(act1);
  proj1.activities.push_back(act2);
  std::ofstream ofs(filename.c_str(), std::ofstream::out);
  if (ofs.is_open()) {
    proj1.serialize(ofs);
    ofs.close();
  }

  auto proj2 = dsb::ProjectFile();
  proj2.name = "proj2";
  std::ifstream ifs(filename.c_str(), std::ifstream::in);
  if (ifs.is_open()) {
    proj2.deserialize(ifs);
    ifs.close();
  }

  auto proj3 = dsb::ProjectFile();
  proj3 = proj2;
  proj3.name = "proj3";

  requireEqual(proj1, proj2);
  requireEqual(proj3, proj2);

  // cleanup the test file
  remove(filename.c_str());
}

}  // End namespace tests
