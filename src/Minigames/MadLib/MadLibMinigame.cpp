/*
 * MadLibMinigame.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/MadLib/Helper.h>
#include <Minigames/MadLib/Library.h>

namespace Minigames {
namespace MadLib {

MadLibMinigame::MadLibMinigame() :
      _canvas(new sf::CircleShape)
{
	// Empty
}

MadLibMinigame::~MadLibMinigame()
{
	// Empty
}

void MadLibMinigame::play()
{
   Helper _helper;
   std::cout << std::endl << _helper.parseString(Library::LetterFromCamp) << std::endl;
}

void MadLibMinigame::processEvent(const sf::Event& event)
{

}

void MadLibMinigame::update()
{

}

//const sf::Drawable& MadLibMinigame::getDrawable() const
//{
//   return _canvas.get();
//}

} /* namespace MadLib */
} /* namespace Minigames */
