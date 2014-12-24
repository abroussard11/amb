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
//         std::cout << problem->getProblemText() << std::endl;
//         std::cout << "Press any key to view the solution" << std::endl;
//         int x;
//         std::cin >> x;
         std::cout << problem->getSolution() << std::endl;
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

//const sf::Drawable& ProjectEulerGame::getDrawable() const
//{
//   return _canvas.get();
//}

} /* namespace ProjectEuler */
} /* namespace Minigames */
