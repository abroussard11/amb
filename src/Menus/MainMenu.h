/*
 * MainMenu.h
 *
 *  Created on: Dec 29, 2014
 *      Author: aaron
 */

#ifndef SRC_MENUS_MAINMENU_H_
#define SRC_MENUS_MAINMENU_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include <Menus/MainMenuTextButton.h>

namespace Menus {

class MainMenu : public sf::Drawable
{
public:
   MainMenu();
   virtual ~MainMenu();

   virtual bool isGameRunning() const;
   virtual void startGame();
   virtual void processEvent(sf::Event event);

private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   bool _isGameRunning;
   Menus::MainMenuTextButton::Ptr _selectedButton;
   int _mouseX;
   int _mouseY;

   sf::Font _luxirb;
   sf::Font _luxirbi;
   sf::Texture _backgroundTexture;
   sf::Sprite _backgroundSprite;
   sf::Texture _logoTexture;
   sf::Sprite _logoSprite;
   sf::Text _titleText;
   sf::Text _introText;
   std::vector<Menus::MainMenuTextButton> _buttons;
};

} /* namespace Menus */

#endif /* SRC_MENUS_MAINMENU_H_ */
