/**
 * x2048/x2048App.cpp
 */

#include <x2048/generic/x2048App.h>

namespace x2048 {

void x2048App::runApplication(Util::CommandLine::Data cmdLine) {
  _appDriver.setApp(this);
  _appDriver.setAppName("x2048App");
  _appDriver.setWindowSize(sf::VideoMode(800, 600));
  _appDriver.runApplication();
}

void x2048App::onKeyPressed(sf::Event& event) {
  if (event.key.code == sf::Keyboard::Escape) {
    _appDriver.closeWindow();
  }
}

void x2048App::onMouseButtonPressed(sf::Event& event) {
  _isMouseDepressed = true;
}

void x2048App::onMouseButtonReleased(sf::Event& event) {
  _isMouseDepressed = false;
}

void x2048App::onMouseMoved(sf::Event& event) {
  // empty
}

}  // End namespace x2048
