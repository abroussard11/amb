/**
 * dsb/gui/left/Button.cpp
 */

#include <iostream>
#include <sstream>
#include <amb/Color.h>
#include <amb/Font.h>
#include <dsb/gui/left/Button.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace left {

Button::Button() :
   GuiComponent(), //
   _rect(), //
   _boundingBox(), //
   _text(), //
   _msg()
{
   _rect.setFillColor(amb::Color::DsbGreen);
   _rect.setSize(sf::Vector2f(450.F, 30.F));

   _text.setFont(amb::Font::defaults[0]);
   _text.setCharacterSize(20);
   _text.setColor(sf::Color::Black);

   _boundingBox.setOutlineColor(sf::Color::Transparent);
   _boundingBox.setFillColor(sf::Color::Transparent);
   _boundingBox.setOutlineThickness(1.F);
}

void Button::setString(std::string str)
{
   _text.setString(str);
   _msg.content.x = str;
}

void Button::setSize(float width, float height)
{
   _rect.setSize(sf::Vector2f(width, height));
}

void Button::centerText()
{
   auto btnWidth = _rect.getSize().x;
   auto txtWidth = _text.getLocalBounds().width;
   _text.move((btnWidth - txtWidth) / 2.F , 0.F);
}

void Button::onMouseButtonPressed(sf::Event& event)
{
   auto color = sf::Color::Transparent;
   if (isClickOnButton(event))
   {
      color = sf::Color::Red;
      Util::Log::info(_text.getString().toAnsiString());
   }
   _boundingBox.setOutlineColor(color);
}

void Button::onMouseButtonReleased(sf::Event& event)
{
   auto color = sf::Color::Transparent;
   if (isClickOnButton(event))
   {
      color = sf::Color::Red;
   _msg.send();
   }
   _boundingBox.setOutlineColor(color);
}

void Button::updateSelf()
{
   auto box = _rect.getGlobalBounds();
   _boundingBox.setSize(sf::Vector2f(box.width, box.height));
   _boundingBox.setPosition(box.left, box.top);
}

void Button::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_rect, states);
   target.draw(_text, states);
   target.draw(_boundingBox, states);
}

bool Button::isClickOnButton(sf::Event& event)
{
   auto trans = getGlobalTransform();
   // auto trans = getTransform();
   auto box = trans.transformRect(_rect.getGlobalBounds());

   return box.contains(event.mouseButton.x, event.mouseButton.y);
}

} // End namespace left
} // End namespace gui
} // End namespace dsb
