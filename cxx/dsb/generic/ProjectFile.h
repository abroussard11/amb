/**
 * dsb/generic/ProjectFile.h
 */

#ifndef DSB_GENERIC_PROJECTFILE_H_
#define DSB_GENERIC_PROJECTFILE_H_

// #include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <dsb/interface/ActivityMsg.h>
#include <dsb/generic/Repository.h>

namespace dsb {

class ProjectFile {
 public:
  std::string name;
  std::vector<ActivityMsg> activities;

  ProjectFile() = default;
  virtual ~ProjectFile() = default;

  bool operator==(ProjectFile& other);

  bool isUnique(const ActivityMsg& act);
  void appendActivity(const ActivityMsg& act);

  // write to file
  void serialize(std::ofstream& os);

  // read from file
  void deserialize(std::ifstream& is);
};

std::ostream& operator<<(std::ostream& os, const dsb::ProjectFile& pf);

}  // End namespace dsb

#endif  // DSB_GENERIC_PROJECTFILE_H_
