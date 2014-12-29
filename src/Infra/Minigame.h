/*
 * Minigame.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_INFRA_MINIGAME_H_
#define SRC_INFRA_MINIGAME_H_

#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace Infra {

/**
 * This is an Abstract Interface Class - every method is pure-virtual meaning
 * there is no implementation defined here, and any class that derives
 * from this interface MUST supply an implementation for each method
 */
class Minigame
{
public:
   typedef std::shared_ptr<Minigame> Ptr;

   virtual ~Minigame() {}
   virtual void play() {} // TODO: make this pure virtual when testing phase is complete
};

} /* namespace Infra */

#endif /* SRC_INFRA_MINIGAME_H_ */
