
// Definition of the ClientSocket class

#ifndef UTIL_CLIENTSOCKET_H_
#define UTIL_CLIENTSOCKET_H_

#include <Util/Socket.h>

namespace Util {

class ClientSocket : public Socket {
 public:
  ClientSocket(std::string host, int port);
  virtual ~ClientSocket(){};

  const ClientSocket& operator<<(const std::string&) const;
  const ClientSocket& operator>>(std::string&) const;
};

}  // End namespace Util

#endif
