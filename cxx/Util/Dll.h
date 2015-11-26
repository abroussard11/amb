/**
 * Util/Dll.h
 */

#ifndef UTIL_DLL_H_
#define UTIL_DLL_H_

#ifdef WIN32
#   include <Util/DllUtilWindows.h>
#else
#   include <Util/DllUtilLinux.h>
#endif

namespace Util {

class Dll
{
public:
   Dll() = delete;
   virtual ~Dll() = default;

   template <typename T>
   static std::unique_ptr<T> create(std::string libName)
   {
      return create<T>(libName, "create");
   }

   template <typename T>
   static std::unique_ptr<T> create(std::string libName, std::string fnName)
   {
   #ifdef WIN32
      return Util::DllUtilWindows::createClass<T>(libName, fnName);
   #else
      return DllUtilLinux::createClass<T>(libName, fnName);
   #endif
   }
};

} // End namespace Util

#endif // UTIL_DLL_H_
