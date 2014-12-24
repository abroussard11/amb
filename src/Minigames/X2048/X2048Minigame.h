/*
 * X2048minigame.h
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_2048_X2048MINIGAME_H_
#define SRC_MINIGAMES_2048_X2048MINIGAME_H_

#include <Infra/Minigame.h>
#include <Minigames/X2048/GameBoard.h>

namespace Minigames {
namespace X2048 {

class X2048Minigame : public Infra::Minigame
{
public:
   // Defualt move values for the tile:
   static const sf::Vector2f c_left;
   static const sf::Vector2f c_right;
   static const sf::Vector2f c_up;
   static const sf::Vector2f c_down;

   X2048Minigame();
   virtual ~X2048Minigame();

   // temporary demo "play" function
   void play();
   virtual void processEvent(const sf::Event& event);
   virtual void update();
   virtual const sf::Drawable& getDrawable() const;

private:
   GameBoard _canvas;
   sf::ConvexShape _tile;
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_2048_X2048MINIGAME_H_ */
