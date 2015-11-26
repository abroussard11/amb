/*
 * paint/exe/main.cpp
 */

#include <amb/App.h>
#include <Util/CommandLine.h>
#include <include/OsCompatibility.h>

// create_app() must be defined in the dll linked
// with this executable
dllImport amb::App* create_app();

int main(int argc, const char** argv)
{
   // Initialize command line data structure
   auto cmdLine = Util::CommandLine::parse(argc, argv);

   // load the dynamically-linked app
   auto _app = create_app();

   // Run the application
   _app->runApplication(cmdLine);
};
