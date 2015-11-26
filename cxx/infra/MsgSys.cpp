/**
 * infra/MsgSys.cpp
 */

#include <iostream>
#include <infra/MsgSys.h>

namespace infra {

MsgSys::Ptr MsgSys::_instance;
std::vector<MsgSys::InboxPair> MsgSys::_database;

MsgSys* MsgSys::getInstance()
{
   if (_instance == nullptr)
   {
      _instance = std::make_unique<MsgSys>();
   }

   return _instance.get();
}

void MsgSys::add(Message::shPtr msg)
{
   auto hash = msg->getHash();
   for (auto& inboxPair : _database)
   {
      if (inboxPair.first == hash)
      {
         inboxPair.second->add(msg);
      }
   }
}

} // End namespace infra
