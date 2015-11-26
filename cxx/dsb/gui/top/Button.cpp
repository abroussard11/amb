/**
 * dsb/top/Button.cpp
 */

#include <iostream>
#include <sstream>
#include <amb/Color.h>
#include <amb/Font.h>
#include <dsb/gui/top/Button.h>
#include <Util/Log.h>

namespace dsb {
namespace gui {
namespace top {

ButtonBase::ButtonBase() :
   GuiComponent(), //
   _boundingBox(), //
   _rect(), //
   _text()
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

void ButtonBase::setString(std::string str)
{
   _text.setString(str);
}

void ButtonBase::setSize(float width, float height)
{
   _rect.setSize(sf::Vector2f(width, height));
}

void ButtonBase::centerText()
{
   auto btnWidth = _rect.getSize().x;
   auto txtWidth = _text.getLocalBounds().width;
   _text.move((btnWidth - txtWidth) / 2.F , 0.F);
}

void ButtonBase::onMouseButtonPressed(sf::Event& event)
{
   if (isClickOnButton(event))
   {
      _boundingBox.setOutlineColor(sf::Color::Red);
   }
}

void ButtonBase::onMouseButtonReleased(sf::Event& event)
{
   _boundingBox.setOutlineColor(sf::Color::Transparent);
}

bool ButtonBase::isClickOnButton(sf::Event& event)
{
   auto trans = getGlobalTransform();
   auto box = trans.transformRect(_rect.getGlobalBounds());

   return box.contains(event.mouseButton.x, event.mouseButton.y);
}

void ButtonBase::updateSelf()
{
   auto box = _rect.getGlobalBounds();
   _boundingBox.setSize(sf::Vector2f(box.width, box.height));
   _boundingBox.setPosition(box.left, box.top);
}

void ButtonBase::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_rect, states);
   target.draw(_text, states);
   target.draw(_boundingBox, states);
}

} // End namespace top
} // End namespace gui
} // End namespace dsb
