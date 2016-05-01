/**
 * BitOps/MsgData.h
 */

#ifndef BITOPS_MSGDATA_H_
#define BITOPS_MSGDATA_H_

#include <include/OsCompatibility.h>

namespace BitOps {

template <std::uint32_t N>
class MsgData {
 public:
  enum { SIZE = N };
  std::uint8_t data[SIZE];
};

}  // End namespace BitOps

#endif  // BITOPS_MSGDATA_H_
