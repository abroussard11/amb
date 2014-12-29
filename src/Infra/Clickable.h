/*
 * Clickable.h
 *
 *  Created on: Dec 29, 2014
 *      Author: aaron
 */

#ifndef SRC_INFRA_CLICKABLE_H_
#define SRC_INFRA_CLICKABLE_H_

namespace Infra {

class Clickable
{
public:
   virtual ~Clickable() {}

   virtual void click() = 0;
};

} /* namespace Infra */

#endif /* SRC_INFRA_CLICKABLE_H_ */
