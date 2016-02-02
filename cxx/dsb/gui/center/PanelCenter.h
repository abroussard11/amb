/**
 * dsb/gui/center/PanelCenter.h
 */

#ifndef DSB_GUI_CENTER_PANELCENTER_H_
#define DSB_GUI_CENTER_PANELCENTER_H_

#include <map>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <amb/GuiComponent.h>
#include <amb/Xml.h>
#include <dsb/interface/ButtonMsg.h>
#include <dsb/gui/center/Category.h>
#include <infra/Inbox.h>

namespace dsb {
namespace gui {
namespace center {

class PanelCenter : public amb::GuiComponent {
 public:
  PanelCenter() = delete;
  PanelCenter(sf::VideoMode& mode);
  virtual ~PanelCenter() = default;

  virtual void processEvent(sf::Event& event) override;

 protected:
  void onButtonMsg(infra::Msg<ButtonMsg>& x);

  // Event handlers
  void onMouseWheelMoved(sf::Event& event) override;

 private:
  sf::RectangleShape _rect;
  std::shared_ptr<infra::Inbox<ButtonMsg>> _inbox;
  std::map<std::string, Category*> _categories;
  Category* _category;
  amb::Xml _xmlTopDb;

  void updateSelf() override;
  void drawSelf(sf::RenderTarget& target,
                        sf::RenderStates states) const override;
  bool isClickOnSelf(sf::Event& event);
};

}  // End namespace center
}  // End namespace gui
}  // End namespace dsb

#endif  // DSB_GUI_CENTER_PANELCENTER_H_
