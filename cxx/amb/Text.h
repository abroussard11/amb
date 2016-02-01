/**
 * amb/Text.h
 */

#ifndef AMB_TEXT_H_
#define AMB_TEXT_H_

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <amb/GuiComponent.h>

namespace amb {

class Text : public amb::GuiComponent {
 public:
  Text() = default;
  virtual ~Text() = default;
  Text(const sf::String& string, const sf::Font& font);

  void setPosition(sf::Vector2f pos);
  void setPosition(float x, float y);
  void setCharacterSize(unsigned int size);
  void setColor(const sf::Color& color);

  sf::Text data;

 private:
  virtual void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const override;
};

}  // End namespace amb

#endif  // AMB_TEXT_H_
