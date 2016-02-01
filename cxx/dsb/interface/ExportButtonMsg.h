/**
 * dsb/interface/ExportButtonMsg.h
 */

#ifndef DSB_INTERFACE_EXPORTBUTTONMSG_H_
#define DSB_INTERFACE_EXPORTBUTTONMSG_H_

#include <string>

namespace dsb {

class ExportButtonMsg {
 public:
  ExportButtonMsg() = default;
  virtual ~ExportButtonMsg() = default;

  std::string x;
};

}  // End namespace dsb

#endif  // DSB_INTERFACE_EXPORTBUTTONMSG_H_
