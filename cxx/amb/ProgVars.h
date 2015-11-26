/**
 * amb/ProgVars.h
 */

#ifndef AMB_PROGVARS_H_
#define AMB_PROGVARS_H_

#include <memory>
#include <string>

namespace amb {

class ProgVars
{
public:
   typedef std::shared_ptr<ProgVars> Ptr;

   ProgVars();
   virtual ~ProgVars();

   std::string toString() const;

   std::string playerName;
   std::string dllName;
   std::string senderIp;
};

} // End namespace amb

#endif //AMB_PROGVARS_H_
