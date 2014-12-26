/*
 * Tile.h
 *
 *  Created on: Dec 24, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_X2048_TILE_H_
#define SRC_MINIGAMES_X2048_TILE_H_

#include <SFML/Graphics/Drawable.hpp>

namespace Minigames {
namespace X2048 {

class Tile : public sf::Drawable
{
public:
   Tile();
   virtual ~Tile();

   int getValue() const;
   void setValue();
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_X2048_TILE_H_ */
