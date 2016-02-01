/**
 * amb/GuiAppDriver.cpp
 */

#include <SFML/Graphics.hpp>
#include <amb/GuiAppDriver.h>
#include <Util/Log.h>

namespace amb {

void GuiAppDriver::runApplication() {
  Util::Log::info("Running Gui Application: " + _appName);

  // Create window
  _window.create(_windowSize, _appName);

  // Initialize state
  sf::FloatRect visibleArea(0, 0, _windowSize.width, _windowSize.height);
  _window.setView(sf::View(visibleArea));

  // While window is open: main loop
  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        _window.close();
      } else if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        _window.setView(sf::View(visibleArea));
      } else {
        _app->processEvent(event);
      }
    }

    // Update GuiApp
    _app->update();

    // Draw frame
    _window.clear();
    _window.draw(*_app);
    _window.display();
  }
}

void GuiAppDriver::setWindowSize(sf::VideoMode vMode) { _windowSize = vMode; }

void GuiAppDriver::setApp(amb::GuiApp* app) { _app = app; }

void GuiAppDriver::setAppName(const std::string& name) { _appName = name; }

void GuiAppDriver::closeWindow() { _window.close(); }

}  // End namespace amb
