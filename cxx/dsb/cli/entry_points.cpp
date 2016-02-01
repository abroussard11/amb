/**
 * dsb/gui/entry_points.cpp
 */

#include <dsb/cli/app/DsbApp.h>
#include <include/OsCompatibility.h>

dllExport amb::App::Ptr create_cli_app() {
  return std::make_unique<dsb::cli::DsbApp>();
}
