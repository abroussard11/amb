/**
 * Util/fs.h
 */

#ifndef UTIL_FS_H_
#define UTIL_FS_H_

#include <Util/AmbException.h>

#ifdef WIN32
#include <Util/fsWindows.h>
#else
#include <Util/fsLinux.h>
#endif

namespace Util {

// throws AmbException
static int mkdir(std::string dirName) {
#ifdef WIN32
  return Util::win_mkdir(dirName);
#else
  return Util::linux_mkdir(dirName);
#endif
};

}  // End namespace Util

#endif  // UTIL_DLL_H_
