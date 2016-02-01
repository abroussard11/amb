/**
 * dsb/gui/left/PanelLeft.h
 */

#ifndef DSB_GUI_LEFT_PANELLEFT_H_
#define DSB_GUI_LEFT_PANELLEFT_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <amb/GuiComponent.h>
#include <dsb/gui/left/Button.h>

namespace dsb {
namespace gui {
namespace left {

class PanelLeft : public amb::GuiComponent {
 public:
  PanelLeft() = delete;
  PanelLeft(sf::VideoMode mode);
  virtual ~PanelLeft() = default;

  // void move(float x, float y);

 protected:
  void onMouseWheelMoved(sf::Event& event) override;

 private:
  sf::RectangleShape _rect;

  virtual void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const;
  bool isClickOnSelf(sf::Event& event);
};

}  // End namespace left
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_LEFT_PANELLEFT_H_
