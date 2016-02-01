/**
 * amb/sGuiComponent.cpp
 */

#include <amb/GuiComponent.h>

namespace amb {

GuiComponent::GuiComponent()
    : _parent(nullptr),  //
      _components(),     //
      _eventHandlers(),  //
      _isVisible(true) {
  _eventHandlers.reserve(sf::Event::Count);
  _eventHandlers.push_back(&GuiComponent::onClosed);  // 1
  _eventHandlers.push_back(&GuiComponent::onResized);  // 2
  _eventHandlers.push_back(&GuiComponent::onLostFocus);  // 3
  _eventHandlers.push_back(&GuiComponent::onGainedFocus);  // 4
  _eventHandlers.push_back(&GuiComponent::onTextEntered);  // 5
  _eventHandlers.push_back(&GuiComponent::onKeyPressed);  // 6
  _eventHandlers.push_back(&GuiComponent::onKeyReleased);  // 7
  _eventHandlers.push_back(&GuiComponent::onMouseWheelMoved);  // 8
#if SFML_VERSION_MAJOR == 2 && SFML_VERSION_MINOR == 3 && \
    SFML_VERSION_PATCH == 1
  _eventHandlers.push_back(&GuiComponent::onMouseWheelScrolled);
#endif
  _eventHandlers.push_back(&GuiComponent::onMouseButtonPressed);  // 9
  _eventHandlers.push_back(&GuiComponent::onMouseButtonReleased);  // 10
  _eventHandlers.push_back(&GuiComponent::onMouseMoved);  // 11
  _eventHandlers.push_back(&GuiComponent::onMouseEntered);  // 12
  _eventHandlers.push_back(&GuiComponent::onMouseLeft);  // 13
  _eventHandlers.push_back(&GuiComponent::onJoystickButtonPressed);  // 14
  _eventHandlers.push_back(&GuiComponent::onJoystickButtonReleased);  // 15
  _eventHandlers.push_back(&GuiComponent::onJoystickMoved);  // 16
  _eventHandlers.push_back(&GuiComponent::onJoystickConnected);  // 17
  _eventHandlers.push_back(&GuiComponent::onJoystickDisconnected);  // 18
  _eventHandlers.push_back(&GuiComponent::onTouchBegan);  // 19
  _eventHandlers.push_back(&GuiComponent::onTouchMoved);  // 20
  _eventHandlers.push_back(&GuiComponent::onTouchEnded);  // 21
  _eventHandlers.push_back(&GuiComponent::onSensorChanged);  // 22
#if SFML_VERSION_MAJOR == 2 && SFML_VERSION_MINOR == 3 && \
    SFML_VERSION_PATCH == 1
  static_assert(23 == sf::Event::Count,
#else
  static_assert(22 == sf::Event::Count,
#endif
                "Event callback methods should match sf::Event types in name "
                "and number.");
}

void GuiComponent::setParent(GuiComponent* parent) { _parent = parent; }

void GuiComponent::addComponent(Ptr&& component) {
  component->setParent(this);
  _components.push_back(component);
}

void GuiComponent::processEvent(sf::Event& event) {
  ((*this).*(_eventHandlers[event.type]))(event);
  for (auto& component : _components) {
    component->processEvent(event);
  }
}

void GuiComponent::update() {
  updateSelf();
  for (auto& component : _components) {
    component->update();
  }
}

void GuiComponent::move(const sf::Vector2f& offset) {
  sf::Transformable::move(offset);
  moveSelf(offset);
}

sf::Transform GuiComponent::getGlobalTransform() {
  auto trans = getTransform();
  if (_parent != nullptr) {
    trans = _parent->getGlobalTransform() * trans;
  }
  return trans;
}

void GuiComponent::setIsVisible(bool doDraw) { _isVisible = doDraw; }

void GuiComponent::draw(sf::RenderTarget& target,
                        sf::RenderStates states) const {
  if (_isVisible) {
    states.transform *= getTransform();
    drawSelf(target, states);
    for (auto& component : _components) {
      target.draw(*component, states);
    }
  }
}

}  // End namespace amb
