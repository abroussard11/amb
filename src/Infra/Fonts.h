/*
 * FontFactory.h
 *
 *  Created on: Dec 28, 2014
 *      Author: aaron
 */

#ifndef SRC_INFRA_FONTFACTORY_H_
#define SRC_INFRA_FONTFACTORY_H_

#include <map>
#include <SFML/Graphics/Font.hpp>

namespace Infra {

class Fonts
{
public:
   static sf::Font luxirb;
   static sf::Font luxirbi;

   Fonts();
   virtual ~Fonts();

   static void initFonts();
};

} /* namespace Infra */

#endif /* SRC_INFRA_FONTFACTORY_H_ */
