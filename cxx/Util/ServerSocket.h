/**
 * Util/SeverSocket.h
 */

#ifndef UTIL_SERVERSOCKET_H_
#define UTIL_SERVERSOCKET_H_

#include <Util/Socket.h>

namespace Util {

class ServerSocket : public Socket {
 public:
  ServerSocket(int port);
  ServerSocket() = default;
  virtual ~ServerSocket();

  const ServerSocket& operator<<(const std::string&) const;
  const ServerSocket& operator>>(std::string&) const;

  void accept(ServerSocket&);
};

} // End namespace Util

#endif  // UTIL_SERVERSOCKET_H_
