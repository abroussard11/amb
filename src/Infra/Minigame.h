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
 * This is an Interface Class - every method is pure-virtual meaning
 * there is no implementation defined here, and any class that derives
 * from this interface MUST supply an implementation for each method
 */
class Minigame
{
public:
   typedef std::shared_ptr<Minigame> Ptr;

   virtual ~Minigame() {}
   virtual void play() {}
//   virtual void processEvent(const sf::Event& event) = 0;
//   virtual void update() = 0;
//   virtual const sf::Drawable& getDrawable() const = 0;
};

} /* namespace Infra */

#endif /* SRC_INFRA_MINIGAME_H_ */
