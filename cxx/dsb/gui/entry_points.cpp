/**
 * dsb/gui/entry_points.cpp
 */

#include <dsb/gui/app/DsbApp.h>
#include <include/OsCompatibility.h>

dllExport amb::App::Ptr create_gui_app()
{
   return std::make_unique<dsb::gui::DsbApp>();
}
