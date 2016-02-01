/**
 * paint/PaintApp.h
 */

#ifndef PAINT_GENERIC_PAINTAPP_H_
#define PAINT_GENERIC_PAINTAPP_H_

#include <SFML/Graphics.hpp>
#include <amb/GuiApp.h>
#include <amb/GuiAppDriver.h>
#include <paint/generic/BrushStroke.h>

namespace paint {

class PaintApp : public amb::GuiApp {
 public:
  PaintApp() = default;
  virtual ~PaintApp() = default;

  virtual void runApplication(Util::CommandLine::Data cmdLine) override;
  virtual void onKeyPressed(sf::Event& event) override;
  virtual void onMouseButtonPressed(sf::Event& event) override;
  virtual void onMouseButtonReleased(sf::Event& event) override;
  virtual void onMouseMoved(sf::Event& event) override;

 private:
  amb::GuiAppDriver _appDriver;
  BrushStroke::Point _start;
  BrushStroke::Point _end;
  bool _isMouseDepressed;
  // sf::Uint32 _colorCode; // TODO SFML 2.3
};

}  // End namespace paint

#endif  // PAINT_GENERIC_PAINTAPP_H_
