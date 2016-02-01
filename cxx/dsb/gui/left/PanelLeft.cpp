/**
 * dsb/gui/left/PanelLeft.cpp
 */

#include <map>
#include <amb/Color.h>
#include <dsb/gui/left/PanelLeft.h>
#include <amb/Xml.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace left {

PanelLeft::PanelLeft(sf::VideoMode mode)
    : GuiComponent(),  //
      _rect() {
  // Configuration
  amb::Xml xml("cxx/dsb/cfg/top.xml");

  // Geometry
  auto width = mode.width * 0.25F;
  auto height = mode.height * 0.9F;

  _rect.setSize(sf::Vector2f(width, height));
  _rect.setFillColor(amb::Color::Gray);

  // Buttons
  auto labels = xml.getElements("//category/name");
  auto numBtns = labels.size();
  for (int i = 0; i < numBtns; ++i) {
    auto button = std::make_unique<Button>();
    button->move(0, (1 + (40.F * i)));
    button->setString(labels.at(i).text);
    addComponent(std::move(button));
  }
}

void PanelLeft::onMouseWheelMoved(sf::Event& event) {
  if (isClickOnSelf(event)) {
    for (auto& button : _components) {
      button->move(0.F, 20.F * event.mouseWheel.delta);
    }
  }
}

void PanelLeft::drawSelf(sf::RenderTarget& target,
                         sf::RenderStates states) const {
  target.draw(_rect, states);
}

bool PanelLeft::isClickOnSelf(sf::Event& event) {
  auto bounds = _rect.getGlobalBounds();
  auto box = getTransform().transformRect(bounds);
  return box.contains(event.mouseWheel.x, event.mouseWheel.y);
}

}  // End namespace left
}  // End namespace gui
}  // End namespace dsb
