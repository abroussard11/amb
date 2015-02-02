/*
 * Tile.cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: aaron
 */

#include <sstream>
#include <Minigames/X2048/Tile.h>

namespace Minigames {
namespace X2048 {

Tile::Tile() :
      _text(), //
      _background()
{
   // Empty
}

Tile::Tile(unsigned int val, sf::Color color, sf::Font& font) :
      _text(), //
      _background()
{
   _background.setFillColor(sf::Color::Green);
   _background.setPosition(10.0F, 10.0F);

   _text.setString(sf::String(val));
   _text.setCharacterSize(20);
   _text.setColor(sf::Color::Yellow);
   _text.setFont(font);
   _text.setPosition(10.F, 10.F);
}

Tile::~Tile()
{
   // Empty
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   states.transform *= getTransform();

   target.draw(_background, states);
   target.draw(_text, states);
}

} /* namespace X2048 */
} /* namespace Minigames */
