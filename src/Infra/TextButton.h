/*
 * TextButton.h
 *
 *  Created on: Dec 26, 2014
 *      Author: aaron
 */

#ifndef SRC_INFRA_TEXTBUTTON_H_
#define SRC_INFRA_TEXTBUTTON_H_

#include <SFML/Graphics.hpp>

namespace Infra {

class TextButton : public sf::Drawable, public sf::Transformable
{
public:
   TextButton();
   virtual ~TextButton();

   virtual void setText(sf::Text text);
   virtual sf::Text getText() const;
   virtual void setButton(sf::RectangleShape button);
   virtual sf::RectangleShape getButton() const;

private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   sf::Text _text;
   sf::RectangleShape _button;
};

} /* namespace Infra */

#endif /* SRC_INFRA_TEXTBUTTON_H_ */
