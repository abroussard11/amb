#include <iostream>
#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/DumbGame/ADumbGame.h>

int main()
{
   std::cout << "Hello World!" << std::endl;

   //std::vector<Infra::Model*> actions;

   //actions.push_back(new Models::Fishy())

   //std::cout << "Select an action to run:" << std::endl;
//   for (auto& action : actions)
//   {
//
//   }

   Minigames::DumbGame::ADumbGame _dumb;
   _dumb.play();
   std::cout << std::endl;

   Minigames::MadLib::MadLibMinigame _firstGame;
   _firstGame.play();
}
