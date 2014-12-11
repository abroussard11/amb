/*
 * MadLibMinigame.h
 *
 *  Created on: Dec 6, 2014
 *      Author: Aaron
 */

#ifndef SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_
#define SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_

#include <Minigames/Minigame.h>

namespace Minigames {
namespace MadLib {

class MadLibMinigame : public Minigame
{
public:
   MadLibMinigame();
   virtual ~MadLibMinigame();

   virtual void play();
};

} /* namespace MadLib */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_ */
