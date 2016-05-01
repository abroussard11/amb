/**
 * A Compatibility header
 */
#ifndef AMB_OSCOMPATIBILITY_
#define AMB_OSCOMPATIBILITY_

#include <cstdint>
#include <bitset>

#ifdef WIN32
#define dllExport __declspec(dllexport)
#define dllImport __declspec(dllimport)
#else
#define dllExport
#define dllImport
#endif

#define logInt(var) \
  std::cout << #var" = " << (int)var << std::endl;

#define logBin(var)                              \
  {                                              \
    std::bitset<sizeof(var) * 8> var##bin(var);  \
    std::string var##str = var##bin.to_string(); \
    for (uint i = 0; i < var##str.size(); i++) { \
      std::cout << var##str.at(i);               \
      if ((i % 8) == 7) {                        \
        std::cout << ' ';                        \
      }                                          \
    }                                            \
    std::cout << std::endl;                      \
  }

#endif  // AMB_OSCOMPATIBILITY_
