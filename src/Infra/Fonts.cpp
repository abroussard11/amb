/*
 * FontFactory.cpp
 *
 *  Created on: Dec 28, 2014
 *      Author: aaron
 */

#include <Infra/Fonts.h>

namespace Infra {

sf::Font Fonts::luxirb;
sf::Font Fonts::luxirbi;

Fonts::Fonts()
{
   // Empty
}

Fonts::~Fonts()
{
   // Empty
}

void Fonts::initFonts()
{
   luxirb.loadFromFile("/usr/share/fonts/truetype/luxirb.ttf");
   luxirbi.loadFromFile("/usr/share/fonts/truetype/luxirbi.ttf");
}

} /* namespace Infra */
