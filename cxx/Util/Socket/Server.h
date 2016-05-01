/**
 * Util/SeverSocket.h
 */

#ifndef UTIL_SERVERSOCKET_H_
#define UTIL_SERVERSOCKET_H_

#include <sstream>
#include <Util/Socket.h>

namespace Util {

class ServerSocket : public Socket {
 public:
  ServerSocket(int port);
  ServerSocket() = default;
  virtual ~ServerSocket();

  void create(int port);
  void accept(ServerSocket&);

  const ServerSocket& operator<<(const std::string&) const;
  const ServerSocket& operator>>(std::string&) const;

  ServerSocket& operator<<(std::stringstream& ss);
  ServerSocket& operator>>(std::stringstream& ss);
};

} // End namespace Util

#endif  // UTIL_SERVERSOCKET_H_
