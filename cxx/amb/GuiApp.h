/**
 * amb/GuiApp.h
 */

#ifndef AMB_GUIAPP_H_
#define AMB_GUIAPP_H_

#include <amb/App.h>
#include <amb/GuiComponent.h>

namespace amb {

/**
 * Pure Virtual interface for GUI Applications
 */
class GuiApp : public App, public amb::GuiComponent
{
public:
   GuiApp() = default;
   virtual ~GuiApp() = default;

};

} // End namespace amb

#endif // AMB_GUIAPP_H_
