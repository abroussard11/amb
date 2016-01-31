/**
 * Paint/generic/BrushStroke.cpp
 */

#include <paint/generic/BrushStroke.h>

namespace paint {

BrushStroke::BrushStroke(Point start, Point end) :
   GuiComponent()
{
   _line[0] = sf::Vertex(start, sf::Color::Green);
   _line[1] = sf::Vertex(end, sf::Color::Green);
}

void BrushStroke::drawSelf(Target& target, States states) const
{
   target.draw(_line, 2, sf::Lines, states);
}

} // End namespace paint
