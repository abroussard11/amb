/**
 * infra/Msg.h
 */

#ifndef INFRA_MSG_H_
#define INFRA_MSG_H_

//#include <infra/InboxBase.h>
#include <infra/Message.h>
#include <infra/MsgSys.h>

namespace infra {

template <typename T>
class Msg : public Message {
 public:
  T content;

  Msg() = default;
  Msg(T copy) : content(copy) {}
  virtual ~Msg() = default;

  Message::shPtr makeSharedMsg() override {
    return shPtr{std::make_shared<Msg<T>>(content)};
  }

  void send() { //
    MsgSys::getInstance()->add(makeSharedMsg());
  }

  std::size_t getHash() override { //
    return typeid(T).hash_code();
  }
};

}  // End namespace infra

#endif  // INFRA_MSG_H_
