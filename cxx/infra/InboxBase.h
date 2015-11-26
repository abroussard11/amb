/**
 * infra/InboxBase.h
 */

#ifndef INFRA_INBOXBASE_H_
#define INFRA_INBOXBASE_H_

#include <vector>
#include <infra/Message.h>

namespace infra {

class InboxBase
{
public:
   std::vector<Message::shPtr> msgs;
   using Ptr = std::shared_ptr<InboxBase>;

   InboxBase() = default;
   virtual ~InboxBase() = default;

   auto add(Message::shPtr msg)
   {
      msgs.push_back(msg);
   }

   // auto getMessages()
   // {
   //    auto msgsCopy = msgs;
   //    msgs.clear();
   //    return msgsCopy;
   // }
};

} // End namespace infra

#endif // INFRA_INBOXBASE_H_
