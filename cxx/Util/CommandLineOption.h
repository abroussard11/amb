/******************************************
 * The CommandLineOption Struct Definition
 ******************************************/

#ifndef UTIL_COMMANDLINEOPTION_H_
#define UTIL_COMMANDLINEOPTION_H_

#include <memory>
#include <string>
#include <vector>

namespace Util {

class CommandLineOption
{
public:
   typedef std::shared_ptr<CommandLineOption> Ptr;

   std::string option;
   std::vector<std::string> values;

   CommandLineOption(std::string op = "") :
      option(op),
      values()
   {
      // Empty
   }

   bool operator ==(const CommandLineOption& other)
   {
      return option == other.option;
   }
};

} // End namespace Util

#endif // UTIL_COMMANDLINEOPTION_H_
