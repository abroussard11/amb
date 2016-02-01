/**
 * dsb/gui/right/ActivityList.cpp
 */
#include <dsb/gui/right/ActivityList.h>

#include <fstream>
#include <iostream>
#include <amb/Color.h>
#include <amb/Font.h>
#include <amb/Text.h>
#include <dsb/gui/right/ProjectItem.h>

namespace dsb {
namespace gui {
namespace right {

void ActivityList::append(const ActivityMsg& msg) {
  if (_proj.isUnique(msg)) {
    std::cout << "Adding msg = " << msg.name << std::endl;

    _proj.appendActivity(msg);
    addComponent<right::ProjectItem>(msg);

    auto& comp = _components.back();
    auto i = _components.size();
    comp->move(0.F, ((i - 1) * 31.F));
  }
}

void ActivityList::loadProjectFile(ProjectFile& pf) {
  _proj = pf;

  _components.clear();
  _components.reserve(_proj.activities.size());
  for (auto& act : _proj.activities) {
    addComponent<right::ProjectItem>(act);
    auto& comp = _components.back();
    auto i = _components.size();
    comp->move(0.F, ((i - 1) * 31.F));
  }
}

void ActivityList::saveProjectToFile(std::string filename) {
  std::ofstream os(filename);
  if (os.is_open()) {
    // update project data
    updateProjectData();

    // save project data to file
    _proj.serialize(os);
  } else {
    std::cout << "Couldn't write to the file: " << filename << std::endl;
  }
}

void ActivityList::updateProjectData() {
  ProjectFile proj;

  for (auto& comp : _components) {
    auto item = dynamic_cast<ProjectItem*>(comp.get());
    proj.appendActivity(item->toActivityMsg());
  }

  _proj = proj;
}

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb
