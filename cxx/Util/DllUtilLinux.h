/**
 * Util/DllUtilLinux.h
 */

#ifndef UTIL_DLLUTILLINUX_H_
#define UTIL_DLLUTILLINUX_H_

#include <dlfcn.h>

#include <iostream>
#include <memory>
#include <string>
#include <Util/AmbException.h>

namespace Util {

class DllUtilLinux {
 public:
  DllUtilLinux() = delete;
  virtual ~DllUtilLinux() = default;

  template <typename T>
  static std::unique_ptr<T> createClass(std::string libName,
                                        std::string fnName) {
    if (libName == "") {
      throw AmbException("Cannot load library. Library name not given");
    }
    auto handle = dlopen(libName.c_str(), RTLD_NOW);

    if (handle == NULL) {
      throw AmbException(dlerror());
    }
    dlerror();  // clear the dl errors (probably not necessary)

    typedef T* creatorFn();
    auto fnSymbol = dlsym(handle, fnName.c_str());
    auto makeClass = reinterpret_cast<creatorFn*>(fnSymbol);
    auto createdClass = std::unique_ptr<T>(makeClass());

    if (createdClass.get() == nullptr) {
      throw AmbException("AmbException: Could not find symbol (" + fnName +
                         ") in lib (" + libName + ")");
    }

    return std::move(createdClass);
  }
};

}  // End namespace Util

#endif  // UTIL_DLLUTILLINUX_H_
