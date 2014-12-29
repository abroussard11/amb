/*
 * MainMenuTextButton.h
 *
 *  Created on: Dec 26, 2014
 *      Author: aaron
 */

#ifndef SRC_MENUS_MAINMENUTEXTBUTTON_H_
#define SRC_MENUS_MAINMENUTEXTBUTTON_H_

#include <memory>
#include <Infra/Clickable.h>
#include <Infra/Minigame.h>
#include <Infra/TextButton.h>

namespace Menus {

class MainMenuTextButton : public Infra::TextButton, public Infra::Clickable
{
public:
   typedef std::shared_ptr<MainMenuTextButton> Ptr;

   MainMenuTextButton(std::string str, sf::Font& font);
   virtual ~MainMenuTextButton();

   virtual void click();
   virtual void setAction(Infra::Minigame::Ptr game);

private:
   MainMenuTextButton();

   Infra::Minigame::Ptr _game;
};

} /* namespace Menus */

#endif /* SRC_MENUS_MAINMENUTEXTBUTTON_H_ */
