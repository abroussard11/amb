/**
 * Util/fsWindows.h
 */

#ifndef UTIL_FSWINDOWS_H_
#define UTIL_FSWINDOWS_H_

#include <windows.h>

namespace Util {

static int win_mkdir(std::string dirName)
{
   int dir_err = CreateDirectory(dirName.c_str(), nullptr);
   if (dir_err == true)
   {
      throw AmbException("Error creating directory");
   }
   return static_cast<int>(dir_err);
};

} // End namespace Util

#endif // UTIL_FSWINDOWS_H_
