/*
 * ProjectEulerGame.cpp
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#include <iostream>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>

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
//   sf::RenderWindow window(sf::VideoMode(1000, 400), "Project Euler");
//   sf::Font font;
//   if (!font.loadFromFile("/usr/share/fonts/truetype/DroidSansMono.ttf"))
//   {
//      std::cout << "ERROR loading the font" << std::endl;
//   }
//   sf::Text text;
//   text.setFont(font);
//   text.setCharacterSize(20); // in pixels, not points
//   text.setString("Pick the problem you would like to see the solution for:");
//   text.setColor(sf::Color::Green);

   // Infinite loop. Hit Ctrl-C to get out
   std::cout << std::endl << "PRESS CTRL-C TO QUIT AT ANY TIME" << std::endl;

//   while (window.isOpen())
//   {
//      sf::Event event;
//      while (window.pollEvent(event))
//      {
//         if (event.type == sf::Event::Closed)
//         {
//            window.close();
//         }
//         else
//         {
////            processEvent(event);
//         }
//
//         window.clear();
//         window.draw(text);
//         window.display();
//      }

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
