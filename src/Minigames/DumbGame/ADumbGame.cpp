/*
 * ADumbGame.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: aaron
 */

#include <iostream>
#include <Minigames/DumbGame/ADumbGame.h>
#include <Minigames/MadLib/MadLibMinigame.h>

namespace Minigames {
namespace DumbGame {

ADumbGame::ADumbGame()
{
   // Empty
}

ADumbGame::~ADumbGame()
{
   // Empty
}

void ADumbGame::play()
{
   std::cout << "Not a very fun game" << std::endl;
   std::cout << "Here's a better one:" << std::endl;

   MadLib::MadLibMinigame _game;
   _game.play();
}

} /* namespace DumbGame */
} /* namespace Minigames */
