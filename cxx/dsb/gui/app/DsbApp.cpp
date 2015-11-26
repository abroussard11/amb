/**
 * dsb/gui/app/DsbApp.cpp
 */

#include <dsb/gui/app/DsbApp.h>
#include <dsb/gui/center/PanelCenter.h>
#include <dsb/gui/left/PanelLeft.h>
#include <dsb/gui/right/PanelRight.h>
#include <dsb/gui/top/PanelTop.h>

namespace dsb {
namespace gui {

DsbApp::DsbApp() :
   GuiApp(), //
   _appDriver(), //
   _videoMode(sf::VideoMode::getDesktopMode())
{
   addComponent<left::PanelLeft>(_videoMode);
   addComponent<center::PanelCenter>(_videoMode);
   addComponent<right::PanelRight>(_videoMode);

   auto top = _videoMode.height * 0.1F;
   auto lLeft = 0;
   auto cLeft = _videoMode.width * 0.25F;
   auto rLeft = _videoMode.width * 0.666666F;

   _components.at(0)->move(lLeft, top);
   _components.at(1)->move(cLeft, top);
   _components.at(2)->move(rLeft, top);

   // And add the top strip
   addComponent<top::PanelTop>(_videoMode);
}

void DsbApp::runApplication(Util::CommandLine::Data cmdLine)
{
   _appDriver.setApp(this);
   _appDriver.setAppName("DSB");
   _appDriver.setWindowSize(_videoMode);
   _appDriver.runApplication();
}

void DsbApp::onKeyPressed(sf::Event& event)
{
   if (event.key.code == sf::Keyboard::Escape)
   {
      _appDriver.closeWindow();
   }
}

} // End namespace gui
} // End namespace dsb
