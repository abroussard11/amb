/**
 * amb/AppDriver.h
 */

#ifndef AMB_APPDRIVER_H_
#define AMB_APPDRIVER_H_

#include <memory>

namespace amb {

/**
 * Pure virtual interface for Application Drivers
 */
class AppDriver {
 public:
  using Ptr = std::unique_ptr<AppDriver>;
  virtual ~AppDriver() = default;

  virtual void runApplication() = 0;
};

}  // End namespace amb

#endif  // AMB_APPDRIVER_H_
