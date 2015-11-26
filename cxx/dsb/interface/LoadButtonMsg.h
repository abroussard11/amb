/**
 * dsb/interface/LoadButtonMsg.h
 */

#ifndef DSB_INTERFACE_LOADBUTTONMSG_H_
#define DSB_INTERFACE_LOADBUTTONMSG_H_

#include <string>

namespace dsb {

class LoadButtonMsg
{
public:
   LoadButtonMsg() = default;
   virtual ~LoadButtonMsg() = default;

   std::string x;
};

} // End namespace dsb

#endif // DSB_INTERFACE_LOADBUTTONMSG_H_
