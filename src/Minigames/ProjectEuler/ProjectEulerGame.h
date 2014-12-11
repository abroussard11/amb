/*
 * ProjectEulerGame.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_
#define SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_

#include <Minigames/Minigame.h>
#include <Minigames/ProjectEuler/ProblemLoader.h>

namespace Minigames {
namespace ProjectEuler {

class ProjectEulerGame : public Minigame
{
public:
   ProjectEulerGame();
   virtual ~ProjectEulerGame();

   virtual void play();

private:
   ProblemLoader _problemLoader;
};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_ */
