/**
 * infra/Inbox.h
 */

#ifndef INFRA_INBOX_H_
#define INFRA_INBOX_H_

#include <infra/InboxBase.h>
#include <infra/Msg.h>

namespace infra {

template <typename T>
class Inbox : public InboxBase
{
public:
   using Ptr = std::shared_ptr<Inbox<T>>;
   Inbox() = default;
   virtual ~Inbox() = default;

    static Ptr makeInbox()
    {
       return std::make_shared<Inbox<T>>();
    }

   std::vector<Msg<T>> getMessages()
   {
      std::vector<Msg<T>> msgsT;
      msgsT.reserve(msgs.size());
      for (auto& m : msgs)
      {
         auto raw_base = m.get();
         auto raw_derived = static_cast<Msg<T>*>(raw_base);
         msgsT.push_back(*raw_derived);
      }
      msgs.clear();

      return msgsT;
   }
};

template <typename T>
void registerInbox(InboxBase::Ptr inbox)
{
   std::size_t hash = Msg<T>().getHash();
   MsgSys::getInstance()->registerInbox(hash, inbox);
}

} // End namespace infra

#endif // INFRA_INBOX_H_
