/**
 * infra/MsgSys.h
 */

#ifndef INFRA_MSGSYS_H_
#define INFRA_MSGSYS_H_

#include <memory>
#include <vector>
#include <infra/InboxBase.h>

namespace infra {

/**
 * Messaging System
 */
class MsgSys
{
public:
   using Ptr = std::unique_ptr<MsgSys>;
   using InboxPair = std::pair<std::size_t, InboxBase::Ptr>;

   static MsgSys* getInstance();

   MsgSys() = default;
   virtual ~MsgSys() = default;

   void add(Message::shPtr msg);

   static void registerInbox(std::size_t hash, InboxBase::Ptr inbox)
   {
      _database.push_back(std::make_pair(hash, inbox));
   }

private:
   static Ptr _instance;
   static std::vector<InboxPair> _database;
};

} // End namespace infra

#endif // INFRA_MSGSYS_H_
