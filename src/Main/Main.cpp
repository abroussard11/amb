/**
 * The Main program. This is what actually runs when you call ./build/AmbGames
 */
#include <iostream>
#include <map>
#include <string>
#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/DumbGame/ADumbGame.h>
#include <Minigames/ProjectEuler/ProjectEulerGame.h>

using namespace Minigames;

int main()
{
   std::cout << "Hello World!" << std::endl;

   std::map<std::string, Minigame::Ptr> games;
   games["Mad Libs"] = Minigame::Ptr(new MadLib::MadLibMinigame);
   games["Dumb Game"] = Minigame::Ptr(new DumbGame::ADumbGame);
   games["Project Euler"] = Minigame::Ptr(new ProjectEuler::ProjectEulerGame);

   while (true)
   {
      std::cout << "Select your game:" << std::endl;
      for (auto& gamePair : games)
      {
         std::cout << "\t" << gamePair.first << std::endl;
      }

      std::string choice;
      std::getline(std::cin, choice);
      auto gamePair = games.find(choice);
      if (gamePair != games.end())
      {
         gamePair->second->play();
      }
      else
      {
         std::cout << "Invalid selection." << std::endl;
      }
      std::cout << std::endl;
   }
}
