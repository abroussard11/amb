/**
 * tests/std/typeinfo.cpp
 */

#include <typeinfo>
#include <cxxabi.h>
#include <tests/std/typeinfo_test.h>

void printTypeData() {
  int status;
  char* realname = abi::__cxa_demangle(typeid(std::typeinfo_test).name(), 0, 0, &status);
   std::cout << realname << std::endl;
   free(realname);
}
namespace std {

void typeinfo_test::testRoutine() {
  std::cout << "Hello\n";
  printTypeData();
}

} // End namespace std
