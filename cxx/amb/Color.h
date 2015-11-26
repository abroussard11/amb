/**
 * amb/Color.h
 */

#ifndef AMB_COLOR_H_
#define AMB_COLOR_H_

#include <SFML/Graphics/Color.hpp>

namespace amb {

class Color : public sf::Color
{
public:
   static const sf::Color Gray;
   static const sf::Color DsbGreen;

   Color() = default;
   virtual ~Color() = default;
};

} // End namespace amb

#endif // AMB_COLOR_H_
