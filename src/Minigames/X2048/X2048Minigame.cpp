/*
 * X2048minigame.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#include <iostream>
#include <Minigames/X2048/X2048Minigame.h>
#include <Minigames/X2048/GameBoard.h>
#include <Minigames/X2048/Tile.h>
#include <Minigames/X2048/TileFactory.h>

namespace Minigames {
namespace X2048 {

// Defualt move values for the tile:
//const sf::Vector2f X2048Minigame::c_left(-66.0F, 0.0F);
//const sf::Vector2f X2048Minigame::c_right(66.0F, 0.0F);
//const sf::Vector2f X2048Minigame::c_up(0.0F, -66.0F);
//const sf::Vector2f X2048Minigame::c_down(0.0F, 66.0F);
const float X2048Minigame::s_moveDistance(66.0F);
X2048Minigame::X2048Minigame() :
      _canvas(), //
      _gameState(4, std::vector<unsigned int>(4, 0))
{
   // Reserve space in the vectors
   _gameState.reserve(4);
   for (auto& vec : _gameState)
   {
      vec.reserve(4);
   }
}

X2048Minigame::~X2048Minigame()
{
   // Empty
}

void X2048Minigame::play()
{
   sf::RenderWindow _window(sf::VideoMode(200, 200), "2048!");
   spawnNewTile();

   // Game loop
   while (_window.isOpen())
   {
      sf::Event event;
      while (_window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
         {
            _window.close();
         }
         else
         {
            processEvent(event);
         }
      }

      _window.clear();
      _window.draw(_canvas);

      std::cout << "Tile Positions:" << std::endl;
      int row = 0;
      for (auto& vec : _gameState)
      {
         int col = 0;
         for (auto& val : vec)
         {
            // construct tile
            Tile::Ptr tile = TileFactory::getTile(val);
            // apply tile transform
            tile->move(row * s_moveDistance, col * s_moveDistance);
            std::cout << tile->getPosition().x << ", " << tile->getPosition().y << std::endl;
            _window.draw(*tile);
            col++;
         }
         row++;
      }
      std::cout << std::endl;

      _window.display();
   }
}

void X2048Minigame::processEvent(const sf::Event& event)
{
   if (event.type == sf::Event::KeyPressed)
   {
      slideBoard(event);
      spawnNewTile();
   }
}

void X2048Minigame::slideBoard(const sf::Event& event)
{
      if (event.type == sf::Event::KeyPressed)
      {
         if (event.key.code == sf::Keyboard::Left)
         {
            std::cout << "LEFT pressed" << std::endl;
//            if (_tile.getPosition().x > 67.0F)
//               _tile.move(c_left);
         }
         if (event.key.code == sf::Keyboard::Right)
         {
            std::cout << "RIGHT pressed" << std::endl;
//            if (_tile.getPosition().x < 133.0F)
//               _tile.move(c_right);
         }
         if (event.key.code == sf::Keyboard::Up)
         {
            std::cout << "UP pressed" << std::endl;
//            if (_tile.getPosition().y > 67.0F)
//               _tile.move(c_up);
         }
         if (event.key.code == sf::Keyboard::Down)
         {
            std::cout << "DOWN pressed" << std::endl;
//            if (_tile.getPosition().y < 133.0F)
//               _tile.move(c_down);
         }
      }
}

void X2048Minigame::spawnNewTile()
{
   int x = rand() % 16;
   std::cout << " Random number = " << x << std::endl;
   int count = 0;

   for (auto& vec : _gameState)
   {
      for (auto& val : vec)
      {
         if (count == x)
         {
            count++;
            std::cout << "New tile spawned!" << std::endl;
            val = 2;
            break;
         }
         else if (val == 0)
         {
            count++;
         }
      }
      if (count >= x)
         break;
   }

   std::cout << "Game State Matrix:" << std::endl;
   for (auto& vec : _gameState)
   {
      for (auto& val : vec)
      {
         std::cout << val << " ";
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

} /* namespace X2048 */
} /* namespace Minigames */
