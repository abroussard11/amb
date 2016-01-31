/**
 * amb/GuiComponent.h
 */

#ifndef AMB_GUICOMPONENT_H_
#define AMB_GUICOMPONENT_H_

#include <memory>
#include <vector>
#include <utility>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>

namespace amb {

/**
 * This class is the base class for all classes responsible for
 * drawing graphics. It is built on the sf::Drawable class from
 * SFML 2.2 (Simple Fast Multi-media Library version 2.2).
 */
class GuiComponent : public sf::Drawable, public sf::Transformable
{
public:
   using Ptr = std::shared_ptr<GuiComponent>;
   using Target = sf::RenderTarget;
   using States = sf::RenderStates;

   typedef void (GuiComponent::*EventHandlerFn)(sf::Event& event);

   GuiComponent();
   virtual ~GuiComponent() = default;

   template <typename T, typename... Args>
   void addComponent(Args&&... args)
   {
      auto comp = std::make_shared<T>(std::forward<Args>(args)...);
      addComponent(std::move(comp));
   }

   void setParent(GuiComponent* parent);
   void addComponent(Ptr&& component);
   virtual void processEvent(sf::Event& event);
   void update();
   void move(const sf::Vector2f& offset);

   void move(float offsetX, float offsetY)
   {
      move(sf::Vector2f(offsetX, offsetY));
   }

   sf::Transform getGlobalTransform();
   void setIsVisible(bool doDraw);

protected:
   GuiComponent* _parent;
   std::vector<GuiComponent::Ptr> _components;

   // Event Handlers
   virtual void onClosed(sf::Event& event) {}
   virtual void onResized(sf::Event& event) {}
   virtual void onLostFocus(sf::Event& event) {}
   virtual void onGainedFocus(sf::Event& event) {}
   virtual void onTextEntered(sf::Event& event) {}
   virtual void onKeyPressed(sf::Event& event) {}
   virtual void onKeyReleased(sf::Event& event) {}
   virtual void onMouseWheelMoved(sf::Event& event) {}
   virtual void onMouseWheelScrolled(sf::Event& event) {} // in SFML 2.3
   virtual void onMouseButtonPressed(sf::Event& event) {}
   virtual void onMouseButtonReleased(sf::Event& event) {}
   virtual void onMouseMoved(sf::Event& event) {}
   virtual void onMouseEntered(sf::Event& event) {}
   virtual void onMouseLeft(sf::Event& event) {}
   virtual void onJoystickButtonPressed(sf::Event& event) {}
   virtual void onJoystickButtonReleased(sf::Event& event) {}
   virtual void onJoystickMoved(sf::Event& event) {}
   virtual void onJoystickConnected(sf::Event& event) {}
   virtual void onJoystickDisconnected(sf::Event& event) {}
   virtual void onTouchBegan(sf::Event& event) {}
   virtual void onTouchMoved(sf::Event& event) {}
   virtual void onTouchEnded(sf::Event& event) {}
   virtual void onSensorChanged(sf::Event& event) {}

private:
   std::vector<EventHandlerFn> _eventHandlers;
   bool _isVisible;

   virtual void updateSelf() {}
   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const {}
   virtual void moveSelf(const sf::Vector2f& offset) {}
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
};

} // End namespace amb

#endif // AMB_GUICOMPONENT_H_
