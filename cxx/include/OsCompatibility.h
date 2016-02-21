/**
 * A Compatibility header
 */
#ifndef AMB_OSCOMPATIBILITY_
#define AMB_OSCOMPATIBILITY_

#include <bitset>

#ifdef WIN32
#define dllExport __declspec(dllexport)
#define dllImport __declspec(dllimport)
#else
#define dllExport
#define dllImport
#endif

using uchar = unsigned char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;
using ullong = unsigned long long;

#define logInt(var) \
  std::cout << #var" = " << (int)var << std::endl;

#define logBin(var) \
  std::bitset<sizeof(var) * 8> var##bin(var); \
  std::cout << #var" = " << var##bin << std::endl

#endif  // AMB_OSCOMPATIBILITY_
