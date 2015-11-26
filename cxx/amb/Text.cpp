/**
 * amb/Text.cpp
 */

#include <amb/Text.h>
#include <amb/Color.h>

namespace amb {

Text::Text(const sf::String& string, const sf::Font& font) :
   GuiComponent(), //
   data(string, font)
{
   // Empty
}

void Text::setPosition(sf::Vector2f pos)
{
   data.setPosition(pos);
}

void Text::setPosition(float x, float y)
{
   data.setPosition(x, y);
}

void Text::setCharacterSize(unsigned int size)
{
   data.setCharacterSize(size);
}

void Text::setColor(const sf::Color& color)
{
   data.setColor(color);
}

void Text::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
   states.transform *= getTransform();
   target.draw(data, states);
}

} // End namespace amb
