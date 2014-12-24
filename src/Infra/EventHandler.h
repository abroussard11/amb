/*
 * EventHandler.h
 *
 *  Created on: Dec 12, 2014
 *      Author: aaron
 */

#ifndef SRC_INFRA_EVENTHANDLER_H_
#define SRC_INFRA_EVENTHANDLER_H_

#include <memory>
#include <SFML/Window/Event.hpp>

namespace Infra {

/**
 * Interface class for handling events
 *    e.g. sf::Event::KeyPressed
 */
class EventHandler
{
public:
   typedef std::shared_ptr<EventHandler> Ptr;

   virtual ~EventHandler() {}
   virtual void processEvent(const sf::Event& event);
};

} /* namespace Infra */

#endif /* SRC_INFRA_EVENTHANDLER_H_ */
