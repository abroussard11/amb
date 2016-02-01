/**
 * Util/fsLinux.h
 */

#ifndef UTIL_FSLINUX_H_
#define UTIL_FSLINUX_H_

#include <sys/stat.h>
#include <cerrno>

namespace Util {

static int linux_mkdir(std::string dirName) {
  const int dir_err =
      mkdir(dirName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (dir_err == -1) {
    if (errno == EEXIST) {
      // directory already exists, we're ok
    } else {
      throw AmbException("Error creating directory");
    }
  }
  return dir_err;
};

}  // End namespace Util

#endif  // UTIL_FSLINUX_H_
