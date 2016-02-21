/**
 * x2048/GameBackground.h
 */

#ifndef X2048_GAMEBACKGROUND_H_
#define X2048_GAMEBACKGROUND_H_

#include <SFML/Graphics/RectangleShape.hpp>

namespace x2048 {

class GameBackground
{
public:
   GameBackground();
   virtual ~GameBackground() = default;

private:
   sf::RectangleShape _rect;
};

} // End namespace x2048

#endif // X2048_GAMEBACKGROUND_H_

