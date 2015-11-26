/**
 * dsb/Button.h
 */

#ifndef DSB_GUI_TOP_BUTTON_H_
#define DSB_GUI_TOP_BUTTON_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>
#include <infra/Msg.h>

namespace dsb {
namespace gui {
namespace top {

class ButtonBase : public amb::GuiComponent
{
public:
   using Ptr = std::unique_ptr<ButtonBase>;

   ButtonBase();
   virtual ~ButtonBase() = default;

   void setString(std::string str);
   void setSize(float width, float height);
   void centerText();

protected:
   sf::RectangleShape _boundingBox;

   virtual void onMouseButtonPressed(sf::Event& event) override;
   virtual void onMouseButtonReleased(sf::Event& event) override;
   bool isClickOnButton(sf::Event& event);

private:
   sf::RectangleShape _rect;
   sf::Text _text;

   virtual void updateSelf() override;
   virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;
};

template <typename T>
class Button : public ButtonBase
{
public:
   Button() = default;
   virtual ~Button() = default;

   void setString(std::string str)
   {
      ButtonBase::setString(str);
      _msg.content.x = str;
   }

protected:
   virtual void onMouseButtonReleased(sf::Event& event) override
   {
      auto color = sf::Color::Transparent;
      if (isClickOnButton(event))
      {
         color = sf::Color::Red;
      _msg.send();
      }
      _boundingBox.setOutlineColor(color);
   }

private:
   infra::Msg<T> _msg;
};

} // End namespace top
} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_TOP_BUTTON_H_
