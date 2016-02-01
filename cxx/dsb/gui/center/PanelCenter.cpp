/**
 * dsb/gui/center/PanelCenter.cpp
 */

#include <iostream>
#include <amb/Color.h>
#include <dsb/gui/center/PanelCenter.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace center {

PanelCenter::PanelCenter(sf::VideoMode& mode)
    : GuiComponent(),      //
      _rect(),             //
      _inbox(),            //
      _categories(),       //
      _category(nullptr),  //
      _xmlTopDb() {
  // Config file
  _xmlTopDb.loadFile("cxx/dsb/cfg/top.xml");

  // Messaging
  _inbox = infra::Inbox<ButtonMsg>::makeInbox();
  infra::registerInbox<ButtonMsg>(_inbox);

  auto width = mode.width * 0.4166666F;
  auto height = mode.height * 0.9F;
  _rect.setSize(sf::Vector2f(width, height));
  _rect.setFillColor(amb::Color::Gray);

  // Initialize categories
  auto categoryNodes = _xmlTopDb.getElements("//category");
  for (auto& catNode : categoryNodes) {
    auto name = catNode.getElement("name");
    auto category = std::make_unique<Category>(catNode);
    category->setIsVisible(false);
    _categories[name] = category.get();
    addComponent(std::move(category));
  }

  // empty list at start
  auto emptyNode = amb::xml::Node();
  auto emptyCat = std::make_unique<Category>(emptyNode);
  _categories["Empty Category"] = emptyCat.get();
  addComponent(std::move(emptyCat));
  _category = _categories["Empty Category"];
}

// The Category class would like to receive events,
// so we forward the events to them here
void PanelCenter::processEvent(sf::Event& event) {
  // Only forward events to the category that's currently displayed
  if (isClickOnSelf(event)) {
    Util::Log::info("PanelCenter clicked");
    _category->processEvent(event);
  }
}

void PanelCenter::onButtonMsg(infra::Msg<ButtonMsg>& msg) {
  _category->setIsVisible(false);

  // set list to display
  if (_categories.find(msg.content.x) != _categories.end()) {
    _category = _categories[msg.content.x];
  } else {
    _category = _categories["Empty Category"];
  }
  _category->setIsVisible(true);
}

void PanelCenter::onMouseWheelMoved(sf::Event& event) {
  if (isClickOnSelf(event)) {
    _category->move(0.F, 20.F * event.mouseWheel.delta);
  }
}

void PanelCenter::updateSelf() {
  auto msgs = _inbox->getMessages();
  for (auto& m : msgs) {
    std::cout << "PanelCenter: msg received - " << m.content.x << std::endl;
    onButtonMsg(m);
    std::cout << "_category = " << std::hex << &_category << std::dec
              << std::endl;
  }
}

void PanelCenter::drawSelf(sf::RenderTarget& target,
                           sf::RenderStates states) const {
  target.draw(_rect, states);
  target.draw(*_category, states);
}

bool PanelCenter::isClickOnSelf(sf::Event& event) {
  if (event.type == sf::Event::MouseButtonPressed ||
      event.type == sf::Event::MouseButtonReleased) {
    auto trans = getGlobalTransform();
    auto box = trans.transformRect(_rect.getGlobalBounds());
    return box.contains(event.mouseWheel.x, event.mouseWheel.y);
  } else {
    return false;
  }
}

}  // End namespace center
}  // End namespace gui
}  // End namespace dsb
