/**
 * dsb/Repository.cpp
 */

#include <dsb/generic/Repository.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <Util/fs.h>

namespace dsb {

Repository::Repository()
    : HEAD(".dsb/HEAD"),  //
      _isValid(false),    //
      _headProjName(":") {
  // Repo File structure:
  // KEYWORD = [list of names]
  //
  // The list of names can span multiple lines
  // by escaping the newline character

  // parse the repo - build internal data
  std::ifstream repoIfs(HEAD, std::ifstream::in);
  if (repoIfs.is_open() == false) {
    _isValid = false;
    return;
  }

  std::getline(repoIfs, _headProjName);
  _isValid = true;
}

bool Repository::isValid() { return _isValid; }

void Repository::initialize() {
  // TODO: check if repo already exists
  Util::mkdir(".dsb");
  std::ofstream ofs(".dsb/HEAD", std::ofstream::out);
  ofs << "HEAD = NULL" << std::endl;
  ofs.close();
}

void Repository::setHead(std::string headName) {
  std::ofstream ofs(HEAD, std::ofstream::out);
  ofs << headName << std::endl;
}

std::string Repository::getHead() {
  std::ifstream ifs(HEAD, std::ofstream::in);
  std::string headProj;
  std::getline(ifs, headProj);
  return headProj;
}

}  // End namespace dsb
