/**
 * paint/PaintApp.cpp
 */

#include <paint/generic/PaintApp.h>

namespace paint {

void PaintApp::runApplication(Util::CommandLine::Data cmdLine)
{
   // Initialize state
   // _colorCode = 16711935;
   // all green, all alpha // TODO not until SFML 2.3

   _appDriver.setApp(this);
   _appDriver.setAppName("PaintApp");
   _appDriver.setWindowSize(sf::VideoMode(800, 600));
   _appDriver.runApplication();
}

void PaintApp::onKeyPressed(sf::Event& event)
{
   if (event.key.code == sf::Keyboard::Escape)
   {
      _appDriver.closeWindow();
   }
}

void PaintApp::onMouseButtonPressed(sf::Event& event)
{
   if (event.mouseButton.button == sf::Mouse::Middle)
   {
      _components.clear();
   }
   else
   {
      _isMouseDepressed = true;
      _start = BrushStroke::Point(event.mouseButton.x, event.mouseButton.y);
   }
}

void PaintApp::onMouseButtonReleased(sf::Event& event)
{
   _isMouseDepressed = false;
}

void PaintApp::onMouseMoved(sf::Event& event)
{
   if (_isMouseDepressed)
   {
      _end = BrushStroke::Point(event.mouseMove.x, event.mouseMove.y);
      addComponent<BrushStroke>(_start, _end);
      _start = _end;
   }
}

} // End namespace paint
