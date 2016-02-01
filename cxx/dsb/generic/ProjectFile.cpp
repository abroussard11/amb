/**
 * dsb/ProjectFile.cpp
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <dsb/generic/ProjectFile.h>

namespace dsb {

bool ProjectFile::operator==(ProjectFile& other) {
  if (activities.size() != other.activities.size()) return false;

  auto b = activities.begin();
  auto e = activities.end();
  auto ob = other.activities.begin();
  auto oe = other.activities.end();

  return std::equal(b, e, ob, oe);
}

bool ProjectFile::isUnique(const ActivityMsg& act) {
  std::cout << "contains: " << act.name << std::endl;

  auto b = activities.begin();
  auto e = activities.end();
  auto loc = std::find(b, e, act);

  std::cout << "loc == end = " << std::boolalpha << (loc == e) << std::endl;

  return loc == e;
}

void ProjectFile::appendActivity(const ActivityMsg& act) {
  activities.push_back(act);
}

void ProjectFile::serialize(std::ofstream& ofs) {
  for (auto& act : activities) {
    ofs << act.name << ";" << act.desc << ";" << act.LU << ";" << act.UC << ";"
        << act.QU << ";" << act.total << std::endl;
  }
}

void ProjectFile::deserialize(std::ifstream& ifs) {
  activities.clear();

  std::string line;
  while (std::getline(ifs, line)) {
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> vec;
    vec.reserve(4);
    while (std::getline(ss, item, ';')) {
      vec.push_back(item);
    }
    std::cout << "vec.size = " << vec.size() << std::endl;
    if (vec.size() == 6) {
      auto act = ActivityMsg();
      act.name = vec.at(0);
      act.desc = vec.at(1);
      act.LU = vec.at(2);
      act.UC = vec.at(3);
      act.QU = vec.at(4);
      act.total = vec.at(5);
      activities.push_back(act);
    }
  }
}

std::ostream& operator<<(std::ostream& os, const dsb::ProjectFile& pf) {
  os << pf.name;
  return os;
}

}  // End namespace dsb
