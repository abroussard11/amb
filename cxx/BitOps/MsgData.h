/**
 * BitOps/MsgData.h
 */

#ifndef BITOPS_MSGDATA_H_
#define BITOPS_MSGDATA_H_

#include <include/OsCompatibility.h>

namespace BitOps {

template <uint N>
class MsgData {
 public:
  enum { SIZE = N };
  uchar data[SIZE];
};

}  // End namespace BitOps

#endif  // BITOPS_MSGDATA_H_
