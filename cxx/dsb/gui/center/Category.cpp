/**
 * dsb/gui/center/Category.cpp
 */

#include <iostream>
#include <dsb/gui/center/Category.h>
#include <dsb/gui/center/Activity.h>

namespace dsb {
namespace gui {
namespace center {

Category::Category(amb::xml::Node& group) : GuiComponent() {
  auto activities = group.getElements("//activity");
  for (auto& activity : activities) {
    auto i = _components.size();
    auto pos = sf::Vector2f(0, (20.F * i));
    addComponent<Activity>(activity);
    _components.back()->move(pos);
  }
}

}  // End namespace center
}  // End namespace gui
}  // End namespace dsb
