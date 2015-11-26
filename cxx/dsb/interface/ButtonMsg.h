/**
 * dsb/ButtonMsg.h
 */

#ifndef DSB_BUTTONMSG_H_
#define DSB_BUTTONMSG_H_

#include <string>

namespace dsb {

class ButtonMsg
{
public:
   ButtonMsg() = default;
   virtual ~ButtonMsg() = default;

   std::string x;
};

} // End namespace dsb

#endif // DSB_BUTTONMSG_H_
