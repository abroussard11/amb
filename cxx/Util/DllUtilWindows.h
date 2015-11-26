/**
 * Util/DllUtilWindows.h
 */

#ifndef UTIL_DLLUTILWINDOWS_H_
#define UTIL_DLLUTILWINDOWS_H_

#include <windows.h>

#include <iostream>
#include <memory>
#include <string>
#include <Util/AmbException.h>

namespace Util {

class DllUtilWindows
{
public:
   DllUtilWindows() = delete;
   virtual ~DllUtilWindows() = default;

   template <typename T>
   static std::unique_ptr<T> createClass(std::string libName, std::string fnName)
   {
      auto handle = LoadLibrary(libName.c_str());

      if (handle == NULL)
      {
         throw AmbException("Error loading library" + libName);
      }

      typedef T* creatorFn();
      auto fnSymbol = GetProcAddress(handle, fnName.c_str());
      auto makeClass = reinterpret_cast<creatorFn*>(fnSymbol);
      auto createdClass = std::unique_ptr<T>(makeClass());

      if (createdClass.get() == nullptr)
      {
         throw AmbException("AmbException: Could not find symbol (" + fnName + ")"
                             + " in lib ("+ libName + ")");
      }

      return std::move(createdClass);
   }
};

} // End namespace Util

#endif // UTIL_DLLUTILWINDOWS_H_
