/*
 * MainMenu.cpp
 *
 *  Created on: Dec 29, 2014
 *      Author: aaron
 */

#include <iostream>
#include <thread>
#include <Menus/MainMenu.h>

#include <Minigames/MadLib/MadLibMinigame.h>
#include <Minigames/X2048/X2048Minigame.h>

namespace Menus {

MainMenu::MainMenu() :
      _isGameRunning(false), //
      _mouseX(0), //
      _mouseY(0), //
      _luxirb(), //
      _luxirbi(), //
      _backgroundTexture(), //
      _backgroundSprite(), //
      _logoTexture(), //
      _logoSprite(), //
      _titleText(), //
      _introText(), //
      _buttons()
{
   // Load Fonts
   _luxirb.loadFromFile("/usr/share/fonts/truetype/luxirb.ttf");
   _luxirbi.loadFromFile("/usr/share/fonts/truetype/luxirbi.ttf");

   // Load Background
   _backgroundTexture.loadFromFile("data/MainMenuBackground2.png");
   _backgroundSprite.setTexture(_backgroundTexture);

   // Load Logo
   _logoTexture.loadFromFile("data/AmbLogoThick.png");
   _logoSprite.setTexture(_logoTexture);
   _logoSprite.setScale(0.1, 0.1);

   // Load Title
   _titleText.setFont(_luxirbi);
   _titleText.setCharacterSize(40); // in pixels, not points
   _titleText.setString("AmbGames");
   sf::Color myOrange(210, 100, 0);
   _titleText.setColor(myOrange);
   sf::FloatRect logoRect = _titleText.getGlobalBounds();
   _titleText.setPosition(350 - (logoRect.width / 2), 0);

   // Load Intro
   sf::Text introtext;
   introtext.setFont(_luxirb);
   introtext.setCharacterSize(60); // in pixels, not points
   introtext.setString("Select Minigame:");
   introtext.setColor(myOrange);
   introtext.setPosition(30, 100);

   // Load Buttons
   MainMenuTextButton mlButton("2048", _luxirb);
   mlButton.setAction(Infra::Minigame::Ptr(new Minigames::X2048::X2048Minigame));
   mlButton.setPosition(30, 500);

   _buttons.push_back(mlButton);
}

MainMenu::~MainMenu()
{
   // Empty
}

bool MainMenu::isGameRunning() const
{
   return _isGameRunning;
}

void MainMenu::processEvent(sf::Event event)
{
   if (event.type == sf::Event::MouseMoved)
   {
         _mouseX = event.mouseMove.x;
         _mouseY = event.mouseMove.y;
         std::cout << "NEW MOUSE LOC: " << _mouseX << ", " << _mouseY << std::endl;
   }

   if (event.type == sf::Event::MouseButtonReleased)
   {
      for (auto& button : _buttons)
      {
         sf::RectangleShape rectShape = button.getButton();
         sf::Transform transform = button.getTransform();
         sf::FloatRect rect = transform.transformRect(rectShape.getGlobalBounds());
         if (rect.contains(_mouseX, _mouseY))
         {
            std::cout << "BUTTON CLICKED" << std::endl;
            _isGameRunning = true;
            _selectedButton = Menus::MainMenuTextButton::Ptr(new Menus::MainMenuTextButton(button));
         }
         else
         {
            std::cout << "MISSED: top = " << rect.top << ", left = "  << rect.left << ", height = " << rect.height << ", width = " << rect.width << std::endl;
         }
      }
   }
}

void MainMenu::startGame()
{
   _isGameRunning = false;
   _selectedButton->click();
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   target.draw(_backgroundSprite, states);
   target.draw(_logoSprite, states);
   target.draw(_titleText, states);
   target.draw(_introText, states);

   for (auto& button : _buttons)
   {
      target.draw(button, states);
   }
}

} /* namespace Menus */
