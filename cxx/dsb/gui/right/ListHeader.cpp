/**
 * dsb/gui/right/ListHeader.cpp
 */

#include <dsb/gui/right/ListHeader.h>

#include <amb/Color.h>
#include <amb/Font.h>

namespace dsb {
namespace gui {
namespace right {

ListHeader::ListHeader()
    : _rects(),  //
      _texts() {
  const auto rectWidth = 120.F;  // same value used in ProjectItem.cpp
  const auto margin = 2.F;
  _rects.reserve(5);
  _texts.reserve(5);
  for (int i = 0; i < 5; ++i) {
    sf::RectangleShape rect;
    rect.setFillColor(amb::Color::White);
    rect.setOutlineColor(sf::Color::Black);
    rect.setSize(sf::Vector2f(rectWidth, 30.F));
    rect.setPosition(i * rectWidth, 0.F);
    rect.setOutlineThickness(1.F);
    _rects.push_back(rect);

    sf::Text text;
    text.setPosition(i * rectWidth + margin, 0.F);
    text.setFont(amb::Font::defaults[0]);
    text.setCharacterSize(20);
    text.setColor(sf::Color::Black);
    _texts.push_back(text);
  }

  _texts.at(0).setString("Activity");
  _texts.at(1).setString("LU");
  _texts.at(2).setString("UC");
  _texts.at(3).setString("QU");
  _texts.at(4).setString("Total");
}

void ListHeader::drawSelf(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  for (auto& rect : _rects) {
    target.draw(rect, states);
  }

  for (auto& text : _texts) {
    target.draw(text, states);
  }
}

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb
