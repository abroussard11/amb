/**
 * dsb/gui/left/Button.h
 */

#ifndef DSB_BUTTON_H_
#define DSB_BUTTON_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>
#include <dsb/interface/ButtonMsg.h>
#include <infra/Msg.h>

namespace dsb {
namespace gui {
namespace left {

class Button : public amb::GuiComponent
{
public:
   using Ptr = std::unique_ptr<Button>;

   Button();
   virtual ~Button() = default;

   void setString(std::string str);
   void setSize(float width, float height);
   void centerText();

protected:
   virtual void onMouseButtonPressed(sf::Event& event) override;
   virtual void onMouseButtonReleased(sf::Event& event) override;

private:
   sf::RectangleShape _rect;
   sf::RectangleShape _boundingBox;
   sf::Text _text;
   infra::Msg<ButtonMsg> _msg;

   virtual void updateSelf() override;
   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;
   bool isClickOnButton(sf::Event& event);
};

} // End namespace left
} // End namespace gui
} // End namespace dsb

#endif // DSB_BUTTON_H_
