/**
 * x2048/entryPoint.cpp
 */

#include <include/OsCompatibility.h>
#include <x2048/generic/x2048App.h>

dllExport amb::App* create_app() { //
  return new x2048::x2048App;
}
