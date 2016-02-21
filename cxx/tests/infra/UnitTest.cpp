/**
 * tests/infra/UnitTest.cpp
 */

#include <tests/infra/UnitTest.h>

#include <infra/Inbox.h>
#include <infra/Msg.h>
#include <infra/MsgSys.h>

namespace infra {

void UnitTest::testRoutine() {
  // A test message data type
  struct Position {
    int x;
    int y;
  };

  // testMsg(): begin - tests 1,2,3,4
  infra::Msg<Position> msg;
  msg.content.x = 1;
  msg.content.y = 2;
  trackTest(msg.content.x == 1);  // test 1
  trackTest(msg.content.y == 2);  // test 2

  auto msgP = msg.makeSharedMsg();
  auto msgP2 = msg.makeSharedMsg();
  trackTest(msgP.get() != msgP2.get());  // test 3
  msg.content.x = 2;
  auto msgPx = (static_cast<infra::Msg<Position>*>(msgP.get()))->content.x;
  trackTest(msg.content.x != msgPx);  // test 4
  // testMsg(): end

  // testInbox(): begin - tests 5,6,7
  infra::Inbox<Position> inbox;
  requireEqual(inbox.msgs.size(), 0);  // test 5
  inbox.add(msg.makeSharedMsg());
  requireEqual(inbox.msgs.size(), 1);  // test 6

  auto msgs = inbox.getMessages();
  requireEqual(inbox.msgs.size(), 0);  // test 7
  // testInbox(): end

  // testMsgSys(): begin - tests 8
  trackTest(construct<infra::MsgSys>());  // test 8
  auto inbox2 = std::make_shared<infra::Inbox<Position>>();
  infra::registerInbox<Position>(inbox2);
  // inbox2.registerInbox(msg2.getHash());
  infra::Msg<Position> msg2;
  msg2.content.x = 3;
  msg2.content.y = 4;
  msg2.send();
  // msys->add(msg.makeShared());
  auto msgs2 = inbox2->getMessages();
  requireEqual(msgs2.size(), 1);
  requireEqual(msgs2.at(0).content.x, 3);
  requireEqual(msgs2.at(0).content.y, 4);

  // testMsgSys(): end
}

}  // End namespace infra
