/**
 * Util/ServerSocket.cpp
 */

#include <Util/ServerSocket.h>
#include <Util/SocketException.h>

namespace Util {

ServerSocket::ServerSocket(int port) {
  create(port);
}

void ServerSocket::create(int port) {
  if (!Socket::create()) {
    throw SocketException("Could not create server socket.");
  }

  if (!Socket::bind(port)) {
    throw SocketException("Could not bind to port.");
  }

  if (!Socket::listen()) {
    throw SocketException("Could not listen to socket.");
  }
}

void ServerSocket::accept(ServerSocket& sock) {
  if (!Socket::accept(sock)) {
    throw SocketException("Could not accept socket.");
  }
}

const ServerSocket& ServerSocket::operator<<(const std::string& s) const {
  if (!Socket::send(s)) {
    throw SocketException("Could not write to socket.");
  }
  return *this;
}

const ServerSocket& ServerSocket::operator>>(std::string& s) const {
  if (!Socket::recv(s)) {
    throw SocketException("Could not read from socket.");
  }
  return *this;
}

ServerSocket& ServerSocket::operator<<(std::stringstream& ss) {
  if (!Socket::send(ss.str())) {
    throw SocketException("Could not write to socket.");
  }
  return *this;
}

ServerSocket& ServerSocket::operator>>(std::stringstream& ss) {
  std::string s;
  if (!Socket::recv(s)) {
    throw SocketException("Could not read from socket.");
  }
  ss.str(s);
  return *this;
}

} // End namespace Util
