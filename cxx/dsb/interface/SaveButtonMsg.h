/**
 * dsb/interface/SaveButtonMsg.h
 */

#ifndef DSB_INTERFACE_SAVEBUTTONMSG_H_
#define DSB_INTERFACE_SAVEBUTTONMSG_H_

#include <string>

namespace dsb {

class SaveButtonMsg
{
public:
   SaveButtonMsg() = default;
   virtual ~SaveButtonMsg() = default;

   std::string x;
};

} // End namespace dsb

#endif // DSB_INTERFACE_SAVEBUTTONMSG_H_
