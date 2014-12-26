/*
 * ProjectEulerGame.cpp
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#include <iostream>
#include <sstream>
#include <string>
#include <Minigames/ProjectEuler/ProjectEulerGame.h>

namespace Minigames {
namespace ProjectEuler {

ProjectEulerGame::ProjectEulerGame() :
      _problemLoader()
{
   // Empty
}

ProjectEulerGame::~ProjectEulerGame()
{
   // Empty
}

void ProjectEulerGame::play()
{
   // Infinite loop. Hit Ctrl-C to get out
   std::cout << std::endl << "PRESS CTRL-C TO QUIT AT ANY TIME" << std::endl;
   while (true)
   {
      std::cout << "Pick the problem you would like to see the solution for:" << std::endl;

      int choice = 0;
      std::string input;
      std::cin >> input;
      std::stringstream(input) >> choice;

      if (0 < choice && choice < 100)
      {
         Problem::Ptr problem = _problemLoader.load(choice);
         std::cout << problem->getText() << std::endl;
         std::cout << std::endl << "Enter any key to view the solution" << std::endl << std::endl;
         std::string x;
         std::cin >> x;
         std::cout << problem->getSolution() << std::endl;
         std::cout << "Check the answer here:   https://projecteuler.net/problem=" << choice << std::endl;
      }
      else
      {
         std::cout << "Invalid selection" << std::endl;
      }
      std::cout << std::endl;
   }
}

void ProjectEulerGame::processEvent(const sf::Event& event)
{

}

void ProjectEulerGame::update()
{

}

} /* namespace ProjectEuler */
} /* namespace Minigames */
