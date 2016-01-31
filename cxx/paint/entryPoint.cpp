/**
 * paint/entryPoint.cpp
 */

#include <include/OsCompatibility.h>
#include <paint/PaintApp.h>

dllExport amb::App* create_app()
{
   return new paint::PaintApp;
}
