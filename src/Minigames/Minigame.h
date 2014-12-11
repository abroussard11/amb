/*
 * Minigame.h
 *
 *  Created on: Dec 10, 2014
 *      Author: aaron
 */

#ifndef SRC_MINIGAMES_MINIGAME_H_
#define SRC_MINIGAMES_MINIGAME_H_

#include <memory>

namespace Minigames {

/**
 * This is an Interface Class - every method is pure-virtual meaning
 * there is no implementation defined here, and any class that derives
 * from this interface MUST supply an implementation for each method
 */
class Minigame
{
public:
   typedef std::shared_ptr<Minigame> Ptr;
   virtual ~Minigame()
   {
   }

   virtual void play() = 0;
};

} /* namespace Minigames */

#endif /* SRC_MINIGAMES_MINIGAME_H_ */
