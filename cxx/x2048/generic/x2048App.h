/**
 * x2048/x2048App.h
 */

#ifndef X2048_GENERIC_X2048APP_H_
#define X2048_GENERIC_X2048APP_H_

#include <SFML/Graphics.hpp>
#include <amb/GuiApp.h>
#include <amb/GuiAppDriver.h>

namespace x2048 {

class x2048App : public amb::GuiApp {
 public:
  x2048App() = default;
  virtual ~x2048App() = default;

  void runApplication(Util::CommandLine::Data cmdLine) override;
  void onKeyPressed(sf::Event& event) override;
  void onMouseButtonPressed(sf::Event& event) override;
  void onMouseButtonReleased(sf::Event& event) override;
  void onMouseMoved(sf::Event& event) override;

 private:
  amb::GuiAppDriver _appDriver;
  bool _isMouseDepressed;
};

}  // End namespace x2048

#endif  // X2048_GENERIC_X2048APP_H_
