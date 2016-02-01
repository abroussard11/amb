/**
 * dsb/ActivityMsg.h
 */

#ifndef DSB_ACTIVITYMSG_H_
#define DSB_ACTIVITYMSG_H_

#include <string>

namespace dsb {

class ActivityMsg {
 public:
  ActivityMsg() = default;
  virtual ~ActivityMsg() = default;

  bool operator==(const ActivityMsg& other) {
    return (name == other.name && desc == other.desc && LU == other.LU &&
            UC == other.UC && QU == other.QU && total == other.total);
  }

  std::string toString() const {
    return name + " " + desc + " " + LU + " " + UC + " " + QU + " " + total;
  }

  std::string name;
  std::string desc;
  std::string LU;
  std::string UC;
  std::string QU;
  std::string total;
};

}  // End namespace dsb

#endif  // DSB_ACTIVITYMSG_H_
