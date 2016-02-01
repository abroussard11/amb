/**
 * dsb/gui/right/ListHeader.h
 */

#ifndef DSB_GUI_RIGHT_LISTHEADER_H_
#define DSB_GUI_RIGHT_LISTHEADER_H_

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>

namespace dsb {
namespace gui {
namespace right {

class ListHeader : public amb::GuiComponent {
 public:
  ListHeader();
  virtual ~ListHeader() = default;

 private:
  std::vector<sf::RectangleShape> _rects;
  std::vector<sf::Text> _texts;

  virtual void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const;
};

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_RIGHT_LISTHEADER_H_
