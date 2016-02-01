/*
 * exe/main.cpp
 */

#include <algorithm>
#include <iostream>
#include <amb/App.h>
#include <Util/CommandLine.h>

// create_app() must be defined in the .so linked
// with this executable
amb::App::Ptr create_gui_app();
amb::App::Ptr create_cli_app();

int main(int argc, const char** argv) {
  auto cmdLine = Util::CommandLine::parse(argc, argv);

  auto _app = amb::App::Ptr(nullptr);

  if (cmdLine.size() > 0) {
    // std::cout << "Creating CLI" << std::endl;
    _app = create_cli_app();
  } else {
    std::cout << "Creating GUI" << std::endl;
    _app = create_gui_app();
  }

  // Run the application
  _app->runApplication(cmdLine);
};
