/*
 * MadLibMinigame.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: aaron
 */

#include <iostream>
#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/MadLib/Helper.h>
#include <Minigames/MadLib/Library.h>

namespace Minigames {
namespace MadLib {

MadLibMinigame::MadLibMinigame()
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

} /* namespace MadLib */
} /* namespace Minigames */
