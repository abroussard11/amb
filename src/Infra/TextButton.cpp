/*
 * TextButton.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: aaron
 */

#include <Infra/TextButton.h>

namespace Infra {

TextButton::TextButton() :
   _text(),
   _button()
{
   // Empty
}

TextButton::~TextButton()
{
   // Empty
}

void TextButton::setText(sf::Text text)
{
   _text = text;
}

sf::Text TextButton::getText() const
{
   return _text;
}

void TextButton::setButton(sf::RectangleShape button)
{
   _button = button;
}

sf::RectangleShape TextButton::getButton() const
{
   return _button;
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   states.transform *= getTransform();

   target.draw(_button, states);
   target.draw(_text, states);
}

} /* namespace Infra */
