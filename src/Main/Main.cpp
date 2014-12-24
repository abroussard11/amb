/**
 * The Main program. This is what actually runs when you call ./build/AmbGames
 */

#include <iostream>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/ProjectEuler/ProjectEulerGame.h>
#include <Minigames/X2048/X2048Minigame.h>

using namespace Minigames;

int main()
{
   std::map<std::string, Infra::Minigame::Ptr> games;
   games["2048"] = Infra::Minigame::Ptr(new X2048::X2048Minigame);
   games["Mad Libs"] = Infra::Minigame::Ptr(new MadLib::MadLibMinigame);
   games["Project Euler"] = Infra::Minigame::Ptr(new ProjectEuler::ProjectEulerGame);

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

} // End of main routine
