/*
 * X2048minigame.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#include <iostream>
#include <Minigames/X2048/X2048Minigame.h>
#include <Minigames/X2048/GameBoard.h>

namespace Minigames {
namespace X2048 {

// Defualt move values for the tile:
const sf::Vector2f X2048Minigame::c_left(-66.0F, 0.0F);
const sf::Vector2f X2048Minigame::c_right(66.0F, 0.0F);
const sf::Vector2f X2048Minigame::c_up(0.0F, -66.0F);
const sf::Vector2f X2048Minigame::c_down(0.0F, 66.0F);

X2048Minigame::X2048Minigame() :
      _canvas(), //
      _tile(4)
{
   // Empty
}

X2048Minigame::~X2048Minigame()
{
   // Empty
}

void X2048Minigame::play()
{
   sf::RenderWindow _window(sf::VideoMode(200, 200), "SFML works!");

//   sf::ConvexShape _tile(4);
   _tile.setFillColor(sf::Color::Green);
   _tile.setPoint(0, sf::Vector2f(-10.F,  10.0F));
   _tile.setPoint(1, sf::Vector2f( 10.F,  10.0F));
   _tile.setPoint(2, sf::Vector2f( 10.F, -10.0F));
   _tile.setPoint(3, sf::Vector2f(-10.F, -10.0F));
   _tile.setPosition(100.0F, 100.0F);

   while (_window.isOpen())
   {
      sf::Event event;
      while (_window.pollEvent(event))
      {
//         processEvent(event); // TODO
         if (event.type == sf::Event::Closed)
         {
            _window.close();
         }
         else if (event.type == sf::Event::KeyPressed)
         {
            if (event.key.code == sf::Keyboard::Left)
            {
               std::cout << "LEFT pressed" << std::endl;
               if (_tile.getPosition().x > 67.0F)
                  _tile.move(c_left);
            }
            if (event.key.code == sf::Keyboard::Right)
            {
               std::cout << "RIGHT pressed" << std::endl;
               if (_tile.getPosition().x < 133.0F)
                  _tile.move(c_right);
            }
            if (event.key.code == sf::Keyboard::Up)
            {
               std::cout << "UP pressed" << std::endl;
               if (_tile.getPosition().y > 67.0F)
                  _tile.move(c_up);
            }
            if (event.key.code == sf::Keyboard::Down)
            {
               std::cout << "DOWN pressed" << std::endl;
               if (_tile.getPosition().y < 133.0F)
                  _tile.move(c_down);
            }
         }
         else if (event.type == sf::Event::KeyReleased)
         {
            if (event.key.code == sf::Keyboard::Left)
            {
               std::cout << "LEFT released" << std::endl;
            }
            if (event.key.code == sf::Keyboard::Right)
            {
               std::cout << "RIGHT released" << std::endl;
            }
            if (event.key.code == sf::Keyboard::Up)
            {
               std::cout << "UP released" << std::endl;
            }
            if (event.key.code == sf::Keyboard::Down)
            {
               std::cout << "DOWN released" << std::endl;
            }
         }
      }

      update();
      _window.clear();
      _window.draw(getDrawable());
      _window.draw(_tile);
      _window.display();
   }
}

void X2048Minigame::processEvent(const sf::Event& event)
{

}

void X2048Minigame::update()
{

}

const sf::Drawable& X2048Minigame::getDrawable() const
{
   return _canvas;
}

} /* namespace X2048 */
} /* namespace Minigames */
