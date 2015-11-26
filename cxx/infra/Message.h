/**
 * infra/Message.h
 */

#ifndef INFRA_MESSAGE_H_
#define INFRA_MESSAGE_H_

#include <memory>

namespace infra {

class Message
{
public:
   using shPtr = std::shared_ptr<Message>;
   virtual ~Message() = default;

   virtual Message::shPtr makeSharedMsg() = 0;
   virtual std::size_t getHash() = 0;
};

} // End namespace infra

#endif // INFRA_MESSAGE_H_
