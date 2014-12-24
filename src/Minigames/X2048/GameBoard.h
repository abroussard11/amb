/*
 * GameBoard.h
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_X2048_GAMEBOARD_H_
#define SRC_MINIGAMES_X2048_GAMEBOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>

namespace Minigames {
namespace X2048 {

class GameBoard : public sf::Drawable
{
public:
   GameBoard();
   virtual ~GameBoard();

protected:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
   virtual void buildRectangleDefaults(sf::RectangleShape& rect);

private:
   sf::RectangleShape _background;
   std::vector<sf::RectangleShape> _grid;
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_X2048_GAMEBOARD_H_ */
