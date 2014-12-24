/*
 * MadLibMinigame.h
 *
 *  Created on: Dec 6, 2014
 *      Author: Aaron
 */

#ifndef SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_
#define SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_

#include <Infra/Minigame.h>

namespace Minigames {
namespace MadLib {

class MadLibMinigame : public Infra::Minigame
{
public:
   MadLibMinigame();
   virtual ~MadLibMinigame();

   virtual void play();
   virtual void processEvent(const sf::Event& event);
   virtual void update();
//   virtual const sf::Drawable& getDrawable() const;

private:
   std::shared_ptr<sf::Drawable> _canvas;
};

} /* namespace MadLib */
} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MADLIB_MADLIBMINIGAME_H_ */
