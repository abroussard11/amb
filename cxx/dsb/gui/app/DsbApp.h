/**
 * dsb/gui/app/DsbApp.h
 */

#ifndef DSB_GUI_APP_DSBAPP_H_
#define DSB_GUI_APP_DSBAPP_H_

#include <amb/GuiComponent.h>
#include <amb/GuiApp.h>
#include <amb/GuiAppDriver.h>

namespace dsb {
namespace gui {

class DsbApp : public amb::GuiApp
{
public:
   DsbApp();
   virtual ~DsbApp() = default;

   virtual void runApplication(Util::CommandLine::Data cmdLine) override;

protected:
   void onKeyPressed(sf::Event& event) override;

private:
   amb::GuiAppDriver _appDriver;
   sf::VideoMode _videoMode;
};

} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_APP_DSBAPP_H_
