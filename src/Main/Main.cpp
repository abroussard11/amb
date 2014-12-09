#include <iostream>
#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/DumbGame/ADumbGame.h>

int main()
{
   std::cout << "Hello World!" << std::endl;

   Minigames::DumbGame::ADumbGame _dumb;
   _dumb.play();
   std::cout << std::endl;

   Minigames::MadLib::MadLibMinigame _firstGame;
   _firstGame.play();
}
