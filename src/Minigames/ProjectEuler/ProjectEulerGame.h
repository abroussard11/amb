/*
 * ProjectEulerGame.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_
#define SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_

#include <Infra/Minigame.h>
#include <Minigames/ProjectEuler/ProblemLoader.h>

namespace Minigames {
namespace ProjectEuler {

class ProjectEulerGame : public Infra::Minigame
{
public:
   ProjectEulerGame();
   virtual ~ProjectEulerGame();

   virtual void play();
   virtual void processEvent(const sf::Event& event);
   virtual void update();

private:
   std::shared_ptr<sf::Drawable> _canvas;
   ProblemLoader _problemLoader;

};

} /* namespace ProjectEuler */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_PROJECTEULER_PROJECTEULERGAME_H_ */
