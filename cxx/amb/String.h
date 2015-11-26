/**
 * amb/String.h
 */

#ifndef AMB_STRING_H_
#define AMB_STRING_H_

#include <string>

namespace amb {

class String : public std::basic_string<char>
{
public:
   String() = default;
   String(const std::string& copy) : std::string(copy) {}
   virtual ~String() = default;

   int toInt() const { return std::stoi(*this); }
   long int toL() const { return std::stol(*this); }
   unsigned long toUl() const { return std::stoul(*this); }
   long long toLl() const { return std::stoll(*this); }
   unsigned long long toUll() const { return std::stoull(*this); }
   float toFloat() const { return std::stof(*this); }
   double toDouble() const { return std::stod(*this); }
   long double toLDouble() const { return std::stold(*this); }
};

} // End namespace amb

#endif // AMB_STRING_H_
