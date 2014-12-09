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

   // This is just here to practice successfully linking one shared library in another
   MadLib::MadLibMinigame _game;
}

} /* namespace DumbGame */
} /* namespace Minigames */
