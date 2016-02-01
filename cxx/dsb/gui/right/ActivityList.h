/**
 * dsb/gui/right/ActivityList.h
 */

#ifndef DSB_GUI_RIGHT_ACTIVITYLIST_H_
#define DSB_GUI_RIGHT_ACTIVITYLIST_H_

#include <vector>
#include <amb/GuiComponent.h>
#include <dsb/generic/ProjectFile.h>
#include <dsb/interface/ActivityMsg.h>

namespace dsb {
namespace gui {
namespace right {

class ActivityList : public amb::GuiComponent {
 public:
  using Ptr = std::shared_ptr<ActivityList>;

  ActivityList() = default;
  virtual ~ActivityList() = default;

  void append(const ActivityMsg& msg);
  void loadProjectFile(ProjectFile& pf);
  void saveProjectToFile(std::string filename);
  void updateProjectData();

 private:
  ProjectFile _proj;
  std::vector<ActivityMsg> _activities;
};

}  // End namespace right
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_RIGHT_ACTIVITYLIST_H_
