/*
 * GameBoard.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#include <Minigames/X2048/GameBoard.h>

namespace Minigames {
namespace X2048 {

GameBoard::GameBoard() :
   _background(sf::Vector2f(200.0F, 200.0F)), //
   _grid()
{
//   //Window = 200 x 200
//   //
//   // p1   p2   p3   p4
//   // p5   p6   p7   p8
//   // p9   p10  p11  p12
//   // p13  p14  p15  p16
//   std::vector<sf::Vertex> points = {sf::Vector2f(1.0,   1.0), sf::Vector2f(67.0,   1.0), sf::Vector2f(133.0,   1.0), sf::Vector2f(199.0,  1.0),
//                                     sf::Vector2f(1.0,  67.0), sf::Vector2f(67.0,  67.0), sf::Vector2f(133.0,  67.0), sf::Vector2f(199.0,  67.0),
//                                     sf::Vector2f(1.0, 133.0), sf::Vector2f(67.0, 133.0), sf::Vector2f(133.0, 133.0), sf::Vector2f(199.0, 133.0),
//                                     sf::Vector2f(1.0, 199.0), sf::Vector2f(67.0, 199.0), sf::Vector2f(133.0, 199.0), sf::Vector2f(199.0, 199.0)};

   _background.setPosition(0.0F, 0.0F);
   _background.setFillColor(sf::Color::Yellow);

   sf::Vector2f verticalSize(66.0F, 198.0F);
   sf::Vector2f horizontalSize(198.0F, 66.0F);

   // horizontal rectangles
   sf::RectangleShape h1(horizontalSize);
   buildRectangleDefaults(h1);
   h1.setPosition(1.0F, 1.0F);

   sf::RectangleShape h2(horizontalSize);
   buildRectangleDefaults(h2);
   h2.setPosition(1.0F, 67.0F);

   sf::RectangleShape h3(horizontalSize);
   buildRectangleDefaults(h3);
   h3.setPosition(1.0F, 133.0F);

   // vertical rectangles
   sf::RectangleShape v1(verticalSize);
   buildRectangleDefaults(v1);
   v1.setPosition(1.0F, 1.0F);

   sf::RectangleShape v2(verticalSize);
   buildRectangleDefaults(v2);
   v2.setPosition(67.0F, 1.0F);

   sf::RectangleShape v3(verticalSize);
   buildRectangleDefaults(v3);
   v3.setPosition(133.0F, 1.0F);


   _grid.push_back(h1);
   _grid.push_back(h2);
   _grid.push_back(h3);
   _grid.push_back(v1);
   _grid.push_back(v2);
   _grid.push_back(v3);
}

GameBoard::~GameBoard()
{
   // Empty
}

void GameBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_background, states);

   for (auto e : _grid)
   {
      target.draw(e, states);
   }
}

void GameBoard::buildRectangleDefaults(sf::RectangleShape& rect)
{
   rect.setOutlineColor(sf::Color::Blue);
   rect.setFillColor(sf::Color::Transparent);
   rect.setOutlineThickness(3);
}

} /* namespace X2048 */
} /* namespace Minigames */
