/**
 * dsb/gui/top/SearchBar.h
 */

#ifndef DSB_GUI_TOP_SEARCHBAR_H_
#define DSB_GUI_TOP_SEARCHBAR_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <amb/GuiComponent.h>

namespace dsb {
namespace gui {
namespace top {

class SearchBar : public amb::GuiComponent
{
public:
   SearchBar();
   virtual ~SearchBar() = default;

   void setSize(float width, float height);
   void setPosition(float x, float y);

protected:
   virtual void onMouseButtonPressed(sf::Event& event) override;
   virtual void onMouseButtonReleased(sf::Event& event) override;

private:
   sf::RectangleShape _rect;
   unsigned char _frames;
   bool _drawCursor;
   sf::RectangleShape _cursor;

   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;
   virtual void updateSelf() override;
   bool isClickOnSelf(sf::Event& event);
};

} // End namespace top
} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_TOP_SEARCHBAR_H_
