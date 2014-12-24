/*
 * ADumbGame.h
 *
 *  Created on: Dec 7, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_
#define SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_

#include <Infra/Minigame.h>

namespace Minigames {
namespace DumbGame {

class ADumbGame : public Infra::Minigame
{
public:
   ADumbGame();
   virtual ~ADumbGame();

   virtual void processEvent(const sf::Event& event);
   virtual void update();
   virtual sf::Drawable& getDrawable();

private:
   std::shared_ptr<sf::Drawable> _canvas;
};

} /* namespace DumbGame */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_ */
