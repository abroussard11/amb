/**
 * dsb/gui/center/Activity.h
 */

#ifndef DSB_GUI_CENTER_ACTIVITY_H_
#define DSB_GUI_CENTER_ACTIVITY_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>
#include <amb/xml/Node.h>
#include <dsb/interface/ActivityMsg.h>
#include <infra/Msg.h>

namespace dsb {
namespace gui {
namespace center {

class Activity : public amb::GuiComponent
{
public:
   using Ptr = std::unique_ptr<Activity>;

   Activity(amb::xml::Node& item);
   Activity() = default;
   virtual ~Activity() = default;

   auto getBoundingBox()
   {
      auto trans = getGlobalTransform();
      auto box = trans.transformRect(_boundingBox.getGlobalBounds());
      return box;
   }

protected:
   virtual void onMouseButtonPressed(sf::Event& event) override;
   virtual void onMouseButtonReleased(sf::Event& event) override;

private:
   sf::Text _name;
   sf::Text _desc;
   sf::Text _LU;
   sf::Text _UC;
   sf::RectangleShape _boundingBox;
   infra::Msg<ActivityMsg> _msg;

   virtual void updateSelf() override;
   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;
   bool isClickOnSelf(sf::Event& event);
   static sf::FloatRect rectUnion(sf::FloatRect box1, sf::FloatRect box2);
};

} // End namespace center
} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_CENTER_ACTIVITY_H_
