/**
 * dsb/gui/center/Activity.cpp
 */

#include <amb/Color.h>
#include <amb/Font.h>
#include <amb/Text.h>
#include <dsb/gui/center/Activity.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace center {

Activity::Activity(amb::xml::Node& item) :
   GuiComponent(), //
   _name(item.getElement("name"), amb::Font::defaults[0]), //
   _desc(item.getElement("desc"), amb::Font::defaults[0]), //
   _LU(item.getElement("LU"), amb::Font::defaults[0]), //
   _UC(item.getElement("UC"), amb::Font::defaults[0]), //
   _boundingBox(), //
   _msg()
{
   // Messaging
   _msg.content.name = _name.getString();
   _msg.content.desc = _desc.getString();
   _msg.content.LU = _LU.getString();
   _msg.content.UC = _UC.getString();

   _name.setPosition(0, 0);
   _desc.setPosition(75.0F, 0);
   _LU.setPosition(550.0F, 0);
   _UC.setPosition(600.0F, 0);


   _name.setCharacterSize(15);
   _desc.setCharacterSize(15);
   _LU.setCharacterSize(15);
   _UC.setCharacterSize(15);

   _name.setColor(amb::Color::Black);
   _desc.setColor(sf::Color::Black);
   _LU.setColor(sf::Color::Black);
   _UC.setColor(sf::Color::Black);

   // setup the bounding box to surround all the text items
   _boundingBox.setOutlineColor(sf::Color::Transparent);
   _boundingBox.setFillColor(sf::Color::Transparent);
   _boundingBox.setOutlineThickness(1.F);
   auto nameBounds = _name.getGlobalBounds();
   auto descBounds = _desc.getGlobalBounds();
   auto LUBounds = _LU.getGlobalBounds();
   auto UCBounds = _UC.getGlobalBounds();

   auto bounds = rectUnion(nameBounds, rectUnion(descBounds, rectUnion(LUBounds, UCBounds)));
   auto buf = 2.F;
   _boundingBox.setSize(sf::Vector2f(bounds.width + (2 * buf), bounds.height + (3 * buf)));
   _boundingBox.setPosition(bounds.left - buf, bounds.top - (2 * buf));
}

void Activity::onMouseButtonPressed(sf::Event& event)
{
   // Empty
}

void Activity::onMouseButtonReleased(sf::Event& event)
{
   auto color = sf::Color::Transparent;
   if (isClickOnSelf(event) && event.mouseButton.button == sf::Mouse::Left)
   {
      color = sf::Color::Red;
      std::cout << "Sending ActivityMsg: " << _name.getString().toAnsiString() << std::endl;
      _msg.send();
   }
   _boundingBox.setOutlineColor(color);
}

void Activity::updateSelf()
{
   auto box = rectUnion(_name.getGlobalBounds(), rectUnion(_desc.getGlobalBounds(), rectUnion(_LU.getGlobalBounds(), _UC.getGlobalBounds())));
   _boundingBox.setSize(sf::Vector2f(box.width, box.height));
   _boundingBox.setPosition(box.left, box.top);
}

void Activity::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_name, states);
   target.draw(_desc, states);
   target.draw(_LU, states);
   target.draw(_UC, states);
   target.draw(_boundingBox, states);
}

bool Activity::isClickOnSelf(sf::Event& event)
{
   auto box = getBoundingBox();
   return box.contains(event.mouseButton.x, event.mouseButton.y);
}

sf::FloatRect Activity::rectUnion(sf::FloatRect box1, sf::FloatRect box2)
{
   auto box1Right = box1.left + box1.width;
   auto box2Right = box2.left + box2.width;
   auto box1Bottom = box1.top + box1.height;
   auto box2Bottom = box2.top + box2.height;

   auto top = (box1.top < box2.top) ? box1.top : box2.top;
   auto left = (box1.left < box2.left) ? box1.left : box2.left;
   auto width = (box1Right > box2Right ? box1Right : box2Right) - left;
   auto height = (box1Bottom > box2Bottom ? box1Bottom : box2Bottom) - top;

   return sf::FloatRect(left, top, width, height);
}

} // End namespace center
} // End namespace gui
} // End namespace dsb
