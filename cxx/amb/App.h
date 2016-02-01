/**
 * amb/App.h
 */

#ifndef AMB_APP_H_
#define AMB_APP_H_

#include <memory>
#include <Util/CommandLine.h>

namespace amb {

/**
 * Pure Virtual interface for Applications
 */
class App {
 public:
  using Ptr = std::unique_ptr<App>;
  virtual ~App() = default;

  virtual void runApplication(Util::CommandLine::Data cmdLine) = 0;
};

}  // End namespace amb

#endif  // AMB_APP_H_
