/**
 * amb/CliApp.h
 */

#ifndef AMB_CLIAPP_H_
#define AMB_CLIAPP_H_

#include <memory>
#include <amb/App.h>

namespace amb {

/**
 * Pure Virtual interface for CLI Applications
 */
class CliApp : public App
{
public:
   using Ptr = std::unique_ptr<CliApp>;
   virtual ~CliApp() = default;
};

} // End namespace amb

#endif // AMB_CLIAPP_H_
