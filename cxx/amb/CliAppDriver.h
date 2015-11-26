/**
 * amb/CliAppDriver.h
 */

#ifndef AMB_CLIAPPDRIVER_H_
#define AMB_CLIAPPDRIVER_H_

#include <amb/AppDriver.h>

namespace amb {

class CliAppDriver : public AppDriver
{
public:
   CliAppDriver() = default;
   virtual ~CliAppDriver() = default;

   virtual void runApplication();
};

} // End namespace amb

#endif // AMB_CLIAPPDRIVER_H_
