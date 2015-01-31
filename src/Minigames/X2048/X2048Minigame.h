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
//   static const sf::Vector2f c_left;
//   static const sf::Vector2f c_right;
//   static const sf::Vector2f c_up;
//   static const sf::Vector2f c_down;
   static const float s_moveDistance;

   X2048Minigame();
   virtual ~X2048Minigame();

   void play();

private:
   void processEvent(const sf::Event& event);
   void slideBoard(const sf::Event& event);
   void spawnNewTile();

   GameBoard _canvas;
   std::vector<std::vector<unsigned int>> _gameState;
};

} /* namespace X2048 */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_2048_X2048MINIGAME_H_ */
