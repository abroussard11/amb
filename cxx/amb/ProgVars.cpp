/**
 * amb/ProgVars.cpp
 */

#include <amb/ProgVars.h>

namespace amb {

ProgVars::ProgVars() :
   playerName("Unknown"), //
   dllName(""), //
   senderIp("0.0.0.0")
{
   // Empty
}

ProgVars::~ProgVars()
{
   // Empty
}

std::string ProgVars::toString() const
{
   std::string s("ProgVars:");
   s += "\n\tPlayerName = " + playerName;
   s += "\n\t   DllName = " + dllName;
   s += "\n\t  SenderIp = " + senderIp;
   s += "\n";

   return s;
}

} // End namespace amb
