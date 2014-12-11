/*
 * ADumbGame.h
 *
 *  Created on: Dec 7, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_
#define SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_

#include <Minigames/Minigame.h>

namespace Minigames {
namespace DumbGame {

class ADumbGame : public Minigame
{
public:
   ADumbGame();
   virtual ~ADumbGame();

   virtual void play();
};

} /* namespace DumbGame */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_DUMBGAME_ADUMBGAME_H_ */
