/**
 * dsb/gui/top/PanelTop.h
 */

#ifndef DSB_GUI_TOP_PANELTOP_H_
#define DSB_GUI_TOP_PANELTOP_H_

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <amb/GuiComponent.h>
#include <amb/Text.h>

namespace dsb {
namespace gui {
namespace top {

class PanelTop : public amb::GuiComponent
{
public:
   PanelTop() = delete;
   PanelTop(sf::VideoMode mode);
   virtual ~PanelTop() = default;

private:
   sf::RectangleShape _rect;
   sf::Text _search;
   amb::Text _searcha;

   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;
};

} // End namespace top
} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_TOP_PANELTOP_H_
