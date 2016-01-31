/**
 * paint/SmallBrush.h
 */

#ifndef PAINT_GENERIC_SMALLBRUSH_H
#define PAINT_GENERIC_SMALLBRUSH_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <amb/GuiComponent.h>

namespace paint {

class SmallBrush : public amb::GuiComponent
{
public:
   SmallBrush(float x, float y);
   virtual ~SmallBrush() = default;

private:
   sf::RectangleShape _tile;

   void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;
};

} // End namespace paint

#endif // PAINT_GENERIC_SMALLBRUSH_H
