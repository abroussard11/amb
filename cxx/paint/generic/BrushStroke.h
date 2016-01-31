/**
 * Paint/generic/BrushStroke.h
 */

#ifndef PAINT_BRUSHSTROKE_H_
#define PAINT_BRUSHSTROKE_H_

#include <SFML/Graphics/Vertex.hpp>
#include <amb/GuiComponent.h>

namespace paint {

class BrushStroke : public amb::GuiComponent
{
public:
   using Point = sf::Vector2f;

   BrushStroke(Point start, Point end);
   virtual ~BrushStroke() = default;

private:
   sf::Vertex _line[2];

   void drawSelf(Target& target, States states) const override;
   //void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;

};

} // End namespace paint

#endif // PAINT_BRUSHSTROKE_H_

