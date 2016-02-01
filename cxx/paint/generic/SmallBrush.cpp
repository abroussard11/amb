/**
 * paint/SmallBrush.cpp
 */

#include <paint/generic/SmallBrush.h>

namespace paint {

SmallBrush::SmallBrush(float x, float y)
    : GuiComponent(),  //
      _tile() {
  _tile.setFillColor(sf::Color::Green);

  // Position: (0,0) is the top left corner;
  _tile.setPosition(x, y);
  _tile.setSize(sf::Vector2f(1.0F, 1.0F));
}

void SmallBrush::drawSelf(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  target.draw(_tile, states);
}

}  // End namespace paint
