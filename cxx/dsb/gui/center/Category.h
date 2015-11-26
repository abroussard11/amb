/**
 * dsb/gui/center/Category.h
 */

#ifndef DSB_GUI_CENTER_CATEGORYLIST_H_
#define DSB_GUI_CENTER_CATEGORYLIST_H_

#include <amb/GuiComponent.h>
#include <amb/xml/Node.h>

namespace dsb {
namespace gui {
namespace center {

class Category : public amb::GuiComponent
{
public:
   using Ptr = std::unique_ptr<Category>;

   Category(amb::xml::Node& group);
   virtual ~Category() = default;
};

} // End namespace center
} // End namespace gui
} // End namespace dsb

#endif // DSB_GUI_CENTER_CATEGORYLIST_H_
