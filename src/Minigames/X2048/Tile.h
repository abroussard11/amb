/*
 * Tile.h
 *
 *  Created on: Dec 24, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_X2048_TILE_H_
#define SRC_MINIGAMES_X2048_TILE_H_

#include <memory>
#include <SFML/Graphics.hpp>

namespace Minigames {
namespace X2048 {

class Tile : public sf::Drawable, public sf::Transformable
{
public:
   typedef std::shared_ptr<Tile> Ptr;

   Tile();
   Tile(unsigned int val, sf::Color color, sf::Font& font);
   virtual ~Tile();

   int getValue() const;
   void setValue();

private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   sf::Text _text;
   sf::RectangleShape _background;
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_X2048_TILE_H_ */
