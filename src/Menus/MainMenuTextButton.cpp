/*
 * MainMenuTextButton.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: aaron
 */
#include <iostream>
#include <Menus/MainMenuTextButton.h>
#include <Infra/Fonts.h>

namespace Menus {

MainMenuTextButton::MainMenuTextButton(std::string str, sf::Font& font) :
      TextButton(), //
      _game()
{
   sf::Text text;
   text.setFont(font);
   text.setCharacterSize(30);
   sf::Color myOrange(210, 100, 0);
   text.setColor(myOrange);
   text.setString(str);

   sf::RectangleShape button(sf::Vector2f(130, 40));
   button.setFillColor(sf::Color::Cyan);

   TextButton::setText(text);
   TextButton::setButton(button);
}

MainMenuTextButton::~MainMenuTextButton()
{
   // Empty
}

void MainMenuTextButton::click()
{
   _game->play();
}

void MainMenuTextButton::setAction(Infra::Minigame::Ptr game)
{
   _game = game;
}

Infra::Minigame::Ptr MainMenuTextButton::getAction() const
{
   return _game;
}

/**
 * Private member functions
 */
MainMenuTextButton::MainMenuTextButton()
{
   // Empty
}

} /* namespace Menus */
