/**
 * dsb/gui/top/SearchBar.cpp
 */

#include <dsb/gui/top/SearchBar.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace top {

SearchBar::SearchBar()
    : GuiComponent(),      //
      _rect(),             //
      _frames(0),          //
      _drawCursor(false),  //
      _cursor() {
  _rect.setFillColor(sf::Color::White);
  _cursor.setFillColor(sf::Color::Black);
}

void SearchBar::setSize(float width, float height) {
  _rect.setSize(sf::Vector2f(width, height));
  _cursor.setSize(sf::Vector2f(10.0F, height * 0.6F));
}

void SearchBar::setPosition(float x, float y) {
  _rect.setPosition(x, y);
  _cursor.setPosition(x + 10.F, y + 10.F);
}

void SearchBar::onMouseButtonPressed(sf::Event& event) {
  if (!isClickOnSelf(event)) {
    _drawCursor = false;
  }
}

void SearchBar::onMouseButtonReleased(sf::Event& event) {
  if (isClickOnSelf(event)) {
    _frames = 128;
    _drawCursor = true;
    Util::Log::info("Draw the cursor");
  }
}

void SearchBar::drawSelf(sf::RenderTarget& target,
                         sf::RenderStates states) const {
  // states.transform = getTransform();
  target.draw(_rect, states);
  if (_drawCursor && _frames > 128) {
    target.draw(_cursor, states);
  }
}

void SearchBar::updateSelf() {
  if (_drawCursor) {
    _frames += 4;
    // Util::Log::info("frames = ", _frames);
  }
}

bool SearchBar::isClickOnSelf(sf::Event& event) {
  auto box = _rect.getGlobalBounds();

  return box.contains(event.mouseButton.x, event.mouseButton.y);
}

}  // End namespace top
}  // End namespace gui
}  // End namespace dsb
