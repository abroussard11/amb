/**
 * amb/GuiAppDriver.h
 */

#ifndef AMB_GUIAPPDRIVER_H_
#define AMB_GUIAPPDRIVER_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <amb/AppDriver.h>
#include <amb/GuiApp.h>

namespace amb {

class GuiAppDriver : public AppDriver {
 public:
  GuiAppDriver();
  virtual ~GuiAppDriver() = default;

  virtual void runApplication();
  void setWindowSize(sf::VideoMode vMode);
  void setApp(amb::GuiApp* app);
  void setAppName(const std::string& name);
  void closeWindow();

 private:
  amb::GuiApp* _app;  // a non-owning raw pointer
  std::string _appName;
  sf::VideoMode _windowSize;
  sf::RenderWindow _window;
};

}  // End namespace amb

#endif  // AMB_GUIAPPDRIVER_H_
